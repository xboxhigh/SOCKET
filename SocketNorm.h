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
	void Init();
	
	struct sockaddr_in adr;
public:
	SOCK();
	~SOCK()	{}
	
	void SetAdr(struct sockaddr_in _src)	{adr = _src;}
	struct sockaddr_in GetAdr()	{return adr;}
	
	int Accept(int _iSocket);
	int Connect(int _iSocket);
	void SendMessage(SockInfo &_sock, string _service);
	void RecvMessage(SockInfo &_sock, string _service);
};

class TCP_Client : SOCK	{
private:
	int sockfd;
    string address;
    int port;
    struct sockaddr_in dest;
	
public:

};

class TCP_Server : SOCK	{
private:
	int sockfd;
	int port;
    struct sockaddr_in dest;
public:

};

#endif