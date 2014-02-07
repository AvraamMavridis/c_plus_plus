#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>

typedef std::vector<std::vector<int> >::iterator vectorvectoriterator;
typedef std::vector<int>::iterator vectorintiterator;


int main(){
	int testcases, totaljobs, jobscompleted;
	std::ostringstream out;
	std::cin >> testcases;
	std::vector<std::vector<int> > results(testcases);
	for(int i=0; i<testcases; i++){
		std::cin >> totaljobs >> jobscompleted;
		std::vector<int> jobs(totaljobs);
		int numb;
		std::cin.ignore(1024,'\n');
		std::string line;
		std::getline( std::cin, line);
		std::istringstream iss(line);
		while(iss >> numb){	
			jobs.at(numb-1) = -1;
		}
		results.at(i) = jobs;
	}

	for(vectorvectoriterator it=results.begin(); it!=results.end(); it++){
		std::vector<int> chefjobs;
		std::vector<int> assistantjobs;
		int flag = 0;
		for(vectorintiterator itt=it->begin(); itt!=it->end(); itt++)
		{
			
		 	 if((*itt == 0)&&(flag == 0))
		 	 {
		 	 	chefjobs.push_back(itt - (it->begin()-1));
		 	 	flag = 1;
		 	 }
		 	 else if((*itt == 0) && (flag == 1))
		 	 {
		 	 	assistantjobs.push_back(itt - (it->begin()-1));
		 	 	flag = 0;
		 	 }
		}
		for(vectorintiterator chefit=chefjobs.begin(); chefit!=chefjobs.end(); chefit++)
			std::cout << *chefit << " ";
		std::cout << std::endl;
		for(vectorintiterator asit=assistantjobs.begin(); asit!=assistantjobs.end(); asit++)
			std::cout << *asit << " ";
		std::cout << std::endl;
	}
}