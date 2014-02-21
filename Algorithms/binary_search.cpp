#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int binary_search(int A[], int key, int imin, int imax)
{
  // test if array is empty
  if (imax < imin)
    // set is empty, so return value showing not found
    return -1;
  else
    {
      // calculate midpoint to cut set in half
      int imid = (imax+imin)/2;
 
      // three-way comparison
      if (A[imid] > key)
        // key is in lower subset
        return binary_search(A, key, imin, imid-1);
      else if (A[imid] < key)
        // key is in upper subset
        return binary_search(A, key, imid+1, imax);
      else
        // key has been found
        return imid;
    }
}

int binary_search_vector(std::vector<int>& A,int key,std::vector<int>::iterator begin, std::vector<int>::iterator end){
	// test if array is empty
	int imax = std::distance(begin,end);
	int imin = std::distance(A.begin(),begin);
  if (imax < imin)
    // set is empty, so return value showing not found
    return -1;
  else
    {
      // calculate midpoint to cut set in half
      int imid = (imax-imin)/2;
 	  std::cout << imid << std::endl;
      // three-way comparison
      if (A[imid] > key)
        // key is in lower subset
        return binary_search_vector(A, key, (A.begin()+imin), (A.begin()+imid-1));
      else if (A[imid] < key)
        // key is in upper subset
        return binary_search_vector(A, key, (A.begin()+imid+1), (A.begin()+imax));
      else
        // key has been found
        return imid;
    }

}

int main(){
	int A[] = {1,2,3,4,5,6,7,8};
	int element;
	std::cin >> element;
	std::cout << binary_search(A,element,0,7) << std::endl;
	std::vector<int> B(10);
	std::iota(B.begin(),B.end(),0);
	int el;
	std::cin >> el,
	std::cout << binary_search_vector(B,el,B.begin(),B.end());

}