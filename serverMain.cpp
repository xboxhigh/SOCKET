#include "SocketNorm.h"

int main(int argc,char **argv)	{
	
	TCP_Server server(3579);
	char* msg = new char[128];
	server.TCPServerSocket();
	
	while (true)	{
		
		
		server.SetClientfd(server.Accept(server.GetSockfd()));
		
		server.RecvMessage(server.GetClientfd(), msg);
		
		cout << msg << endl;
		
		if (strcmp(msg, "close") == 0)	{
			cout << "Close Connection ! "<< endl;
			break;
		}	
	}
	
	return 0;
}