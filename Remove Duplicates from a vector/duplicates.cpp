#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void removeDuplicate(std::vector<int>& array)
{
	int count=0;
	int n=array.size();	
	for(int i=0; i<array.size()-1; i++){
		int value=array.at(i);
		
		for(int j=i+1; j<n; j++){
			if(array.at(j)==value){
					for(int k=j;k<array.size()-1; k++)
						array.at(k) = array.at(k+1);
					n--;
				}
		}
	 
	}
	array.resize(n);
	//array.resize(std::distance(array.begin(),array.begin()+count));
}

int main(){
	std::vector<int> array{1,2,2,3,4,4,5,6,7,8,9,1,2,1,3,15};

	removeDuplicate(array);
	std::copy(array.begin(),array.end(),std::ostream_iterator<int>(std::cout,","));
	 
}