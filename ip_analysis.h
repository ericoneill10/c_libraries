#ifndef _IP_ANALYSIS_H_
#define _IP_ANALYSIS_H_

#include <stdbool.h>
#include <stdint.h>

#define HEADER_LENGTH 20
#define SOURCE_ADDRESS_OFFSET 16


bool is_local_address(uint8_t *ipv4_header, uint32_t address, uint32_t subnet);


#endif
