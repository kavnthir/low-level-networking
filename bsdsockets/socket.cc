
#include "socket.h"

Socket::Socket(){
	#if PLATFORM == PLATFORM_WINDOWS
		WSADATA WsaData;
		WSAStartup( MAKEWORD(2,2), &WsaData );
	#endif

	this->handle = -1;
}

Socket::~Socket(){
	#if PLATFORM == PLATFORM_WINDOWS
		WSACleanup();
	#endif
}

bool Socket::Open( uint16_t port ){
    this->handle = socket( AF_INET, SOCK_DGRAM, IPPROTO_UDP );

    if ( handle <= 0 ) 
        return false;

	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(port);

	if ( bind( handle, (const sockaddr*) &addr, sizeof(sockaddr_in) ) < 0 ) 
        return false;

	return true;
}

void Socket::Close(){
	#if PLATFORM == PLATFORM_MAC || PLATFORM == PLATFORM_UNIX
		close( handle );
	#elif PLATFORM == PLATFORM_WINDOWS
		closesocket( handle );
	#endif
}

bool Socket::IsOpen() const{
	return handle > 0;
}

bool Socket::Send( const Address& destination, const void* data, uint64_t size){
	
	return true;
}

uint64_t Socket::Receive( Address& sender, void* data, uint64_t size){

	return 0;
}

