#include "SocketNorm.h"

int main(int argc,char **argv)	{

	TCP_Client client("127.0.0.1", 3579);
	char* msg = new char[128] ;
	
	strcpy(msg, "HELL Connect success!");
	
	client.TCPClientSocket();
	
	if (client.Connect(client.GetSockfd(), client.GetSock()) == 0)	{	//	Connect Success.
	
		cout << "Success" << endl;
		
		client.SendMessage(client.GetSockfd(), msg);
	
	}	else	{
	
		cout << "Failure" << endl;
	}
	
}


