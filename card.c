#include "card.h"
#include <memory.h>
#include <stdio.h>
#include <time.h>

float simulate_draw()
{
	int i;
	srand(time(NULL));

	struct card cards[8];
	int double_ace_count = 0;
	for (i = 0; i < NUM_SIMULATIONS; i++)
	{
		reset_cards(cards);
		int first_draw = rand() % 8;
		if (cards[first_draw].value == king)
		{
			continue; // we know we can't have 2 aces if the first is a king
		}
		else { // first card is an ace
			//swap first card to last position in array
			struct card temp_card = cards[first_draw];
			cards[first_draw] = cards[7];
			cards[7] = cards[first_draw];
			
			int second_draw = rand() % 7;
			if (cards[second_draw].value == ace)
			{
				double_ace_count++;
			}

		}
	}
	float probability = ((float)double_ace_count) / ((float)NUM_SIMULATIONS);

	printf("num iterations:%i\n", NUM_SIMULATIONS);
	printf("double ace count: %i\n", double_ace_count);
	printf("probability: %f\n", probability);
	return probability;

}

float simulate_draw_known_suit(int known_suit)
{
	int i;
	srand(time(NULL));

	struct card cards[8];
	
	int double_ace_count = 0;
	for (i = 0; i < NUM_SIMULATIONS; i++)
	{
		reset_cards(cards);
		int first_draw = rand() % 8;
		if (cards[first_draw].value == king)
		{
			continue; // we know we can't have 2 aces if the first is a king
		}
		else { // first card is an ace
			if (cards[first_draw].suit != known_suit) { //if our ace isn't the right suit, don't even need to draw we know the other card
				double_ace_count++;
				//continue;
			}

			//swap first card to last position in array
			else
			{
				struct card temp_card = cards[first_draw];
				cards[first_draw] = cards[7];
				cards[7] = cards[first_draw];

				int second_draw = rand() % 7;
				if (cards[second_draw].value == ace)
				{
					double_ace_count++;
				}
			}
		}
	}
	float probability = ((float)double_ace_count) / ((float)NUM_SIMULATIONS);

	printf("known suit num iterations:%i\n", NUM_SIMULATIONS);
	printf("known suit double ace count: %i\n", double_ace_count);
	printf("known suit probability: %f\n", probability);
	return probability;

}

void reset_cards(struct card * cards) {
	cards[0].value = king;
	cards[0].suit = hearts;
	cards[1].value = king;
	cards[1].suit = diamonds;
	cards[2].value = king;
	cards[2].suit = spades;
	cards[3].value = king;
	cards[3].suit = clubs;
	cards[4].value = ace;
	cards[4].suit = hearts;
	cards[5].value = ace;
	cards[5].suit = diamonds;
	cards[6].value = ace;
	cards[6].suit = spades;
	cards[7].value = ace;
	cards[7].suit = clubs;
}