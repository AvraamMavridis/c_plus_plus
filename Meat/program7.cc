#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <sstream>
#include <algorithm>
#include <utility>


typedef std::pair<std::string,int> Element;
namespace std 
{
	std::ostream& operator<<(std::ostream& os,Element element){
		os << element.first << " : " << element.second;
		return os;
	}
}

bool sortbyday(Element a, Element b){
	return a.second < b.second;
}

Element adjuct(Element e){
	Element new_element;
	new_element.first = e.first;
	if(e.second == 1)
		new_element.second = 2;
	else if(e.second == 2)
		new_element.second = 4;
	else if(e.second > 2)
		new_element.second = e.second + 3;

	return new_element;
}

int main(int argv,char** argc){
	if(argv < 2 | argv > 3)
	{
		std::cerr << "Input file not specified or more than one input files" << std::endl;
		return -1;
	}
	std::ifstream File;
	File.open(argc[1]);
	if(!File){
		std::cerr << "Could not open file " << argc[1] << std::endl;
		return -2;
	}


  	std::string line;
  	std::vector<Element> products;
  	while(std::getline(File,line))
  	{
  		std::istringstream iss(line);
  		std::string name;
  		int days;
  		char delim;
  		std::getline(iss,name,':');
  		iss >> days;
  		products.push_back(std::make_pair(name,days));
  	}

  	std::sort(products.begin(),products.end());
  	std::copy(products.begin(), products.end(), std::ostream_iterator<Element>(std::cout, "\n"));
  	if(argv==3){
  	if(argc[2][0]=='A'){
  		std::transform(products.begin(),products.end(),products.begin(),adjuct);
  	}}
  	std::sort(products.begin(),products.end(),sortbyday);
  	std::copy(products.begin(), products.end(), std::ostream_iterator<Element>(std::cout, "\n"));
  		

}