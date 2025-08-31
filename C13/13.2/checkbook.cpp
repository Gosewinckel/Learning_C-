/**************************************************** 
 * Checkbook -- This program defines a class to act 
 * as a checkbook
 *
 * Author -- Lewis Gosewinckel
 *
 ***************************************************/ 

#include <iostream>


class checkbook {
	public:
		int entries[100];		// a list of entries into the checkbook, would use a pointer but haven't learned yet
		int entry_num;			// the number of entries in entries
		int total;				// the total value of entries
		
		//class functions
		checkbook() {
			entry_num = 0;
			total = 0;
		}

		void add_item(int amount) {		//insert and item into the checkbook
			entries[entry_num] = amount;
			++entry_num;
		}

		// Return the total of all the entries
		int calculate_total() {
			for(int i = 0; i < entry_num; i++) {
				total += entries[i];
			}
			return total;
		}
};


int main() {
	checkbook checkbook_x;

	for(int i = 0; i < 5; i++) {
		checkbook_x.add_item(i + 1);
	}

	int total = checkbook_x.calculate_total();
	std::cout << "total amount: " << total << "\n";
}
