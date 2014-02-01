#include <iostream>
#include <string>
#include <vector>

int main(){
	std::string good1 = "010";
	std::string good2 = "101";
	std::string temp;
	std::vector<std::string> feedbacks;
	int T,i = 0;

	std::cin >> T;
	while(i < T){
		std::cin >> temp;
		feedbacks.push_back(temp);
		i++;
	}

	i = 0;
	std::size_t found;
	std::size_t found2;
	while(i < T){
		found = feedbacks.at(i).find(good1);
		found2 = feedbacks.at(i).find(good1);
		if(found!=std::string::npos || found2!=std::string::npos  ){
			std::cout << "Good" << std::endl;
		}
		else{
			std::cout << "Bad" << std::endl;
		}
		i++;
	}
}