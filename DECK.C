#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graph.h>
#include <string.h>

/*ASCII colors*/
#define WHITE 7
#define BRIGHT_WHITE 15
#define RED 4

/*card suites*/
#define HEARTS   0
#define DIAMONDS 1
#define CLUBS    2
#define SPADES   3

#define DECK_SIZE 52

typedef struct {
    int value;
    int suit;
} card_t;

int is_black(int suit) {
    /*
    hearts   0 00
    diamonds 1 01
    clubs    2 10
    spades   3 11
    */

    /* bitwise and */
    return (suit & 2);
}

/* returns the chard value, needed to diplay 10 */
/* function is unused*/
int get_card_value(int i) {

    int value;

    switch(i) {
	case 0:
	    value = 'A';
	    break;
	case 1:
	    value = 2;
	    break;
	case 2:
	    value = 3;
	    break;
	case 3:
	    value = 4;
	    break;
	case 4:
	    value = 5;
	    break;
	case 5:
	    value = 6;
	    break;
	case 6:
	    value = 7;
	    break;
	case 7:
	    value = 8;
	    break;
	case 8:
	    value = 9;
	    break;
	case 9:
	    value = 10;
	    break;
	case 10:
	    value = 'J';
	    break;
	case 11:
	    value = 'Q';
	    break;
	case 12:
	    value = 'K';
	    break;
	default: /*this should never happen*/
	    value = -1; 
    }

    return value;
} 

/*returns a string representing the card value*/
char* get_card_value_str(int i, char* tmpstr) {

    //char tmpstr[2];

    switch(i) {
	case 0:
	    tmpstr = "A";
	    break;
	case 1:
	    tmpstr = "2";
	    break;
	case 2:
	    tmpstr = "3";
	    break;
	case 3:
	    tmpstr = "4";
	    break;
	case 4:
	    tmpstr = "5";
	    break;
	case 5:
	    tmpstr = "6";
	    break;
	case 6:
	    tmpstr = "7";
	    break;
	case 7:
	    tmpstr = "8";
	    break;
	case 8:
	    tmpstr = "9";
	    break;
	case 9:
	    tmpstr = "10";
	    break;
	case 10:
	    tmpstr = "J";
	    break;
	case 11:
	    tmpstr = "Q";
	    break;
	case 12:
	    tmpstr = "K";
	    break;
	default: /*this should never happen*/
	    tmpstr = "XX"; 
    }

    return tmpstr;
} 


/*todo: if value is only 1 char then add space for aligment*/
void print_deck(card_t *deck) {
    //old method: using X to represent 10 card
    //char cards[] = "A23456789XJQK";

    char tmpstr[2];
    char* valuestr;
    char toprint[3];
    int index;

    for (index = 0; index < DECK_SIZE; index++) {
	if(is_black(deck[index].suit)) {
	    _settextcolor(WHITE); /*white*/
	}
	else {
	    _settextcolor(RED); /*red*/
	}

	//old method: using X to represent 10 card
	//sprintf(tmpstr, "%c%c ", cards[ deck[index].value ], deck[index].suit + 3);

	/*
	  - using length of the returned string value to determine spacing
	  - + 3 is in reference to the ascii table
	  - I am sure there is a better way of doing this
	*/
	valuestr = get_card_value_str(deck[index].value, tmpstr); 
	if(strlen(valuestr) == 2) {
	    sprintf(toprint, "%s%c ", valuestr, deck[index].suit +3);
	}
	else { /*add two spaces inbetween*/
	    sprintf(toprint, "%s%c  ", valuestr, deck[index].suit +3);
	}
	//old method: no additional spacing
	//sprintf(toprint, "%s%c ",get_card_value_str(deck[index].value,tmpstr), deck[index].suit +3);

	/* print in max 13 columns for readability*/
	if(index == 13 || index == 26 || index == 39) {
	    _outtext("\n");
	}

	_outtext(toprint);
    }
}

void shuffle_card(card_t *deck, int i, int j) {
    card_t tmp;

    tmp = deck[i];
    deck[i] = deck[j];
    deck[j] = tmp;
}

void shuffle_deck(card_t *deck) {

    int index, rand_index;

    for (index = 0; index < DECK_SIZE; index++) {
	rand_index = (int) rand() % DECK_SIZE;
	shuffle_card(deck, index, rand_index);
    }
}

int main() {

    /*create the array of cards*/
    card_t deck[DECK_SIZE];

    /* build the deck */
    int index = 0;
    int v, s;

    //4 suits represented by 0-3
    //13 cards in each suit represented by 0-12
    for(s = 0; s < 4; s++) {
	for (v = 0; v < 13;v++) {
	    deck[index].value = v;
	    deck[index].suit = s;
	    index++;
	}
    }
    /*print the deck*/
    _settextcolor(BRIGHT_WHITE); /*br white*/
    _outtext("\nBefore Shuffle:\n");
    print_deck(deck);

    /* shuffle and print the deck */
    /* set a random seed value using the system clock*/
    srand(time(NULL));
    shuffle_deck(deck);

    _settextcolor(BRIGHT_WHITE); /*br white*/
    _outtext("\n\nAfter Shuffle:\n");
    print_deck(deck);

    /*reset the DOS color back to white and exit*/
    _settextcolor(WHITE); /*white*/
    _outtext("\n\n");

    return 1;
}

