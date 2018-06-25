#include <iostream>
#include "cuddObj.hh"

using namespace std;

int main() {
  Cudd mgr;
  BDD x = mgr.bddVar();
  BDD y = mgr.bddVar();
  BDD f = x * y;
  BDD g = y +!x;
  cout << "f is" << (f <= g ? "" : " not")
       << " less than or equal to g" << endl;
  return 0;
}
