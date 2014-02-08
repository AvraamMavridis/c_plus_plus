/** Rewrite exercise 2. Instead of printing all cars using std::copy(), construct a loop for printing all 
car brands in the list in exercise 2, which begins with a certain letter, e.g all car brands beginning 
with ’A’. Try both the ordinary for loop, with iterators, and the range based for loop. */


#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <iomanip>

int main(int argv, char** argc){
	if(argv < 2 || argv > 3)
	{
		std::cerr << "File not specified or more than one files" << std::endl;
		return -1;
	}
	std::fstream File;
	File.open(argc[1]);
	if(!File.good()){
		std::cerr << "Could not open file " << argc[1] << std::endl;
		return -2; 
	}
	std::istream_iterator<std::string> input(File);
	std::istream_iterator<std::string> eof;
	std::vector<std::string> cars(input,eof);
	std::sort(cars.begin(),cars.end());
	for(auto it=cars.begin(); it!=cars.end(); ++it){
		if((*it)[0]='A')
			std::cout << *it << std::endl;
	}
	std::cout << std::setw(30) << std::setfill('=') << std::left << "" << std::endl;
	for(auto it : cars){
		std::cout << it << std::endl;;
	}
}