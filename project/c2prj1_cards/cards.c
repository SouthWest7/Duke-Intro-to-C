#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
    assert(c.value >= 2 && c.value <= VALUE_ACE);
    assert(c.suit >= SPADES && c.suit <= CLUBS);
}

const char* ranking_to_string(hand_ranking_t r) {
    const char* s;
    switch (r)
    {
    case STRAIGHT_FLUSH:
        s = "STRAIGHT_FLUSH";
        break;
    case FOUR_OF_A_KIND:
        s = "FOUR_OF_A_KIND";
        break;
    case FULL_HOUSE:
        s = "FULL_HOUSE";
        break;
    case FLUSH:
        s = "FLUSH";
        break;
    case STRAIGHT:
        s = "STRAIGHT";
        break;
    case THREE_OF_A_KIND:
        s = "THREE_OF_A_KIND";
        break;
    case TWO_PAIR:
        s = "TWO_PAIR";
        break;
    case PAIR:
        s = "PAIR";
        break;
    default:
        s = "NOTHING";
        break;
    }
    return s;
}

char value_letter(card_t c) {
    char ch;
    switch (c.value)
    {
    case VALUE_ACE:
        ch = 'A';
        break;
    case VALUE_KING:
        ch = 'K';
        break;
    case VALUE_QUEEN:
        ch = 'Q';
        break;
    case VALUE_JACK:
        ch = 'J';
        break;
    case 10:
        ch = '0';
        break;
    default:
        ch = '0' + c.value;
        break;
    }
    return ch;
}


char suit_letter(card_t c) {
    char ch;
    switch (c.suit)
    {
    case SPADES:
        ch = 's';
        break;
    case HEARTS:
        ch = 'h';
        break;
    case DIAMONDS:
        ch = 'd';
        break;
    case CLUBS:
        ch = 'c';
        break;
    default:
        break;
    }
    return ch;
}

void print_card(card_t c) {
    printf("%c%c", value_letter(c), suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
    card_t temp;
    switch(value_let) {
        case 'A':
            temp.value = VALUE_ACE;
            break;
        case 'K':
            temp.value = VALUE_KING;
            break;
        case 'Q':
            temp.value = VALUE_QUEEN;
            break;
        case 'J':
            temp.value = VALUE_JACK;
            break;
        case '0':
            temp.value = 10;
            break;
        default:
            temp.value = value_let - '0';
            break;
        }
        switch(suit_let) {
        case 's':
            temp.suit = SPADES;
            break;
        case 'h':
            temp.suit = HEARTS;
            break;
        case 'd':
            temp.suit = DIAMONDS;
            break;
        case 'c':
            temp.suit = CLUBS;
            break;
    }
    assert_card_valid(temp);
    return temp;
}

card_t card_from_num(unsigned c) {
    assert(c >= 0 && c < 52);
    card_t temp;
    temp.value = c % 13 + 2;
    if (c < 13) {
        temp.suit = SPADES;
    } else if (c >= 13 && c < 26) {
        temp.suit = HEARTS;
    } else if (c >= 26 && c < 39) {
        temp.suit = DIAMONDS;
    } else {
        temp.suit = CLUBS;
    }
    assert_card_valid(temp);
    return temp;
}
