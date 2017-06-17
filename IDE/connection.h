#ifndef CONNECTION_H
#define CONNECTION_H


#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <tchar.h>

#include <sdkddkver.h>

#include <initguid.h>
//#include <windows.h>


#include <winsock2.h>
#include <ws2bth.h>
#include <bluetoothapis.h>
#include <bthsdpdef.h>



#include <functional>


#include <string>
#include <vector>

#include <QtGui>

using namespace std;


class Connection{


public:
    Connection();
    ~Connection();

    void starBT();

    bool IsValid();

    void Bind();

    void Listen();

    void Accept();

    void RegisterServiceB();

    void OnConnected(function<void(SOCKET)> handler);

    static bool InitializedForCurrentProcess();
    static void UnInitialized();


    static bool g_isInitFCP;

    bool _isValidSocket = false;

    SOCKET serverSocket;
    SOCKADDR_BTH ServerAddress;

    function<void(SOCKET)> _onConnectedHanlder;

    WSAQUERYSET _service;

};

#endif // CONNECTION_H
