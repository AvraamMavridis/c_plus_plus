Copy file program6.cc from directory given_files to your working directory. There are some
instructions given in the file, especially regarding testing.
You are to define a polymorphic class hierarchy for representing different kind of rooms.
All room classes shall have an abstract class named Room as common base. Room shall have two
direct subclasses, named Office and Store_Room, and Office shall in turn have a direct subclass
named Executive_Office.
All room objects shall store a room identity string, such as “B3D:449”. When a new room object
is created its identity string shall be initialized, and thereafter never changed. There shall be a
member function get_id() returning the room identity string.
AnOffice object shall store the number of persons having the office room as their workplace. This
number shall initialized when a new Office object is created, if not explicitly given the default is 1
(one person). Office shall have member functions get_n_occupants() and set_n_occupants() for
accessing and modifying, respectively, the number of persons working in the office room.
AnExecutive_Office is an Office which is always occupied by only one person. The name of the
person is to be stored, as a string, and may be initialized when a new Executive_Office object is
created, but also left out until later. Executive_Office shall have member functions get_occupant()
and set_occupant(), for getting and setting, respectively, the name of the person using the
executive office room.
A Store_Room shall store itssize (the floor area) as a double. The size is always to be set when a
new Store_Room object is created, and thereafter never to be changed. Store_Room shall have a
member function get_size() for returning the store room size.
There shall also a member function use(), which shall return a string telling the use of a room, i.e.
“Office”, “Executive office”, or “Store room”, respectively.
Room objects are supposed to be created dynamically (new). There shall be no other publicway to
room objects besides the following polymorphic copy function:
• clone() shall create a copy of the object in question and return a pointer to the copy
clone() shall use the copy constructor to initialize the copy.
• assignment is not allowed at all
No other functions than those mentioned above are allowed!

Write a test program according to the instructions given in the given file program6.cc. Output shall
look as the following example shows:
Office B3D:450, used by 9 persons
Executive office B3D:449, used by Tommy Olsson
Store room B3D:510, size 40.5
Design with care – use C++ well – keep with the given specifications!