#include <iostream>
#include <vector>

/* Se comments i the header file too... */
#include "wwiii.h"

/*
 * Use C++ inheritance an polymorphism to create a more elegant
 * implementation of the different strategies.
 */

void Strategy::react_to_enemy(Soldier const& s)
{
  using std::cout;
  using std::cerr;
  using std::endl;
  
  /* This switch will grow really big when more strategies is added
   * with their complete implementetion. For now just have a placeholde
   * implementation.
   */
  cout << "Soldier " << s.get_id() << ": ";

}


/* A small test program for the classes.
 */
int main()
{
  const unsigned SIZE = 13;
  Soldier* army[SIZE];
  unsigned n = 0;
  int j = 1;
  
  army[n++] = new Soldier(j++, new DEFEND());
  army[n++] = new Soldier(j++, new OUTWIT());
  army[n++] = new Soldier(j++, new HIDE());
  army[n++] = new Soldier(j++, new RUN_FOR_IT());
  army[n++] = new Soldier(j++, new ATTACK());
  army[n++] = new Soldier(j++, new OUTWIT());
  army[n++] = new Soldier(j++, new HIDE());
  army[n++] = new Soldier(j++, new OUTWIT());
  army[n++] = new Soldier(j++, new RUN_FOR_IT());
  army[n++] = new Soldier(j++, new RUN_FOR_IT());
  army[n++] = new Soldier(j++, new DEFEND());
  army[n++] = new Soldier(j++, new HIDE());
  army[n++] = new Soldier(j++, new ATTACK());

  if (n > SIZE)
  {
    std::cerr << "ERROR: Army array is too small!" << std::endl;
    return 1;
  }
  
  for ( unsigned i = 0; i < n; ++i )
  {
    army[i]->enemy_in_sight();
  }
  
  for ( unsigned i = 0; i < n; ++i )
  {
    delete army[i];
  }
  
  return 0;
}
