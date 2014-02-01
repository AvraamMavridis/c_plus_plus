/*
 * program6.cc
 */
#include <iostream>
using namespace std;

// Define washing equipment classes here

void print(Washing_Equipment* p)
{
   // TODO:
   // Create a copy of the object the parameter p points to.
   //
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

   // TODO: destroy the objects created above

   return 0;
}
