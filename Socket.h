
#include <sys/types.h>          
#include <sys/socket.h> //protocol families
#include <arpa/inet.h>
#include <errno.h>



 


class Socket {
public:
	Socket(char,bool=false);
	Socket();
	~Socket();
	int sd; //socket descriptor
	int Connect(char * Host, int Port);
	int Read(char * text, int len);
	int Write(char * text, int len);
	int Listen(int Queue);	
	int Bind(int Port);
	Socket * Accept();
	int Shutdown( int );
        Socket * nuevo;
};





