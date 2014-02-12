#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

struct replaceOdd{
	int operator()(int i){
		if(i%2!=0)
			return 0;
		else
			return i;
	}
};

struct isZero
{
	bool operator()(int i){
		if(i==0) return true;
		else return false;
	}	
};

int main()
{
	
	std::vector<int> input;
	std::copy(std::istream_iterator<int>(std::cin),std::istream_iterator<int>(),std::back_inserter(input));
	std::cout << input.size() << " values read" << std::endl;
	std::copy(input.begin(),input.end(),std::ostream_iterator<int>(std::cout," "));
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Values sorted: " << std::endl;
	std::sort(input.begin(),input.end());
	std::copy(input.begin(),input.end(),std::ostream_iterator<int>(std::cout," "));
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Odd values replaced with zeroes:" << std::endl;
	std::transform(input.begin(),input.end(),input.begin(),replaceOdd());
	std::transform(input.begin(),input.end(),input.begin(),replaceOdd());
	std::copy(input.begin(),input.end(),std::ostream_iterator<int>(std::cout," "));
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Zeroes removed:" << std::endl;
	auto it = std::remove_if(input.begin(),input.end(),isZero());
	input.resize(std::distance(input.begin(),it));
	std::copy(input.begin(),input.end(),std::ostream_iterator<int>(std::cout," "));


}