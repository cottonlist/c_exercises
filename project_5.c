#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int rank;
	char *suit;
}card;

int main(int argc, char const *argv[])
{
	// card *card1 = (card *) malloc(sizeof(card));
	// card1->rank = 1;
	// printf("%d\n", card1->rank);

	card *cards[52];

	for (int i = 0; i < 13; ++i)
	{
		cards[i] = (card *) malloc(sizeof(card));
		cards[i]->rank = i + 1;
		cards[i]->suit = "spades";
	}

	for (int i = 13; i < 26; ++i)
	{
		cards[i] = (card *) malloc(sizeof(card));
		cards[i]->rank = i - 12;
		cards[i]->suit = "hearts";
	}

	for (int i = 26; i < 39; ++i)
	{
		cards[i] = (card *) malloc(sizeof(card));
		cards[i]->rank = i - 25;
		cards[i]->suit = "clubs";
	}

	for (int i = 39; i < 52; ++i)
	{
		cards[i] = (card *) malloc(sizeof(card));
		cards[i]->rank = i - 38;
		cards[i]->suit = "diamonds";
	}

	for (int i = 0; i < 5; ++i)
	{
		int index = rand() % 52 + 1;
		printf("%d, %s\n", cards[index]->rank, cards[index]->suit);
	}

	// free allocated memory addresses that have finished their jobs
	for (int i = 0; i < 52; ++i)
	{
		free(cards[i]);
	}

	return 0;
}