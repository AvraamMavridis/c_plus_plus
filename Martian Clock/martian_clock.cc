#include <iostream>
#include <sstream>
#include <iomanip>


class Day{
	public:
		Day(int hours,int minutes,int seconds){
			_hours = hours;
			_minutes = minutes;
			_seconds = seconds;
		}
		void shiftOneSecond(){
			_hours = (_hours + ((_minutes + (_seconds + 1 ) / 67 ) / 53))%25;
			_minutes = (_minutes + (_seconds + 1 ) / 67 ) % 53;
			_seconds = ( _seconds + 1 ) % 67;
		}
		int getHours()const { return _hours;};
		int getMinutes()const { return _minutes;};
		int getSeconds()const { return _seconds;};
		friend std::ostream& operator<<(std::ostream& out, Day _myDay){
			out << std::setfill ('0') << std::setw (2) << _myDay.getHours() << ":" 
			<< std::setfill ('0') << std::setw (2) << _myDay.getMinutes() << ":" 
			<< std::setfill ('0') << std::setw (2) << _myDay.getSeconds();
			return out;
		}
	private:
		int _hours;
		int _minutes;
		int _seconds;
};

int main(){

	
	std::string line;
	std::cout << "Insert time in HH:MM:SS format: ";
	std::cin >> line;
	std::istringstream iss(line);
	int hours,minutes,seconds;
	char temp;
	iss >> hours >> temp >> minutes >> temp >> seconds;
	
	Day myDay(hours,minutes,seconds);
	std::cout << myDay << std::endl;
	myDay.shiftOneSecond();
	std::cout << myDay << std::endl;
	



}