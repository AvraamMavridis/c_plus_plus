#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <numeric>

void connect(std::vector<int>& nodes){
	std::cout << std::endl;
	std::cout << "Give two nodes seperated by a space ";
	int node1,node2;
	std::cin >> node1 >> node2;
	int valueofnode2 = nodes.at(node2);
	for(auto it=nodes.begin(); it!=nodes.end(); ++it){
		if(*it==valueofnode2)
			*it = nodes.at(node1);
	}
	std::cout << std::endl;
}

void checkconnection(std::vector<int>& nodes){
	std::cout << std::endl;
	std::cout << "Give two nodes seperated by a space ";
	int node1,node2;
	std::cin >> node1 >> node2;
	if(nodes.at(node1)==nodes.at(node2))
	 	std::cout << "Nodes are connected" << std::endl;
	else
		std::cout << "Nodes are not connected" << std::endl;
	std::cout << std::endl;
}

void printcomponents(std::vector<int>& nodes){
	std::vector<int> toprint;
	std::copy(nodes.begin(),nodes.end(),std::back_inserter(toprint));
	for(std::vector<int>::iterator it=toprint.begin(); it!=toprint.end(); ++it){
		std::vector<int> component;
		if(*it != -1)
		{
			component.push_back(*it);
			for(std::vector<int>::iterator itt=it+1; itt!=toprint.end(); ++itt){
				if(*it == *itt){
					component.push_back(std::distance(toprint.begin(),itt));
					*itt = -1;
				}
			}
			
			//std::cout << std::endl;

			switch(component.size()){
			case 0:
				break;
			case 1:
				std::cout << "{" << *component.begin() << "}" << std::endl;
				break;
		    default:
		    std::cout << "{";
			std::copy(component.begin(),component.end()-1,std::ostream_iterator<int>(std::cout,","));
			std::cout << *(component.end()-1);
			std::cout << "}";
			std::cout << std::endl;
		}
		}

		
		
	}	
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
			printcomponents(nodes);
			break;
			}
	}while(selection == 1 || selection == 2 || selection == 3);
	std::copy(nodes.begin(),nodes.end(),std::ostream_iterator<int>(std::cout," "));
}
