#ifndef __WWIII_H__
#define __WWIII_H__

/* A list of the intended main strategy types, currently used by the
 * strategy class to know how to react. Can this design be solved
 * better in C++? */



/* Let the following code know that Soldiers exist. */
class Soldier;


/* Represent the behaviour of a Soldier, right now only how it reacts
 * to enemy
 */
 using std::cout;
  using std::endl;

class Strategy
{
public:
  Strategy() {}
  virtual void react_to_enemy(Soldier const& s);
};

class DEFEND : public Strategy{
    public:
      DEFEND():Strategy(){};
      void react_to_enemy (Soldier const& s) override  { 
        Strategy::react_to_enemy(s);
        std::cout << "I'll never yield an inch!" << std::endl;
      }

};

class ATTACK : public Strategy{
    public:
      ATTACK():Strategy(){};
      void react_to_enemy (Soldier const& s) override  { 
        Strategy::react_to_enemy(s);
        cout << "Come on and I'll show you..." << endl;
      }

};

class HIDE : public Strategy{
    public:
      HIDE():Strategy(){};
      void react_to_enemy (Soldier const& s) override  { 
        Strategy::react_to_enemy(s);
        cout << "You'll never find me anyway." << endl;
      }

};

class RUN_FOR_IT : public Strategy{
    public:
      RUN_FOR_IT():Strategy(){};
      void react_to_enemy (Soldier const& s) override  { 
        Strategy::react_to_enemy(s);
        cout << "Uh-Oh.. It's getting too hot here..." << endl;
      }

};

class OUTWIT : public Strategy{
    public:
      OUTWIT():Strategy(){};
      void react_to_enemy (Soldier const& s) override  {
        Strategy::react_to_enemy(s); 
        cout << "Uh-Oh.. It's getting too hot here..." << endl;
      }

};


/* Represent one soldier. Right know we're just interested in the
 * service number that uniquely identify one soldier, and each
 * soldiers strategy - how he should behave.
 *
 * Of course a lot more details will be added at a later stage.
 */
class Soldier
{
public:
  /* Parameters for other properties added later on... */
  Soldier(int id, Strategy* s) : service_number(id), ai(s) {}
    
  void enemy_in_sight()
  {
    ai->react_to_enemy(*this);
  }

  int get_id() const { return service_number; }
  
private:
  /* If they start giving errors we'll need to implement them... */
  Soldier(Soldier&);
  Soldier& operator=(Soldier&);
  
  int service_number;
  Strategy* ai;
  
  /* Properties such as strength, brains, health, weapons will be
   * added here later on...
   */
};

#endif
