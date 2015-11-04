#include "Socket.h"
#include <iostream>
#include <unistd.h>

using namespace std;

Socket::Socket(){
	sd=socket(AF_INET,  SOCK_STREAM,0);
	if(sd==-1){
		cout<<"Error al crear el descriptor"<<endl;	
	}else{
		cout<<"Descriptor creado exitosamente"<<endl;	
	}
}
Socket::Socket(char type, bool t1){
	sd=socket(AF_INET,  SOCK_STREAM,0);
	if(sd==-1){
		cout<<"Error al crear el descriptor"<<endl;	
	}else{
		cout<<"Descriptor creado exitosamente"<<endl;	
	}
}

Socket::~Socket(){
	int cl= close(sd);
	if(cl==0){
		cout<<"Descriptor cerrado exitosamente"<<endl;
	}else{
		cout<<"Error al cerrar el descriptor"<<endl;
	}
}
int Socket::Connect(char * Host, int Port){
	struct sockaddr_in host_addr;
	host_addr.sin_family = AF_INET;
	inet_aton( Host,  &host_addr.sin_addr );
	host_addr.sin_port = htons( Port );
	int len = sizeof( host_addr );

	int cn= connect(sd, (sockaddr *) & host_addr, len);
	if(cn==-1){
		cout<<"Error al crear la conexion"<<endl;	
	}else{
		cout<<"Conexion creada exitosamente"<<endl;	
	}
return cn;
}
int Socket::Read(char * text, int len){
	 int r=read( sd, text, len);
	
	if(r==-1){
		cout<<"Error al leer del archivo"<<endl;	
	}else{
		cout<<"Lectura realizada exitosamente"<<endl;	
	}
}
int Socket::Write(char * text, int len){

	int w = write(sd, text, len);

	 if(w==-1){
		cout<<"Error al escribir al archivo"<<endl;	
	}else{
		cout<<"Escritura realizada exitosamente"<<endl;	
	}
}
int Socket::Listen(int queue){
//queue--> maximo de conexiones pendientes
//marca el socket (sd) como pasivo, que se puede usar para aceptar conexiones entrantes
	int lt=listen(sd, queue);
	if(lt==-1){
		cout<<"Error en el listen"<<endl;	
	}else{
		cout<<"Listen realizado exitosamente"<<endl;	
	}
}
int Socket::Bind(int Port){
//bind() assigns the address specified by addr to the socket  referred  to by  the  file  descriptor sd.
//addrlen specifies the size, in bytes, of the address structure pointed to by addr
	 
       struct sockaddr_in server_addr;
       server_addr.sin_family = AF_INET;
       server_addr.sin_addr.s_addr = htonl( INADDR_ANY );
       server_addr.sin_port = htons( Port );
       socklen_t len = sizeof( server_addr );
       int b=bind( sd, (const sockaddr *) & server_addr, len );

	if(b==-1){
		cout<<"Error en el Bind"<<endl;	
	}else{
		cout<<"Bind realizado exitosamente"<<endl;	
	}
}
Socket* Socket::Accept(){
     	struct sockaddr_in client;
	socklen_t len=sizeof (sockaddr_in); 
	int a= accept(sd, (struct sockaddr *)& client, &len);
	if(a==-1){
		cout<<"Error en el accept"<<endl;	
	}else{
		cout<<"Accept realizado exitosamente"<<endl;	
	nuevo->sd = a;
        }
return nuevo;
}
int Socket::Shutdown( int r ){
	shutdown(sd,r);
}
