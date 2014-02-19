#include <iostream>

int main(){
	int contents[] = {1,10,3,9,5,4,7,2,6};
	int current;
	for(int i=0; i<9; i++){
		current=i;
		for(int j=current; j>0; j--){
			if(contents[j-1]>contents[j]){
				contents[j-1] = contents[j-1]^contents[j];
				contents[j] = contents[j-1]^contents[j];
				contents[j-1] = contents[j-1]^contents[j];
			}
		}
	}
	for(int i=0; i<9; i++){
		std::cout << contents[i] << std::endl;
	}
}