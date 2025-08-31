/**************************************************** 
 * flash_cards -- this is a class that defines
 * a deck of language flash cards
 *
 * Author: Lewis Gosewinckel
 *
 * Purpose: practicing classes in C++
 ****************************************************/ 

#include <iostream>
#include <string>

struct single_card {
	std::string question;	//English version of the word
	std::string answer;		//Other language version
};

class flash_cards {
	public:
		single_card top_card;	//card pulled from the deck

		// Constructor
		flash_cards(single_card cards[]) {
			for(int i = 0; i < deck_size; ++i) {
				deck[i] = cards[i];
			}	
		}

		// Get the next card
		const single_card& next_card() {
			const single_card &top_card = deck[deck_size];
			return top_card;
		}

		//test function
		void test();
	
	private:
		single_card deck[100];	//deck of flash cards
		int deck_size;			// Number of cards in the deck
		
};

void flash_cards::test() {
	std::cout << "Success!\n";
}
