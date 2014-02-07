#include <iostream>
#include <tuple>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iomanip>

typedef std::tuple<std::string,int,float> Person;
typedef std::vector<Person> Persons;

namespace std{
	std::ostream& operator<<(std::ostream& out,Person person){
		out <<  "Name: " << std::setw(10)<< left << std::get<0>(person) << " Age: " 
		<< std::setw(10) << left << std::get<1>(person) 
		<< " Salary: " << std::get<2>(person); 
		return out;
	}
}

struct sortbysalary{
	bool operator()(Person a, Person b){
		return std::get<2>(a) > std::get<2>(b);
	}
};

int main(){
	auto p = std::make_tuple("Makis",26,1400.23);
	auto p2 = std::make_tuple("Giorgos",22,1440.93);
	auto p3 = std::make_tuple("Petros",21,1500.45);

	Persons persons{p,p2,p3};
	std::sort(persons.begin(),persons.end(),sortbysalary());
	std::copy(persons.begin(),persons.end(),std::ostream_iterator<Person>(std::cout,"\n"));


}