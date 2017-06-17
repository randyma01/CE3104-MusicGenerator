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
        correct = false;
        return message;
    }
    else if (connect(sockClient, (sockaddr*)&serverAddress, sizeof(serverAddress)) ){
        message = "<font color = \"red\"> >> [Error 0x02] Bluetooth Server not available #Error: ";
        message.append(to_string(WSAGetLastError()));
        message.append("\n");
        message.append("</font>");
        closesocket(sockClient);
        correct = false;
        return   message;

    }else{
        message = ">> Socket Bluetooth Created\n>> Socket Bluetooth Created\n"
                  ">> Connecting....\n>> Connected to: HC-05 {98:D3:32:20:A9:62}\n"
                                                           ">> Sending to MusicGenerator-Hardware\n";
        correct = true;
        return message;
    }
}

void Client::sendMS(string message){

    size_t pos = 0;

    string action;
    string delimiter = "|";
    //const char *buffer;

    /*
    while ((pos = message.find(delimiter)) != std::string::npos) {
        action = message.substr(0, pos);

        const char *buffer = new char[action.length()];
        buffer = action.c_str() + '|';
        send(sockClient, buffer, (action.length() + 1), 0);
        sleep(1);
        qInfo() << buffer;
        message.erase(0, pos + delimiter.length());
    }
    qInfo() <<"final " << message.c_str();
    const char *buffer = new char[message.length()];
    buffer = message.c_str() + '|';
    send(sockClient, buffer, (message.length() + 1), 0);
    */


    int lengthMSG = message.length();
    const char *buffer = new char[lengthMSG];
    buffer = message.c_str();

    qInfo() << "largo texto: " << lengthMSG;

    int s = send(sockClient, buffer, lengthMSG+1, 0);

    qInfo() << s ;

    /*char buffer[5086] = {0};
    memset(buffer, 0, sizeof(buffer));
    int r = 0;
    r = recv(sockClient, (char*)buffer, sizeof(buffer), 0);
    qInfo() << "Result: " << buffer;
    */
}






