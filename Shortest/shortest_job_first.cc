#include <iostream>
#include <vector>
#include <utility>
#include <vector>
#include <algorithm>
#include <sstream>

typedef std::pair<std::string,int> Task;
typedef std::vector<Task> Tasks;

Task taskForToday(Tasks& mytasks){
	std::sort(mytasks.begin(),mytasks.end());
	return mytasks.back();
}

int main(){
	int currentday = 0;
	std::string t = " ";
	int days = 0;
	Tasks tasks;
	Task todayTask;

	//do{

		do{
		std::cout << "Enter new task arriving at day " << currentday << ":";
		std::getline(std::cin,t);
		std::istringstream in(t);
		if(!(in >> t))
			break;
		std::cout << "Days needed for completion: ";
		std::cin >> days;
		tasks.push_back(std::make_pair(t,days));
		}while(true);
		//todayTask = taskForToday(tasks);
		//std::cout << todayTask.first;
	//}while(tasks.size() == 0);

}