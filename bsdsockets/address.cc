
#include "address.h"

Address::Address(){
	this->address = (127 << 24) | 1;
	this->port = 25565;	
}

Address::Address( unsigned char a, 
 				  unsigned char b,
 				  unsigned char c,
 				  unsigned char d,
 				  uint16_t port ){
	this->address = ( a << 24 ) | 
				    ( b << 16 ) | 
				    ( c << 8  ) | 
				 	 d;
	this->port = port;
}

Address::Address( uint64_t address, uint16_t port ){
	this->address = address;	
	this->port = port;	
}

uint64_t Address::GetAddress() const{
	return address;
}

unsigned char Address::GetA() const{
	return address >> 24;	
}

unsigned char Address::GetB() const{
	return (address << 8) >> 24;
}

unsigned char Address::GetC() const{
	return (address << 16) >> 24;
}

unsigned char Address::GetD() const{
	return (address << 24) >> 24;
}

uint16_t Address::GetPort() const{
	return port;
}
