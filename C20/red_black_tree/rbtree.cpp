/**************************************************** 
 * rbtree -- this program defines a class for a red 
 * black binary tree
 *
 * Author -- Lewis Gosewinckel
 *
 * Purpose -- defines a red black binary tree for 
 * effitient data allocation
 *
 * usage -- currently no usage but can be adapted to 
 * be used in larger programs
 ****************************************************/ 

#include <iostream>

class red_black_tree {
	private:
		class node {
			public:
				int data;	// data value held in node

				// Node constructor, 
				node(int data, bool red) {
					this->data = data;
					this->red = true;
					parent_ptr = NULL;
					left_child_ptr = NULL;
					right_child_ptr = NULL;
				}

				// Destructor for node
				~node() {}

			private:
				bool red;	// Colour of the node
				node *parent_ptr;	 
				node *left_child_ptr;
				node *right_child_ptr;

				//function change set colour of node
				void set_black() {
					red = false;
					return;
				}
				void set_red() {
					red = true;
					return;
				}
			friend class red_black_tree;
				
		};
		
		// Root node
		node *root_ptr;

		// Rotation functions to balance tree
		void rotate_left(node *x);
		void rotate_right(node *x);

	public:
		red_black_tree() {
			root_ptr = NULL;
		}
		

		node *search(int val) {
			node *temp = root_ptr;
			node *head_ptr;
			while(true) {
				// If val cannot be found return NULL
				if(temp == NULL) {
					return NULL;
				}
				if(temp->data == val) {
					return temp;
				}
				//choose which direction to search
				if(temp->data > val) {
					temp = temp->left_child_ptr;
				}
				else if(temp->data < val) {
					temp = temp->right_child_ptr;
				}
			}
		}

		// Add and delete node from tree
		void add_node(int val);
		void delete_node(int val);
};

void red_black_tree::rotate_left(node *x) {
	node *y = x->right_child_ptr;		//temporary node for new root
	
	// Move node left subtree to sub_heads right subtree
	x->right_child_ptr = y->left_child_ptr;
	if(y->left_child_ptr != NULL) {
		y->left_child_ptr->parent_ptr = x;
	}
	//update parent nodes
	y->parent_ptr = x->parent_ptr;
	// Case: sub_head is the root node
	if(x->parent_ptr == NULL) {
		root_ptr = y;
	}
	// Case: sub_head is left child
	else if(x == x->parent_ptr->left_child_ptr) {
		x->parent_ptr->left_child_ptr = y;
	}
	// Case: sub_head is right child
	else {
		x->parent_ptr->right_child_ptr = y;
	}
	y->left_child_ptr = x;
	x->parent_ptr = y;
}

void red_black_tree::rotate_right(node*x) {
	node *y = x->left_child_ptr;

	x->left_child_ptr = y->right_child_ptr;
	if(y->right_child_ptr != NULL) {
		y->right_child_ptr = x;
	}
	y->parent_ptr = x->parent_ptr;
	if(x->parent_ptr == NULL) {
		root_ptr = y;
	}
	else if(x == x->parent_ptr->left_child_ptr) {
		x->parent_ptr->left_child_ptr = y;
	}
	else {
		x->parent_ptr->right_child_ptr = y;
	}
	y->right_child_ptr = x;
	x->parent_ptr = y;
}
