#ifndef MY_MATRIX_H
#define MY_MATRIX_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Vector{
public:
   Vector() { }
   Vector(size_t n, double x = 0) {
      _vec.resize(n, x);
   }
   ~Vector() { }

   double& operator[] (size_t i) { return _vec[i]; }
   const double& operator[] (size_t i) const { return _vec[i]; }
   
   double operator* (const Vector& v) {
      double x;
      for(size_t i = 0, n = _vec.size(); i < n; ++i)
         x = x + _vec[i]*v[i];
      return x;
   }
   Vector operator+ (const Vector& v) {
      size_t n;   n = _vec.size();
      Vector x(n);    
      for(size_t i = 0; i < n; ++i)
         x[i] = _vec[i] + v[i];
      return x;
   } 
   Vector operator- (const Vector& v) {
      size_t n;   n = _vec.size();
      Vector x(n);    
      for(size_t i = 0; i < n; ++i)
         x[i] = _vec[i] - v[i];
      return x;
   }

   size_t size() const { return _vec.size(); }
private:
   vector<double> _vec;
};

class dnMatrix{
public:
   dnMatrix() { 
      _val.resize(3, Vector(3));
      for(size_t i = 0; i < 3; ++i)          
         _val[i][i] = 1; 
   }
   dnMatrix(const string& name) {
      ifstream fin;   fin.open(name);
      if(fin.is_open()) {
         size_t m, n;
         string str;
         stringstream ss;
         ss >> m >> n; 
      }
   }
   ~dnMatrix() { }

   const Vector& operator[] (size_t i) const { return _val[i]; }

   void print() const {
      for(auto it = _val.begin(); it != _val.end(); ++it) {
         for(size_t i = 0, n = it->size(); i < n; ++i)
            cout << (*it)[i] << ' ';
         cout << endl;
      } 
   }
private:
   vector<Vector> _val;
};

class spMatrix {
public:
   spMatrix() { }
   spMatrix(const string& name) {
      ifstream fin;   fin.open(name);
      if(fin.is_open()) {
         double v;
         size_t c, r;
         string str;
         stringstream ss;
         while(getline(fin, str)) {
            ss.str(""); ss.clear();
            ss << str;  
         }
      }
      fin.close();
   }
   ~spMatrix() { }

   void print() const {
      cout << "values:" << endl << ' ';   
      for(vector<double>::const_iterator it = _val.begin(); it != _val.end(); ++it)
         cout << (*it) << ' ';
      cout << "columns:" << endl << ' ';
      for(vector<size_t>::const_iterator it = _col.begin(); it != _col.end(); ++it)
         cout << (*it) << ' ';
      cout << "rows: " << endl << ' ';
      for(vector<size_t>::const_iterator it = _row.begin(); it != _row.end(); ++it)
         cout << (*it) << ' ';
   }
private:
   vector<double> _val; 
   vector<size_t> _col, _row;
};

#endif
