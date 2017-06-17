#include "connection.h"

bool Connection::g_isInitFCP = false;



Connection::Connection(){
    SOCKET s = socket(AF_BTH, SOCK_STREAM, BTHPROTO_RFCOMM);

    const DWORD lastError = ::GetLastError();


    if(s == INVALID_SOCKET){
       // printf("Failed to get bluetooth socket! &d\n", lastError);
        qInfo() << "(Error Socket.......)";
        qInfo() << lastError;
    }

    WSAPROTOCOL_INFO protocolInfo;
    int protocolInfoSize = sizeof(protocolInfo);

    if (getsockopt(s, SOL_SOCKET, SO_PROTOCOL_INFO, (char*)&protocolInfo, &protocolInfoSize) != 0){
        qInfo() << "return prueba";
    }

    serverSocket = s;

    _isValidSocket = true;

}


void Connection::starBT(){

}


void Connection::Bind(){
    SOCKADDR_BTH address;

    int length = sizeof(SOCKADDR_BTH);
    char buf[1024] = { 0 };
    DWORD buf_len = sizeof(buf);

    address.addressFamily = AF_BTH;
    address.btAddr = 0;
    //address.serviceClassId = GUID_MAX_POWER_SAVINGS; //error
    address.port = BT_PORT_ANY;

    sockaddr *pAddr =(sockaddr*)&address;


    if (bind(serverSocket, pAddr, sizeof(SOCKADDR_BTH)) != 0){
        //printf("%d\n", GetLastError());
        qInfo() << "Error Bind";
    }

    qInfo() << "\nBinding Successful.......\n";

   //int length = sizeof(SOCKADDR_BTH);
    getsockname(serverSocket, (sockaddr*)&address, &length);
    //wprintf(L"Local Bluetooth devide is %04x%08x \nServer channel = %d\n",
      //      GET_NAP(address.btAddr), GET_SAP(address.btAddr), address.port);

    //qInfo() << "Local Bluetooth device is: " << GET_NAP(address.btAddr) << GET_SAP(address.btAddr);

    WSAAddressToStringA((LPSOCKADDR)&address, (DWORD)length, NULL, buf, &buf_len);
    qInfo() << "Server Bluetooth device is: " << buf;
    qInfo() << "Server Porr = " << address.port;

    //qInfo() << "Other: "  << address.btAddr << address.port << address.addressFamily << address.serviceClassId;



}


void Connection::Listen(){
    if(listen(serverSocket, 2) != 0){
        //printf("%d\n",GetLastError());
        qInfo() << "Error Listen";
    }
}

void Connection::RegisterServiceB(){
    LPWSTR name;
    LPWSTR desp;
    GUID uuid;
    name = L"RFCOMM Server Demo Instance";
    desp = L"Pushing data to PC";
    uuid = OBEXObjectPushServiceClass_UUID;


    memset(&_service, 0, sizeof(_service));
    _service.dwSize = sizeof(_service);
    _service.lpszServiceInstanceName = name;
    _service.lpszComment = desp;

    GUID serviceID = uuid;

    _service.lpServiceClassId = &serviceID;
    _service.dwNumberOfCsAddrs = 1;
    _service.dwNameSpace = NS_BTH;



    SOCKADDR_BTH address;
    sockaddr *pAddr = (sockaddr*)&address;

    int length = sizeof(SOCKADDR_BTH);

    getsockname(serverSocket, pAddr, &length);


    CSADDR_INFO csAddr;
    memset(&csAddr, 0, sizeof(csAddr));
    csAddr.LocalAddr.iSockaddrLength = sizeof(SOCKADDR_BTH);
    csAddr.LocalAddr.lpSockaddr = pAddr;
    csAddr.iSocketType = SOCK_STREAM;
    csAddr.iProtocol = BTHPROTO_RFCOMM;
    _service.lpcsaBuffer = &csAddr;

    if (0 != WSASetService(&_service, RNRSERVICE_REGISTER, 0)){
        //printf("Service Registration failed.....");
        //printf("%d\n", GetLastError());
        qInfo() << "Service Registration failed.....";

    }else{
        qInfo() << "Service registration successful....";
    }
}


void Connection::Accept(){
   //qInfo() << "Before accept..........";

    SOCKADDR_BTH cl;

    int ilen = sizeof(cl);

    SOCKET s = accept(serverSocket, (sockaddr*)&cl, &ilen);

    char buf[1024] = { 0 };
    DWORD buf_len = sizeof(buf);

    if (s == INVALID_SOCKET){
        //wprintf(L"Socket bind, error %d\n", WSAGetLastError());

        qInfo() << "Socket bind, error: " << WSAGetLastError();
    }

    //wprintf(L"\nConnection came from %04x%08x to channel %d\n", GET_NAP(cl.btAddr), GET_SAP(cl.btAddr), cl.port);
    //wprintf(L"\nAfter Accept\n");

    //qInfo() << "Connection from: " << GET_NAP(cl.btAddr) << GET_SAP(cl.btAddr) << "to channel: " << cl.port;

    WSAAddressToStringA((LPSOCKADDR)&cl, (DWORD)ilen, NULL, buf, &buf_len);
    qInfo() << "connection from: " << buf;


    qInfo() << "Accept!!";



    if (_onConnectedHanlder != NULL){
        _onConnectedHanlder(s);
    }
}

void Connection::OnConnected(function<void (SOCKET)> handler){
    _onConnectedHanlder = handler;

}


bool Connection::InitializedForCurrentProcess(){
    if (g_isInitFCP){
        return true;
    }

    WORD WVersionR;

    WSADATA wsaData;
    int err;

    WVersionR = MAKEWORD(2, 2);

    err = WSAStartup(WVersionR, &wsaData);

    if (err != 0){
        qInfo() << "Error_ Failed WSAStartup()";
        return false;
    }

    if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2){
        qInfo() << "Could not find a usable version of Winsock.dll";
        return false;
    }else{
        qInfo() << "The Winsock 2.2 dll was found okay.";
    }

    g_isInitFCP = true;
    return true;

}

void Connection::UnInitialized(){
    WSACleanup();
}


bool Connection::IsValid(){
    return _isValidSocket;
}

Connection::~Connection(){
    if (0 != WSASetService(&_service, RNRSERVICE_DELETE, 0)){
        qInfo() << "Error al desconectar......";
    }
    closesocket(serverSocket);
}

