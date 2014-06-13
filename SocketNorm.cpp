#include "SocketNorm.h"

SOCK::SOCK()	{
	Init();
}

void SOCK::Init()	{
	
}

int SOCK::Accept(int _iSocket)
{
	struct sockaddr adr;
	socklen_t  alen;        
    alen=sizeof(adr);
	
	return accept(iSocket, (struct sockaddr *)&adr, &alen);	
}

int SOCK::Connect(int _iSocket, )
{	
	//--Connecting to server--//
	return connect(_iSocket, (struct sockaddr*)&_sock.dest, sizeof(_sock.dest));	
}

void SOCK::SendMessage(SockInfo &_sock, string _service)
{
	struct sockaddr_in client_addr;
	
	if(_service == "Server")
		send(_sock.clientfd, _sock.sendBuff, sizeof(_sock.sendBuff), 0);
	else if(_service == "Client")
		send(_sock.sockfd, _sock.sendBuff, sizeof(_sock.sendBuff), 0);
		
}

void SOCK::RecvMessage(SockInfo &_sock, string _service)
{
	struct sockaddr_in client_addr;
	
	if(_service == "Server")
		_sock.byteRecv = recv(_sock.clientfd, _sock.recvBuff, sizeof(_sock.recvBuff), 0);
	else if(_service == "Client")
		_sock.byteRecv = recv(_sock.sockfd, _sock.recvBuff, sizeof(_sock.recvBuff), 0);
	
}

