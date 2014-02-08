/**Before printing the cars, their names are to be lower-cased. Deﬁne a function 
object class to lower case the letters in a string. Use std::transform() and such a function object to 
iterate over all cars and lower-case their names */


#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <functional>



bool decide(std::string first,std::string second){
	std::transform(first.begin(),first.end(),first.begin(),::tolower);
	std::transform(second.begin(),second.end(),second.begin(),::tolower);
	auto pos = std::find(second.begin(),second.end(),*(first.begin()));
	return pos!=second.end();
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
	std::copy_if(cars.begin(),cars.end(),std::ostream_iterator<std::string>(std::cout,"\n"),std::bind(decide,std::placeholders::_1,"ABC"));
}