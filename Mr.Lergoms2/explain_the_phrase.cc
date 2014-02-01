#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include <sstream>
#include <iterator>

typedef std::vector<std::string> Examples;
typedef std::pair<std::string,Examples> phrase;


int main(int argv,char** args){
	std::vector<phrase> phrases;
	std::vector<phrase>::iterator ittphrases;
	Examples::iterator ittex;

	if(argv < 2){
		std::cerr << "File not specified." << std::endl;
		return -1;
	}

	std::ifstream File(args[1]);

	if(!File){
		std::cerr << "File " <<  args[1] << "not found." << std::endl;
	}


	std::istringstream iss;
	std::string line;
	std::string phrase;
	while(std::getline(File,line)){
		Examples ex;
		do{
			std::getline(File,phrase);
			if(phrase!="")
				ex.push_back(phrase);
		}while(phrase!="");
		phrases.push_back(std::make_pair(line,ex));
	}

	std::cout << "Enter a keyword of the phrase to explain: ";
	std::string keyword;
	std::cin >> keyword;

	for(ittphrases=phrases.begin(); ittphrases!=phrases.end(); ++ittphrases){
		if(ittphrases->first.find(keyword)!=std::string::npos){
			std::cout << std::endl;
			std::cout << ittphrases->first << std::endl;
			for(ittex=ittphrases->second.begin(); ittex!=ittphrases->second.end(); ++ittex){
				std::cout << " -- " << *ittex << std::endl;
			}
		}
	}

	

	

}