#include <iostream>

int main(){
	int contents[] = {1,10,3,9,5,4,7,2,6};
	int current,temp;
	for(int i=0; i<9; i++){
		current = i;
		while(current > 0 && contents[current-1] > contents[current]){
			contents[current-1] = contents[current-1]^contents[current];
			contents[current] = contents[current-1]^contents[current];
			contents[current-1] = contents[current-1]^contents[current];
			current--;
		}

	}

	for(int i=0; i<9; i++){
		std::cout << contents[i] << std::endl;
	}
}