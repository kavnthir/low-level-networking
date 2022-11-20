
#include<stdint.h>

class Socket {
	public:
		Socket();

		~Socket();

		bool Open( uint16_t port );

		void Close();

		bool IsOpen() const;

		bool Send( const Address& destination,
				   const void* data,
				   int size);

		int Receive( Address& sender,
				     void* data,
					 int size);

	private:
		int handle;
};
