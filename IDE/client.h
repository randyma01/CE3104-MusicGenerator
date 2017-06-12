#ifndef CLIENT_H
#define CLIENT_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <tchar.h>
#include <unistd.h>
#include <sdkddkver.h>
#include <initguid.h>
#include <winsock2.h>
#include <ws2bth.h>
#include <bluetoothapis.h>
#include <bthsdpdef.h>
#include <functional>
#include <string>
#include <vector>

#include <QtGui>



using namespace std;

///address bluetooth HC-05 "98:D3:32:20:A9:62"
/// uuid  HC-05  "00001101-0000-1000-8000-00805F9B34FB"

DEFINE_GUID(SERVER_UUID, 0x00001101, 0x0000, 0x1000, 0x80, \
0x00, 0x00, 0x80, 0x5f, 0x9b, 0x34, 0xfb);

DEFINE_GUID(GUID_NULL, 0x00000000, 0x0000, 0x0000, 0x00, \
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);



class Client{

public:
    Client();
    void sendMS(const char *ms);
    string startClient();

private:

    WSADATA wsaData = {0};
    WORD wVersionRequested = MAKEWORD(2, 2);
    ULONG iResult = 0;

    int port = 1;


    SOCKET sockClient = INVALID_SOCKET;
    SOCKADDR_BTH serverAddress;
    SOCKADDR_BTH clientAddress;


};

#endif // CLIENT_H
