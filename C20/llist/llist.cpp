/**************************************************** 
 * llist -- create a linked list that can sort and
 * store random numbers
 *
 * Usage:
 *		does nothing really
 ****************************************************/ 

#include <iostream>
#include <cstdlib>

class llist {
	private:
		// node in a list
		class node {
			private:
				node *prev_ptr;
				node *next_ptr;
			public:
				int data;

			friend class llist;
		};

	public:
		// Head of llist
		node *head_ptr;

		// Constructor
		llist() {
			head_ptr = NULL;
		}

		// Add item to the list
		void add_node(const int val);

		// Delete a node
		void delete_node(const int val);

		// Print entire list
		void print_list();
};

void llist::add_node(const int val) {
	node *node_ptr = head_ptr;

	// If list is empty
	if(node_ptr == NULL) {
		node *new_node_ptr = new node;
		new_node_ptr->data = val;
		new_node_ptr->prev_ptr = NULL;
		new_node_ptr->next_ptr = NULL;
		head_ptr = new_node_ptr;
		return;
	}

	//find first val larger than val
	while(true) {
		// Found last node
		if(node_ptr->next_ptr == NULL) {
			break;
		}
		// Found node higher than val
		if(node_ptr->data >= val) {
			break;
		}
		node_ptr = node_ptr->next_ptr;
	}
	
	//node to be inserted
	node * new_node_ptr = new node;
	new_node_ptr->data = val;
	
	// Case: new highest value
	if(node_ptr->next_ptr == NULL) {
		node_ptr->next_ptr = new_node_ptr;
		new_node_ptr->prev_ptr = node_ptr;
		new_node_ptr->next_ptr = NULL;
		return;
	}

	// Case: new lowest value
	if(node_ptr->prev_ptr == NULL) {
		new_node_ptr->next_ptr = node_ptr;
		new_node_ptr->prev_ptr = NULL;
		node_ptr->prev_ptr = new_node_ptr;
		head_ptr = new_node_ptr;
		return;
	}

	new_node_ptr->next_ptr = node_ptr;
	new_node_ptr->prev_ptr = node_ptr->prev_ptr;
	node_ptr->prev_ptr->next_ptr = new_node_ptr;
	node_ptr->prev_ptr = new_node_ptr;
	return;

}

void llist::delete_node(const int val) {
	return;
}

void llist::print_list() {
	node *node_ptr = head_ptr;
	while(node_ptr != NULL) {
		std::cout << node_ptr->data << ", ";
		node_ptr = node_ptr->next_ptr;
	}
	std::cout << "\n";
	return;
}

int main() {
	llist list = llist();
	for(int i = 0; i < 10; i++) {
		int input = rand() % 11;
		list.add_node(input);
	}
	
	// Print list
	list.print_list();
	return(0);
}
