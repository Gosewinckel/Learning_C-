#include <iostream>
#include <cassert>

const int X_SIZE = 40;	// size of array in the x direction
const int Y_SIZE = 60;	// size of array in the y direction


char graphics[X_SIZE/8][Y_SIZE];	// graphics data

/**************************************************** 
 * set_bit -- set a bit in the graphics array.
 *
 * Parameters 
 *		x,y -- location of the bit
 ****************************************************/ 
inline void set_bit(const int x, const int y) {
	assert((x >= 0) && (x < X_SIZE));
	assert((y >= 0) && (y < Y_SIZE));
	graphics[(x)/8][y] |= static_cast<char>(0x80 >>((x)%8));
}

/**************************************************** 
 * clear_bit -- clear a bit in the graphics array.
 *
 * Parameters
 *		x,y -- location of the bit
 ***************************************************/ 
inline void clear_bit(const int x, const int y) {
	assert((x >= 0) && (x < X_SIZE));
	assert((y >= 0) && (y < Y_SIZE));
	char bit_mask = static_cast<char>(0x80 >>((x)%8));
	graphics[(x)/8][y] &= ~bit_mask;
}

/**************************************************** 
 * test_bit -- test if a bit is activated.
 *
 * Parameters
 *		x,y -- location of the bit
 ***************************************************/ 
inline void test_bit(const int x, const int y) {
	assert((x >= 0) && (x < X_SIZE));
	assert((y >= 0) && (y < Y_SIZE));
	if((graphics[(x)/8][y] & static_cast<char>(0x80 >>((x)%8))) == 0) {
		std::cerr << "Bit is innactive\n";
	}
	else {
		std::cerr << "Bit is active\n";
	}
}

int main() {
	int loc;	// current location
	
	// set all bits on diagonal to on
	for(loc = 0; loc < X_SIZE; ++loc) {
		set_bit(loc, loc);
		test_bit(loc, loc);
		clear_bit(loc, loc);
		test_bit(loc, loc);
	}
	return(0);
}
