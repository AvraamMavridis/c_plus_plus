#include <iostream>

void swap1(int& a,int& b){
	a = a^b;
	b = a^b;
	a = a^b;
}

void swap2(int& a,int& b){
	int temp = a;
	a = b;
	b = temp;
}

void swap3(int& a,int& b){
	a = a + b;
	b = a - b;
	a = a - b;
}

void swap4(int& a, int& b){
	a = a*b;
	b = a/b;
	a = a/b;
}

int main(){
	int a,b;
	std::cout << "a: ";
	std::cin >> a;
	std::cout << "b: ";
	std::cin >> b;

	std::cout << "Swap method 1: ";
	swap1(a,b);
	std::cout << "a: " << a << " b: " << b << std::endl;
	std::cout << "Swap method 2: ";
	swap2(a,b);
	std::cout << "a: " << a << " b: " << b << std::endl;
	std::cout << "Swap method 3: ";
	swap3(a,b);
	std::cout << "a: " << a << " b: " << b << std::endl;
	std::cout << "Swap method 4: ";
	swap4(a,b);
	std::cout << "a: " << a << " b: " << b << std::endl;

}