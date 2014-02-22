#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

int main(){
	int number;
	std::cin >> number;
	std::vector<int> binary;
	while(number!=0){
		binary.push_back(number%2);
		number = number / 2;
	}
	number = 0;
	for(std::vector<int>::reverse_iterator i=binary.rbegin(); i!=binary.rend(); i++)
		number += *i * std::pow(2,std::distance(binary.rbegin(),i)) ;
	std::cout << number;
}