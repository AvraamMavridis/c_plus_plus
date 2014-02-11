#include <iostream>
#include <vector>
#include <initializer_list>
#include <iterator>
#include <algorithm>


//Generic class
template
<typename T>
class NumberContainer{
	public:
		NumberContainer(std::initializer_list<T> contents):contents_(contents){ std::cout <<"Generic constructor" << std::endl; };
		~NumberContainer(){};
		int getSize() const;
		void sortContainer();
	    void pushBack(T element);
	    T at(int position) const;
		template <typename U>
		friend std::ostream& operator<<(std::ostream& out,const NumberContainer<U>& obj);
	private:
		std::vector<T> contents_;
};


//Integer class specialization
template
<>
class NumberContainer<int>{
	public:
		NumberContainer(std::initializer_list<int> contents):contents_(contents){ std::cout <<"Integer constructor" << std::endl; };
		template <typename U>
		friend std::ostream& operator<<(std::ostream& out,const NumberContainer<U>& obj);
	private:
		std::vector<int> contents_;
};

template
<typename T>
T NumberContainer<T>::at(int position) const {
	return contents_.at(position);
}

template
<typename T>
int NumberContainer<T>::getSize() const{
	return contents_.size();
}

template
<typename T>
void NumberContainer<T>::pushBack(T element){
	contents_.pushBack(element);
}

template
<typename T>
void NumberContainer<T>::sortContainer(){
	sort(contents_.begin(),contents_.end());
}

template <typename U>
std::ostream& operator<<(std::ostream& out,const NumberContainer<U>& obj){
	for(auto it = obj.contents_.begin(); it!=obj.contents_.end(); ++it){
		out << *it << std::endl;
	}
	return out;
}
	


int main(){
	NumberContainer<int> loops{1,2,3,4,5,6,7,8};
	std::cout << loops;
}