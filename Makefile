server : serverMain.cpp SocketNorm.cpp
	g++ serverMain.cpp SocketNorm.cpp -o server
client : clientMain.cpp SocketNorm.cpp
	g++ clientMain.cpp SocketNorm.cpp -o client
clean :
	rm -rf server client
 