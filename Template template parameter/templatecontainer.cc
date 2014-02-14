#include <iostream>
#include <vector>
#include <iterator>
#include <deque>
#include <string>
#include <initializer_list>

template <typename T, template <typename ELEM, typename ALLOC=std::allocator<ELEM> > class Cont=std::vector>
class VehiclesContainer {
  public:
  	VehiclesContainer(std::initializer_list<T> l):container(l){};
  	virtual ~VehiclesContainer(){};
  	virtual void addVehicle(T elem);
  	virtual T getFirst() const;
  	template
  	<typename U, template <typename ELEM2, typename ALLOC=std::allocator<ELEM2> > class Cont2>
  	friend std::ostream& operator<<(std::ostream& out, const VehiclesContainer<U,Cont2>& obj);
  private:
    Cont<T> container;
};




template
<typename T,template <typename ELEM,typename ALOC=std::allocator<ELEM> > class Cont>
std::ostream& operator<<(std::ostream& out,const VehiclesContainer<T,Cont>& obj){
	typename Cont<T>::const_iterator it;
	for(it=obj.container.begin(); it!=obj.container.end(); ++it)
		out << *it << " ";
	return out;
}

// template
// <int,template <typename ELEM,typename ALOC=std::allocator<ELEM> > class Cont>
// std::ostream& operator<< <>(std::ostream& out,const VehiclesContainer<int,Cont>& obj){
// 	typename Cont<int>::const_iterator it;
// 	for(it=obj.container.begin(); it!=obj.container.end(); ++it)
// 		out << *it << "--";
// 	return out;
// }

template 
<typename T, template <typename ELEM, typename ALLOC=std::allocator<ELEM> > class Cont>
void VehiclesContainer<T,Cont>::addVehicle(T elem){
	container.push_back(elem);
}

template
<typename T,template <typename ELEM,typename ALOC=std::allocator<ELEM> > class Cont>
T VehiclesContainer<T,Cont>::getFirst() const{
	return *(container.begin());
}


//Subclass of VehicleContainer
template
<typename T, template <typename ELEM, typename ALOC=std::allocator<ELEM> > class Cont>
class CarContainer : public VehiclesContainer<T,Cont>{
	public:
		CarContainer(std::initializer_list<T> l):VehiclesContainer<T,Cont>(l){};
		virtual ~CarContainer(){};
		virtual T getFirst() const override;

};

template
<typename T,template <typename ELEM,typename ALOC=std::allocator<ELEM> > class Cont>
T CarContainer<T,Cont>::getFirst() const
{
    return VehiclesContainer<T,Cont>::getFirst();
}


int main(){
	VehiclesContainer<double,std::vector > aStack1({10,20,30});
	std::cout << aStack1;

}