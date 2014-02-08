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