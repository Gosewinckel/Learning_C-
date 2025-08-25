// This program computes the area and perimeter of a constant rectangle
#include <iostream>

int height = 3;			// height of a rectangle
int width = 5;			// width of a rectangle

int main() {
	//calculate the area and perimeter of a rectangle
	int area = height * width;			
	int perimeter = height*2 + width*2;

	std::cout << "Area: " << area << "\n";
	std::cout << "Perimeter: " << perimeter << "\n";
	return(0);
}
