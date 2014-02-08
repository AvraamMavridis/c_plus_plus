/*
The following code is found in a program, where the vector v is populated with int values in 
some way, and then sorted as shown.
vector<int> v; 
sort(v.begin(), v.end(), greater<int>());
Add code to then read one integer value at a time from cin, search for the value in v with 
std::binary_search and print if a value was found or not. */

#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>

int main(){
	std::vector<int> v{10,20,1,34,654,1,4,234,5,24,2,147,7,5}; 
	std::sort(v.begin(), v.end(), std::greater<int>());
	std::copy(v.begin(),v.end(),std::ostream_iterator<int>(std::cout," "));
	std::cout << std::endl;
	int value;
	while(std::cin >> value){
			if(std::binary_search(v.rbegin(),v.rend(),value))
				std::cout << "Found " << std::endl;
			else
				std::cout << "Not found" << std::endl;
	}
}