#include <stdio.h>
#include <time.h>
#include <memory.h>
#include <stddef.h>
#include <stdlib.h>

#include "card.h"
#include "primes.h" 
#include "ip_analysis.h"
#include "sorts.h"

int main(void)
{
	int sort_test_array[TEST_SIZE] = { 4,13,12,10,
							1,2,5,15,
							3,5,9,8,
							14,11,0,16 };
	print_list(sort_test_array, TEST_SIZE);
	merge_sort(sort_test_array, TEST_SIZE);
	print_list(sort_test_array, TEST_SIZE);

	scanf_s("a");
	//getch();
	exit(0);
}


void take_home_questions()
{
	/*  CARD QUESTION*/
	printf("Question 1: Simulate Card Draws\n\n");

	simulate_draw();
	simulate_draw_known_suit(hearts);

	printf("\n\n*****************************************\n\n");
	/* PRIMES QUESTION*/
	printf("Question 2: 10001st Prime\n\n");
	printf("is 2 prime: %i\n", is_prime(2));
	printf("is 3 prime: %i\n", is_prime(3));
	printf("is 4 prime: %i\n", is_prime(4));
	printf("is 5 prime: %i\n", is_prime(5));
	printf("is 5 prime: %i\n", is_prime(5));
	printf("is 15 prime: %i\n", is_prime(15));
	printf("is 17 prime: %i\n", is_prime(17));
	printf("is 17 prime: %i\n", is_prime(17));
	printf("is 369 prime: %i\n", is_prime(369));

	printf("the 1st prime is: %i\n", find_nth_prime(1));
	printf("the 2nd prime is: %i\n", find_nth_prime(2));
	printf("the 6th prime is: %i\n", find_nth_prime(6));
	printf("the 100th prime is: %i\n", find_nth_prime(100));
	printf("the 10001st prime is: %i\n", find_nth_prime(10001));

	printf("\n\n*****************************************\n\n");

	/* IP QUESTION*/

	printf("Question 3: IPv4 Check\n\n");

	uint8_t ipv4_header[HEADER_LENGTH] = { 0x45, 0x00, 0x00, 0x44, 0xAD, 0x0B, 0x00, 0x00, 0x40, 0x11, 0x72, 0x72, 0xac, 0x14, 0x02, 0xfd, 0xAC, 0x14, 0x00, 0x06 };
	uint8_t ipv4_header_bad_checksum[HEADER_LENGTH] = { 0x22, 0x00, 0x00, 0x44, 0xAD, 0x0B, 0x00, 0x00, 0x40, 0x11, 0x72, 0x72, 0xac, 0x14, 0x02, 0xfd, 0xAC, 0x14, 0x00, 0x06 };


	printf("adress is valid? %s\n", is_local_address(ipv4_header, 0xAC140006, 0xFFFFFFFF) ? "true" : "false");
	printf("adress is valid? %s\n", is_local_address(ipv4_header_bad_checksum, 0xAC140006, 0xFFFFFFFF) ? "true" : "false");
	printf("adress is valid? %s\n", is_local_address(ipv4_header, 0xAC140007, 0xFFFFFFFF) ? "true" : "false");

	printf("\n\n*****************************************\n\n");
}