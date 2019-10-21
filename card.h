#ifndef _CARD_H_
#define _CARD_H_

#define NUM_SIMULATIONS 1000000

enum card_suit {
	hearts,
	diamonds,
	spades,
	clubs
};

enum card_value {
	king,
	ace
};

struct card {
	int suit;
	int value;
};

float simulate_draw();
float simulate_draw_known_suit(int known_suit); // known suit is value hearts,spades,diamonds,clubs (0,1,2,3)
void reset_cards(struct card * cards);

#endif //_CARD_H_
