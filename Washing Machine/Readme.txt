Copy the file named program6.cc to your working directory.
Design a polymorphic class hierarchy for representing washing equipment (washing machines,
clothes dryers, dish washers, etc.). The following classes shall be defined:
• Washing_Equipmentshall be a common abstract base for all classes. All washing equipments
have a model code (e.g. WE1486WM) and an energy class(A+++, A++, A+, A, B, C).
• Washing_Machine is a direct concrete subclass of Washing_Equipment. Washing machines
also have capacity (kg,float) and spin (rpm; a non-negative integer value).
• Clothes_Dryer is a direct subclass to Washing_Equipment, and a common abstract base for
concrete clothes dryer classes. No specific data is associated with this class.
• Condenser_Dryer is a concrete kind of clothes dryer. Besides model and energy class,
condenser dryers also have capacity (kg; float).
• Tumble_Dryer is another kind of concrete clothes dryer. No specific data associated is with this
class.
• Dish_Washer is a direct concrete subclass of Washing_Equipment. Dish washers also have
capacity (number of settings; some positive integer value), and noise level (dB; a non-negative
integer value).
All data members shall be initialized at object creation, and thereafter never to be modified.
Besides functionality related to object creation and destruction there shall be a
• get function for each data member
Washing equipment objects are supposed to be created dynamically (new). There shall be no other
public way to copy washing equipment objects besides the following polymorphic copy function:
• clone() shall create a copy of the object in question and return a pointer to the copy
clone() shall use the copy constructor to initialize the copy.
• assignment is not allowed at all
No other functions than those mentioned above are allowed!
Write a test program according to the comments in the given file program6.cc.