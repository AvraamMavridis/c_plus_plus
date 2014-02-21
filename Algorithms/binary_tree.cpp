#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class Node{
	public:
		Node(int v):value(v),left(nullptr),right(nullptr){};
		~Node(){};
		Node* left;
		Node* right;
		int value;
};

class Tree{
	public:
		Tree(Node* h):head(h){};
		~Tree(){};
		void insert(Node* n);
		void print(Node* root);
		//void delete(Node* n); To be implemented
		Node* head;
};

void Tree::print(Node* root){
	if(root){
		std::cout << root->value << "\n";
	}
	if(root->left){
		std::cout << "left ";
		print(root->left);
	}
	if(root->right){
		std::cout << "right ";
		print(root->right);
	}
}

void Tree::insert(Node* n){
	Node* root = head;
	while(true){
		if(n->value > root->value){
			if(root->right==nullptr){
			root->right = n;
			return;
			}
			else{
				root = root->right;
			}
		}
		else if(n->value <= root->value && root->left==nullptr)
			if(root->left==nullptr){
				root->left = n;
				return;
			}
			else{
				root = root->left;
			}
	}
}



int main(){
	Node* head = new Node(19);
	Tree* mytreee = new Tree(head);
	Node* node2 = new Node(29);
	mytreee->insert(node2);
	Node* node3 = new Node(49);
	mytreee->insert(node3);
	Node* node4 = new Node(5);
	mytreee->insert(node4);
	mytreee->print(head);
	
}