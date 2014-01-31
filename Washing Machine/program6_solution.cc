/*
 * program6.cc
 */
#include <iostream>
using namespace std;

// Define washing equipment classes here

class Washing_Equipment{
	public:
		Washing_Equipment(std::string m,std::string ec):_model(m),_energyclass(ec){};
		virtual ~Washing_Equipment() = default;
		std::string getModel() const {return _model;};
		std::string getEnergyClass() const { return _energyclass;};
		virtual Washing_Equipment* clone() = 0;

	protected:
		Washing_Equipment(const Washing_Equipment& obj) = default;
		Washing_Equipment(Washing_Equipment&& obj) = default;
		std::string _model;
		std::string _energyclass;
};

class Washing_Machine : public Washing_Equipment{
	public:
		Washing_Machine(std::string m,std::string ec,float c,unsigned int s):Washing_Equipment(m,ec),_capacity(c),_spin(s){};
		float getCapacity() const {return _capacity;};
		unsigned int getSpin() const { return _spin;};
		Washing_Machine* clone() { return new Washing_Machine(*this); }
		Washing_Machine& operator=(const Washing_Machine& obj) = delete;
	protected:
		const float _capacity;
		const unsigned int _spin;

};

class Clothes_Dryer : public Washing_Equipment{
	public:
		Clothes_Dryer(std::string m,std::string ec):Washing_Equipment(m,ec){}

	protected:
		Clothes_Dryer(const Clothes_Dryer&) = default;
   		Clothes_Dryer(Clothes_Dryer&&) = default;
   	private:
   	Clothes_Dryer& operator=(const Clothes_Dryer&) = delete;
};


class Condenser_Dryer : public Clothes_Dryer{
	public:
		Condenser_Dryer(std::string m, std::string ec, float c):Clothes_Dryer(m,ec),_capacity(c){};
		float getCapacity() const { return _capacity;};
		Condenser_Dryer* clone() { return new Condenser_Dryer(*this); }
	protected:
		Condenser_Dryer(const Condenser_Dryer&) = default;
   		Condenser_Dryer(Condenser_Dryer&&) = default;
	private:
		const float _capacity;
		Condenser_Dryer& operator=(const Condenser_Dryer& obj) = delete;
};

class Tumble_Dryer : public Clothes_Dryer{
	public:
		Tumble_Dryer* clone() { return new Tumble_Dryer(*this); }
		Tumble_Dryer(std::string m,std::string ec):Clothes_Dryer(m,ec){};
	protected:
		Tumble_Dryer(const Tumble_Dryer&) = default;
   		Tumble_Dryer(Tumble_Dryer&&) = default;
   	private:
   		Tumble_Dryer& operator=(const Tumble_Dryer& obj) = delete;
		
};

class Dish_Washer : public Washing_Equipment{
	public:
		Dish_Washer(std::string m,std::string ec,int c,int nl):Washing_Equipment(m,ec),_capacity(c),_noiselevel(nl){};
		int getCapacity() const { return _capacity;};
		unsigned int getNoiseLevel() { return _noiselevel;};
		Dish_Washer* clone() { return new Dish_Washer(*this); }
	private:
		const int _capacity;
		const unsigned int _noiselevel;
	protected:
		Dish_Washer(const Dish_Washer&) = default;
   		Dish_Washer(Dish_Washer&&) = default;
};

void print(Washing_Equipment* p)
{
   // TODO:
   // Create a copy of the object the parameter p points to.
   //
	Washing_Equipment* we = p->clone();

	Washing_Machine* wm = dynamic_cast<Washing_Machine*>(we);
	Tumble_Dryer* td = dynamic_cast<Tumble_Dryer*>(we);
	Condenser_Dryer* cd = dynamic_cast<Condenser_Dryer*>(we);
	Dish_Washer* dw = dynamic_cast<Dish_Washer*>(we);

	std::cout << we->getModel() << ", ";
	if(wm)
		std::cout << "Washing_Machine: " << wm->getCapacity() << " kg, " << wm->getSpin() << " rpm, energy class "  << wm->getEnergyClass();
	if(td)
		std::cout << "Tumble dryer: " << "energy class "  << td->getEnergyClass();
	if(cd)
		std::cout << "Condenser Dryer: " << cd->getCapacity() << " kg, " << " energy class "  << cd->getEnergyClass();
	if(dw)
		std::cout << "Condenser Dryer: " << dw->getCapacity() << " settings, " << dw->getNoiseLevel() << " dB, energy class "  << dw->getEnergyClass();

	std::cout << std::endl;

	delete we;

   // Print data from the copy, as shown in these examples:
   //
   //   WE1486WM, Washing machine: 8 kg, 1400 rpm, energy class A+
   //   WE1809TD, Tumble dryer: energy class C
   //   WE6756CD, Condenser dryer: 7.50 kg, energy class B
   //   WE6570DW, Dish washer: 12 settings, 47 dB, energy class A
   //
   // Destroy the copy
}

int main()
{
   Washing_Equipment* p_washing_machine  = new Washing_Machine("WE1486WM", "A+", 8.0, 1400);
   Washing_Equipment* p_condenser_dryer  = new Condenser_Dryer("WE6756CD", "B", 7.5);
   Washing_Equipment* p_tumble_dryer     = new Tumble_Dryer("WE1809TD", "C");
   Washing_Equipment* p_dish_washer      = new Dish_Washer("WE6570DW", "A", 12, 47);

   print(p_washing_machine);
   print(p_condenser_dryer);
   print(p_tumble_dryer);
   print(p_dish_washer);

   delete p_washing_machine;
   delete p_condenser_dryer;
   delete p_tumble_dryer;
   delete p_dish_washer;

   // TODO: destroy the objects created above

   return 0;
}
