#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>

// std::ostream& operator<<(std::ostream& out,const char* obj){
// 	out << obj;
// 	out << "\n";
// 	return out;
// }

std::string isAmbigous(std::vector<int>& permutations){
	std::vector<int>::iterator itt;
	int flag = 0;
	for(itt = permutations.begin(); itt!=permutations.end(); itt++)
	{
		if(itt-permutations.begin() != permutations.at(*itt))
			flag = 1;
	}
	if(flag == 0)
		return "ambiguous";
	else
		return "not ambiguous";
}


int main(){
	int temp=1;
	std::string line;
	std::vector<std::string> results;
	do
	{
		std::cin >> temp;
		if(temp!=0){
		std::cin.ignore(1024,'\n');
		std::getline(std::cin,line);
		std::istringstream iss(line);
		std::vector<int> permutations;
		permutations.push_back(0);
		int n;
		while(iss >> n)
			permutations.push_back(n);
		results.push_back(isAmbigous(permutations));
		}
		else
			break;
	}while(true);

	std::vector<std::string>::iterator itresult;
	for(itresult = results.begin(); itresult!=results.end(); itresult++)
		std::cout << *itresult << std::endl;
}