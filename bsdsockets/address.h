
#include <stdint.h>

class Address {
	public:
		Address();

		Address( unsigned char a, 
				 unsigned char b,
				 unsigned char c,
				 unsigned char d,
				 uint16_t port );

		Address( uint64_t address,
				 uint16_t port );

		uint64_t GetAddress() const;

		unsigned char GetA() const;
		unsigned char GetB() const;
		unsigned char GetC() const;
		unsigned char GetD() const;

		uint16_t GetPort() const;

	private:

		uint64_t address;
		uint16_t port;
};
