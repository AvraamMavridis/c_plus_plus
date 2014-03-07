#include <iostream>
#include <iterator>
#include <vector>


int fibr(int n){
	if(n==0) return 0;
	if(n==1) return 1;

	return fibr(n-1)+fibr(n-2);
}

int fib(int n){
	if(n==0) return 0;
	if(n==1) return 1;

	int n1=0;
	int n2=1;
	int value;
	for(int i=1; i<n; i++){
		value=n1+n2;
		n1=n2;
		n2=value;
	}
	return value;
}


int main(){
	std::cout << fibr(3) << std::endl;
	std::cout << fibr(11) << std::endl;
	std::cout << fib(11) << std::endl;
}