#include "client.h"



Client::Client(){
    if ((iResult = WSAStartup(wVersionRequested, &wsaData)) != 0){
        qInfo() << "Error initialize Winsock!!";
    }
    clientAddress.addressFamily = AF_BTH;
    clientAddress.port = port;
    clientAddress.btAddr = 0;
    clientAddress.serviceClassId = GUID_NULL;

    serverAddress.port = port;
    serverAddress.addressFamily = AF_BTH;
    serverAddress.btAddr = BTH_ADDR(0x98D33220A962);
    serverAddress.serviceClassId = SERVER_UUID;
}

string Client::startClient(){
    string message;


    sockClient = socket(AF_BTH, SOCK_STREAM, BTHPROTO_RFCOMM);

    if (sockClient == INVALID_SOCKET){
        //"<font color = \"red\"> Sample Text</font>"
        message = "<font color = \"red\"> >> [Error 0x01] - Socket creation! #Error: ";
        message.append(to_string(WSAGetLastError()));
        message.append("\n");
        message.append("</font>");
        return message;
    }
    else if (connect(sockClient, (sockaddr*)&serverAddress, sizeof(serverAddress)) ){
        message = "<font color = \"red\"> >> [Error 0x02] Bluetooth Server not available #Error: ";
        message.append(to_string(WSAGetLastError()));
        message.append("\n");
        message.append("</font>");
        closesocket(sockClient);
        return   message;

    }else{
        message = ">> Socket Bluetooth Created\n>> Socket Bluetooth Created\n"
                  ">> Connecting....\n>> Connected to: HC-05 {98:D3:32:20:A9:62}\n"
                                                           ">> Sending to MusicGenerator-Hardware\n";
        return message;
    }
}

void Client::sendMS(const char *ms){
    int lengthOfBytes = sizeof(ms);
    send(sockClient, ms, lengthOfBytes, 0);
    char buffer[1024] = {0};
    memset(buffer, 0, sizeof(buffer));
    int r = 0;
    r = recv(sockClient, (char*)buffer, sizeof(buffer), 0);
    qInfo() << "Result: " << buffer;
}






