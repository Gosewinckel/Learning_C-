// This program calculates change in coins for values less than $1
#include <iostream>

float amount;
int quarters;
int dimes;
int nickels;
int pennies;


int main() {
	//get amount from user
	std::cout << "enter change < $1\n";
	std::cin >> amount;
	//make sure user entered valid amount
	while(amount > 1 || amount < 0) {
		std::cout << "must be number greater than 0 and less than 1\n";
		std::cin >> amount;
	}

	//calculate amount of each coin
	//quarters
	while(amount >= 0.25) {
		amount -= 0.25;
		++quarters;
	}
	//dimes
	while(amount >= 0.10) {
		amount -= 0.10;
		++dimes;
	}
	//nickels
	while(amount >= 0.05) {
		amount -= 0.05;
		++nickels;
	}
	//pennies
	if(amount >= 0.01) {
		pennies = amount*100;
		amount = 0;
	}
	
	//output results
	std::cout << "quarters: " << quarters << "\n";
	std::cout << "dimes: " << dimes << "\n";
	std::cout << "nickels: " << nickels << "\n";
	std::cout << "pennies: " << pennies << "\n";
	return(0);
	
}
