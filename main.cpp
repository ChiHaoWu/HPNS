#include <iostream>
#include "myMatrix.h"
#include "mySolver.h"
#include "myUtil.h"

using namespace std;

int main() {
   dnMatrix a(4);   
   for(size_t i = 0; i < 4; ++i)
      a[i][i] = i+1; 
   cout << "a:" << endl;
   print(a); 

   Vector v(4);
   for(size_t i = 0; i < 4; ++i)
      v[i] = (i+1)*(i+1);
   cout << "v:" << endl;
   print(v);
   cout << "a*v:" << endl;
   print(a*v);
   jacobi(a, v);
}
