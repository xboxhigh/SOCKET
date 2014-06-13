#include "SocketNorm.h"

SOCK::SOCK()	{	Init();}

void SOCK::Init()	{
	
}

int SOCK::Accept(int _iSocket)	{
	struct sockaddr addr;
	socklen_t  alen;        
    alen = sizeof(addr);
	
	return accept(_iSocket, (struct sockaddr *)&addr, &alen);	
}

int SOCK::Connect(int _iSocket, struct sockaddr_in _dest)	{	
	//--Connecting to server--//
	return connect(_iSocket, (struct sockaddr*)&_dest, sizeof(_dest));	
}

void SOCK::SendMessage(int _iSocket, char *_msg)	{
	send(_iSocket, _msg, sizeof(_msg), 0);		
}

int SOCK::RecvMessage(int _iSocket, char *_msg)	{
	return recv(_iSocket, _msg, sizeof(_msg), 0);
}


/// TCP Client Socket ///

TCP_Client::TCP_Client(string _addr, int _port)	{	Init(_addr, _port);}

void TCP_Client::Init(string _addr, int _port)	{
	sockfd = 0;
    address = _addr;
    port = _port;	
}

void TCP_Client::TCPClientSocket()
{	
	//--Create Socket--//
	sockfd = socket(PF_INET, SOCK_STREAM, 0);

	//--Initailize structure Destination--//
	bzero(&dest, sizeof(dest));
	dest.sin_family = AF_INET;
	dest.sin_port = htons(port);

	//--This line is different from server--//
	dest.sin_addr.s_addr = inet_addr(address.c_str());
	
	
}


/// TCP Server Socket ///

TCP_Server::TCP_Server(int _port)	{	Init(_port);}

void TCP_Server::Init(int _port)	{
	sockfd = 0;
    port = _port;
}

void TCP_Server::TCPServerSocket()
{
	//struct sockaddr_in dest;
	
	//--Create Socket--//
	sockfd = socket(PF_INET, SOCK_STREAM, 0);
	
	//--Initailize structure Destination--//
	bzero(&dest, sizeof(dest));
	dest.sin_family = AF_INET;
	dest.sin_port = htons(port);

	//--This line is different from client--//
	dest.sin_addr.s_addr = INADDR_ANY;
	
	//--Assign a port number to socket--//
	bind(sockfd, (struct sockaddr*)&dest, sizeof(dest));
	
	//--Make it listen to socket with max 20 connections--//
	listen(sockfd, 20);
	
}