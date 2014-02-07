#include <iostream>


class IntegerWrapper{
	public:
		IntegerWrapper(int v):_value(v){};
	    IntegerWrapper(float v) = delete;
	    IntegerWrapper(double v) = delete;
		const IntegerWrapper operator=(const IntegerWrapper& obj);
		const IntegerWrapper operator+(const IntegerWrapper& obj);
		const IntegerWrapper operator/(const IntegerWrapper& obj);
		const IntegerWrapper operator*(const IntegerWrapper& obj);
		bool operator>(const IntegerWrapper& obj);
		bool operator<(const IntegerWrapper& obj);
		bool operator==(const IntegerWrapper& obj);
		bool operator>=(const IntegerWrapper& obj);
		bool operator<=(const IntegerWrapper& obj);
		friend std::ostream& operator<<(std::ostream& out, const IntegerWrapper& obj);
		friend std::istream& operator>>(std::istream& in,  IntegerWrapper& obj);
		IntegerWrapper& operator+=(const IntegerWrapper& obj);
		IntegerWrapper& operator-=(const IntegerWrapper& obj);
		IntegerWrapper& operator/=(const IntegerWrapper& obj);
		IntegerWrapper& operator*=(const IntegerWrapper& obj);
		IntegerWrapper& operator++();
		IntegerWrapper& operator++(int v);
		int getValue() const { return _value;};
	protected:
		int _value;
};

std::ostream& operator<<(std::ostream& out, const IntegerWrapper& obj){
	out << "Integer: " << obj.getValue() << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in,IntegerWrapper& obj){
	in >> obj._value;
	return in;
}

const IntegerWrapper IntegerWrapper::operator=(const IntegerWrapper& obj){
	this->_value = obj.getValue();
}

const IntegerWrapper IntegerWrapper::operator+(const IntegerWrapper& obj){
	return IntegerWrapper(this->_value+obj.getValue());
}

const IntegerWrapper IntegerWrapper::operator/(const IntegerWrapper& obj){
	return IntegerWrapper(this->_value/obj.getValue());
}

const IntegerWrapper IntegerWrapper::operator*(const IntegerWrapper& obj){
	return IntegerWrapper(this->_value*obj.getValue());
}

bool IntegerWrapper::operator>(const IntegerWrapper& obj){
	return (this->_value > obj.getValue()) ? true : false;
}

bool IntegerWrapper::operator<(const IntegerWrapper& obj){
	return (this->_value < obj.getValue()) ? true : false;
}

bool IntegerWrapper::operator==(const IntegerWrapper& obj){
	return (this->_value == obj.getValue()) ? true : false;
}

bool IntegerWrapper::operator>=(const IntegerWrapper& obj){
	return (this->_value >= obj.getValue()) ? true : false;
}

bool IntegerWrapper::operator<=(const IntegerWrapper& obj){
	return (this->_value <= obj.getValue()) ? true : false;
}

IntegerWrapper& IntegerWrapper::operator+=(const IntegerWrapper& obj){
	this->_value+=obj.getValue();
	return *this;
}

IntegerWrapper& IntegerWrapper::operator-=(const IntegerWrapper& obj){
	this->_value-=obj.getValue();
	return *this;
}

IntegerWrapper& IntegerWrapper::operator/=(const IntegerWrapper& obj){
	this->_value/=obj.getValue();
	return *this;
}

IntegerWrapper& IntegerWrapper::operator*=(const IntegerWrapper& obj){
	this->_value*=obj.getValue();
	return *this;
}

IntegerWrapper& IntegerWrapper::operator++(){
	this->_value++;
}

IntegerWrapper& IntegerWrapper::operator++(int v){
	++(this->_value);
}

int main(){

	IntegerWrapper v(19);
	IntegerWrapper k(200);
	std::cout << v+k;
	v+=k;
	std::cout << v;
	v-=k;
	std::cout << v;
	v*=k;
	std::cout << v;
	v/=k;
	std::cout << v;
	++v;
	std::cout << v;
	v++;
	std::cout << v;




}