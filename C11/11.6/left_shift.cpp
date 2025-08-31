/**************************************************** 
 * This program shifts all the on bits in a number to 
 * the left
 *
 * Author: Lewis Gosewinckel
 *
 * Purpose: learning bitwise operations
 *
 * Usage: run the program and input a number, all 
 * the bits in that number will be shifted to the left
 ***************************************************/ 

#include <iostream>
#include <cmath>


/**************************************************** 
 * shift_left -- shifts all proceeding bits to the
 * left until an on bit is found
 *
 * Parameters:
 *		x, loc:
 *			x = number to be shifted
 *			loc = position of bit to be shifted to
 ***************************************************/ 
int shift_left(int x, int loc) {
	int idx = 0;			// amount of places that need to be shifted
	int place = loc;		//temporary storage of places
							//
	//find location of next bit
	while((x & place) != 0) {
		place /= 2;
		++idx;
	}

	//create mask for new shifted int
	short int bitmask = x;
	bitmask *= std::pow(2, idx);
	loc *= 2;
	while(loc <= 0x4000) {
		x |= loc;
		loc *= 2;
	}
	return x;
}

int main() {
	short int x;	//integer input by user

	//get user to input a number
	std::cout << "pick a number:";
	std::cin >> x;

	int loc = 0x4000;
	while(loc > 0) {
		x = shift_left(x, loc);
		loc /= 2;
	}
	std::cout << "x: " << x << "\n";
	return(0);

}
