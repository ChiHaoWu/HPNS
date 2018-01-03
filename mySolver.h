#include <vector>
#include <math.h>
#include "myMatrix.h"

double
norm(Vector v)
{
   return sqrt(v*v);
}

bool
jacobi(const dnMatrix& a, Vector& b)
{
   size_t n = b.size();
   Vector init(n);
   //while(norm(a*x - b) > pow(10, -5)) {
   // 
   //} 
   return true;
}
