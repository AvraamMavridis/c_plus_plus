#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>


int main(int argv, char** args){
	if(argv < 2){
		std::cerr << "File not specified." << std::endl;
		return -1;
	}

	std::ifstream File(args[1]);
	if(!File){
		std::cerr << "File " << args[1] << " not found." << std::endl;
	}

	std::istringstream iss;
	std::string title;
	int price,ratings;
	char temp,temp2;
	std::string cweight;
	float weight;
	
	while(std::getline( File, title, ';' )){
		File >> price >> temp >> temp2 >> ratings;
		File >> cweight;
		if(cweight == "-")
			weight = 0;
		else
			weight = std::stof(cweight);

		if(ratings >= 4){
		   std::cout << std::setw(45) << std::left << title
           << std::setw(10) << std::right << price << ":-"
           << std::setw(6) << ratings
           << std::setw(8) << std::setprecision(3) << weight
           << std::setw(8) << std::setprecision(3) << (weight+(weight-5)/ratings);
			
		}
	}
	std::cout << std::endl;

}