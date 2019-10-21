#include "ip_analysis.h"

bool is_local_address(uint8_t *ipv4_header, uint32_t address, uint32_t subnet)
{
	int i;
	uint16_t word;
	uint32_t checksum_total = 0;
	uint16_t final_checksum;

	uint32_t source_addr;
	//1. Check checksum

	// add all 2 byte words in header
	for (i = 0; i < HEADER_LENGTH; i+=2)
	{
		word = (((uint16_t) *(ipv4_header + i)) << 8) + ((uint16_t) *(ipv4_header + i + 1));
		checksum_total += word;
	}

	checksum_total = (checksum_total & 0xFFFF) + (checksum_total >> 16); // add 16-bit carry over to total
	checksum_total = ~checksum_total; //ones compliment
	final_checksum = checksum_total; //put result into 16 bit int to truncate 
	printf("checksum total is: %x\n", final_checksum);

	//2. Check address
	//Bytes 16-19
	source_addr = (((uint32_t) *(ipv4_header+ SOURCE_ADDRESS_OFFSET)) << 24) +
		(((uint32_t) *(ipv4_header + SOURCE_ADDRESS_OFFSET + 1)) << 16) +
		(((uint32_t) *(ipv4_header + SOURCE_ADDRESS_OFFSET + 2)) << 8) +
		((uint32_t) *(ipv4_header + SOURCE_ADDRESS_OFFSET + 3));

	printf("the source addr is: %x\n", source_addr);

	return (source_addr == (address & subnet)) && (final_checksum == 0);
}
