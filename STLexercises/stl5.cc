/** Create a vector<string> and read a list with names of car brands into the vector. Sort the list using 
std::sort and print the result using std::copy. There is a given text ﬁle with car brands, named 
cars_of_the_world.txt. */


#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <functional>

std::string lowering(std::string lower){
	std::transform(lower.begin(),lower.end(),lower.begin(),::tolower);
	return lower;
}

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
	std::transform(cars.begin(),cars.end(),cars.begin(),lowering);
	std::copy(cars.begin(),cars.end(),std::ostream_iterator<std::string>(std::cout,"\n"));
}