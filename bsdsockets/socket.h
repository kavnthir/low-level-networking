
#include <stdint.h>
#include <unistd.h>
#include "address.h"

#define PLATFORM_WINDOWS  1
#define PLATFORM_MAC      2
#define PLATFORM_UNIX     3

#if defined(_WIN32)
	#define PLATFORM PLATFORM_WINDOWS
#elif defined(__APPLE__)
	#define PLATFORM PLATFORM_MAC
#else
	#define PLATFORM PLATFORM_UNIX
#endif

#if PLATFORM == PLATFORM_WINDOWS
	#include <winsock2.h>
#elif PLATFORM == PLATFORM_MAC || PLATFORM == PLATFORM_UNIX
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <fcntl.h>
#endif

#if PLATFORM == PLATFORM_WINDOWS
	#pragma comment( lib, "wsock32.lib" )
#endif

class Socket {
	public:
		Socket();

		~Socket();

		bool Open( uint16_t port );

		void Close();

		bool IsOpen() const;

		bool Send( const Address& destination,
				   const void* data,
				   uint64_t size);

		uint64_t Receive( Address& sender,
				     void* data,
					 uint64_t size);

	private:
		uint64_t handle;
};
