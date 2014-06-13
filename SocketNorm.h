#ifndef SOCKETNORM_H 
#define SOCKETNORM_H  

#include<iostream>    //cout
#include<string.h>    //strlen
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr
#include<netdb.h> //hostent
#include <netinet/in.h>		//for struct sockaddr_in

using namespace std;


class SOCK	{
private:
	char* msgBuff;	
	struct sockaddr_in adr;

	void Init();
public:
	SOCK();
	~SOCK()	{}
	
	void SetAdr(struct sockaddr_in _src)	{adr = _src;}
	struct sockaddr_in GetAdr()	{return adr;}
	void SetMsgBuff(char* _msg)	{msgBuff = _msg;}
	string GetMsgBuff()	{return msgBuff;}
	
	int Accept(int _iSocket);
	int Connect(int _iSocket, struct sockaddr_in _dest);
	void SendMessage(int iSocket, char *_msg);
	int RecvMessage(int iSocket, char *_msg);
};

/// TCP Client Class ///
class TCP_Client : public SOCK	{
private:
	int sockfd;
    string address;
    int port;
    struct sockaddr_in dest;
	
	void Init(string _addr, int _port);
public:
	TCP_Client(string _addr, int _port);
	~TCP_Client()	{}
	
	void TCPClientSocket();
	int GetSockfd()	{return sockfd;}
	struct sockaddr_in GetSock()	{return dest;}
};

/// TCP Server Class ///
class TCP_Server : public SOCK	{
private:
	int sockfd;
	int clientfd;
	int port;
    struct sockaddr_in dest;
	
	void Init(int _port);
public:
	TCP_Server(int _port);
	~TCP_Server()	{}
	
	void TCPServerSocket();
	int GetSockfd()	{return sockfd;}
	int GetClientfd()	{return clientfd;}
	void SetClientfd(int _iSocket)	{clientfd = _iSocket;}
	struct sockaddr_in GetSock()	{return dest;}
};

#endif