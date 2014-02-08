/** Write a program which creates a vector<char> which stores the letters a-z in order. Print the 
elements in the vector in order and in reverse order using std::copy. */

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

int main(){
	std::vector<char> letters(26);
	std::iota(letters.begin(),letters.end(),'a');
	std::copy(letters.begin(),letters.end(),std::ostream_iterator<char>(std::cout,""));
	std::cout << std::endl;
	std::copy(letters.rbegin(),letters.rend(),std::ostream_iterator<char>(std::cout,""));
	std::cout << std::endl;
}