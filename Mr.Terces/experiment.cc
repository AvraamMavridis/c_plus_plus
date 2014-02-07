#include <iostream>

using namespace std;

class DataItem{
  public:
        DataItem(int v=0,int o=0):_value(v),_order(o){};
        ~DataItem(){};
        int getValue() const { return _value;};
        int getOrder() const { return _order;};
  private:
    int _value;
    int _order;
};

void bubble_sort(DataItem *array[], int size)
{
  for (int i = 1; i < size; ++i)
  {
    for (int j = size - 1; j >= i; --j)
    {
      if (array[j-1]->getValue() > array[j]->getValue())
      {
        DataItem* saveme = array[j-1];
        array[j-1] = array[ j ];
        array[ j ] = saveme;
      }
    }
  }
}

int binary_search(int value, DataItem* array[], int size)
{
  int upper_bound = size;
  int lower_bound = 0;

  while (lower_bound < upper_bound)
  {
    int middle = lower_bound + (upper_bound - lower_bound) / 2;
    
    if (array[middle]->getValue() > value)
    {
      upper_bound = middle;
    }
    else if (array[middle]->getValue() < value)
    {
      lower_bound = middle + 1;
    }
    else
    {
      return middle;
    }
  }
  return -1;
}

int main()
{
  DataItem* sorted[10];
  DataItem* ordered[10];

  int value;

  for (int i = 0; i < 10; ++i)
  {
    cin >> value;
    ordered[i] = new DataItem(value,i);
    sorted[i] = new DataItem(value,i);
  }

   bubble_sort(sorted, 10);

   for (int i = 0; i < 10; ++i)
   {
    cout << sorted[i]->getValue() << " ";
   }
   cout << endl;

   std::cout << "Give me a X number : " << std::endl;
   int X;
   std::cin >> X;

   int find = binary_search(X,sorted,10);
   for (int i = find+1; i < 10; ++i)
   {
    cout << sorted[i]->getValue() << " ";
   }

  for (int i = 0; i < 10; ++i){
    delete sorted[i];
    delete ordered[i];
  }
  
  return 0;
}
