#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <numeric>


//Connect one node to another if the other node is a root unless it connects it to seconds node root
void connect(std::vector<int>& nodes){
	std::cout << std::endl;
	std::cout << "Give two nodes seperated by a space ";
	int node1,node2;
	std::cin >> node1 >> node2;
	int flag = 0;
	int temp = node2;
	do{
		if(nodes.at(temp)==temp){
			nodes.at(node1) = temp;
			flag = 1;
		}
		else{
			temp = nodes.at(temp);
		}
	}while(flag==0);

	std::cout << std::endl;
}

//find the root of each node
int findroot(std::vector<int>& nodes,int element){
	int temp = nodes.at(element);
	int root = 0;
	int flag = 0;
	do{
		if(temp==nodes.at(temp)){
			root = temp;
			flag = 1;
		}
		else{
			temp = nodes.at(temp);
		}
	}while(flag==0);
	return root;
}

//if the roots are the same the nodes are connected
void checkconnection(std::vector<int>& nodes){
	std::cout << std::endl;
	std::cout << "Give two nodes seperated by a space ";
	int node1,node2;
	std::cin >> node1 >> node2;
	if(findroot(nodes,node1)==findroot(nodes,node2))
	 	std::cout << "Nodes are connected" << std::endl;
	else
		std::cout << "Nodes are not connected" << std::endl;
	std::cout << std::endl;
	

}

int main(){
	std::cout << "Give the number of the nodes";
	int NumberOfNodes;
	std::cin >> NumberOfNodes;
	std::vector<int> nodes(NumberOfNodes);
	std::iota(nodes.begin(),nodes.end(),0);

	int selection = 0;
	do{
		std::cout << "Menu:" << std::endl;
		std::cout << "To connect two nodes press 1" << std::endl;
		std::cout << "To check if two nodes are connected press 2" << std::endl;
		std::cout << "To print the connected components press 3" << std::endl;
		std::cout << "To exit press any other key" << std::endl;
		std::cout << "Selection: ";
		std::cin >> selection;
		switch(selection)
			{
			case 1:
			connect(nodes);
			break;
			case 2:
			checkconnection(nodes);
			break;
			case 3:
			//printcomponents(nodes);
			break;
			}
	}while(selection == 1 || selection == 2 || selection == 3);

	std::copy(nodes.begin(),nodes.end(),std::ostream_iterator<int>(std::cout," "));
}