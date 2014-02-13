/*
 * program6.cc    
 */
#include <vector>
#include <string>
#include <iostream>
#include <iterator>

// Note: namespace std is NOT to be opened yet!

// Define the room classes here

 class Room{
   public:
      Room(std::string id):id_(id){};
      virtual ~Room(){};
      virtual std::string getId() const { return id_;};
      virtual std::string use() const = 0;
      virtual Room* clone() = 0;
   protected:
      Room(const Room& obj) = default;
      Room& operator=(const Room& obj) = default;
      const std::string id_;
 };

 class Office : public Room{
   public:
      Office(std::string id, unsigned int n=1):Room(id),occupants_(n){};
      virtual ~Office(){};
      unsigned int get_n_occupants() const { return occupants_;};
      void set_n_occupants(unsigned int n){ occupants_=n;};
      std::string use() const override { return "Office";};
      virtual Office* clone() { return new Office(*this);};
   protected:
      Office(const Office& obj) = default;
      Office& operator=(const Office& obj) = default;
      unsigned int occupants_;
 };

 class Store_Room : public Room{
   public:
      Store_Room(std::string id,double size):Room(id),size_(size){};
      virtual ~Store_Room(){};
      double get_size() { return size_;};
      std::string use() const override { return "Store Room";};
      virtual Store_Room* clone(){ return new Store_Room(*this);};
   protected:
      Store_Room(const Store_Room& obj) = default;
      Store_Room& operator=(const Store_Room& obj) = default;
   private:
      const double size_;
 };

 class Executive_Office : public Office{
   public:
      Executive_Office(std::string id,std::string name=""):Office(id),personname_(name){};
      virtual ~Executive_Office(){};
      std::string get_occupant() const { return personname_;};
      void set_n_occupant(std::string name){ personname_ = name;};
      std::string use() const override { return "Executive Office";};
      virtual Executive_Office* clone() { return new Executive_Office(*this);};
   protected:
      Executive_Office(const Executive_Office& obj) = default;
      Executive_Office& operator=(const Executive_Office& obj) = default;
   private:
      std::string personname_;
 };

int main()
{
   // Namespace std shall not be opened until now!
   using namespace std;

   Office p("102dsa",100);
   Office* k = p.clone();

   

   // Don't introduce any utility functions to do the following,
   // code straight forward according to the instructions!

   // Use a std::vector for storing pointers to room objects.
   // Create dynamically one of each of the concrete room classes
   // and store pointers to the objects in the vector.

   // Iterate over the vector, and for each room object 
   // * copy the object, and output the following for the copy:
   //   - use and identity and also, on the same line
   //   - if a store room, its size
   //   - if an office, the number of occupants
   //   - if an executive office, the name of the occupant
   // * delete the copy

   // Iterate over the vector, delete all room objects and set the
   // pointers in the vector to nullptr.

   std::vector<Room*> rooms{new Office("B3D:450",9),new Executive_Office("B3D:449","Tom Olsson"), new Store_Room("B3D:510",40.5)};

   for(std::vector<Room*>::iterator it=rooms.begin(); it!=rooms.end(); ++it){
      Room* p = (*it)->clone();
      Store_Room* sr = dynamic_cast<Store_Room*>(p);
      Executive_Office* exof = dynamic_cast<Executive_Office*>(p);
      Office* of = dynamic_cast<Office*>(p);
      if(sr)
        std::cout << "Store Room " << sr->getId() << ", size" << sr->get_size() << std::endl;
      else if(exof)
         std::cout << "Office " << exof->getId() << ", used by " << exof->get_occupant() << " people" << std::endl;
      else if(of)
         std::cout << "Office " << of->getId() << ", used by " << of->get_n_occupants() << " people" << std::endl;
   }

   return 0;
}

