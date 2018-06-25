#include <iostream>
#include <vector>
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

  // example
  auto size = mgr.ReadSize();
  cout << size << endl;

  // dump
  const vector<BDD> vec1 = {f};
  const vector<BDD> vec2 = {f, g};
  auto fp1 = fopen("output1.dot", "w");
  auto fp2 = fopen("output2.dot", "w");
  mgr.DumpDot(vec1, NULL, NULL, fp1);
  mgr.DumpDot(vec2, NULL, NULL, fp2);
  return 0;
}
