#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iterator>

void rotate(std::string& word,int monkey){
	char temp;
	for(int j=0; j<monkey; j++){
			 	temp = word[word.size()-1];
				for(int z=word.size()-1; z>0; z--){
					word[z] = word[z-1];
				}
				word[0] = temp;
			}
}

int main(){
	int testcases;
	std::cin >> testcases;
	int monkey,pop;
	std::string word;
	std::string initialword;
	std::vector<int> counts(testcases);
	for(int i=0; i<testcases; i++){
		std::cin >> word;
		initialword = word;
		std::cin >> monkey >> pop;
			while(true){
					rotate(word,monkey);
					counts[i]++;
					if(word == initialword)
					break;
					rotate(word,pop);
					counts[i]++;
					if(word == initialword)
					break;	
			}
				 
	}
	std::copy(counts.begin(),counts.end(),std::ostream_iterator<int>(std::cout,"\n"));
	
}