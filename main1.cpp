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
  auto fp1 = fopen("dot/output1.dot", "w");
  auto fp2 = fopen("dot/output2.dot", "w");
  const char* iname[2] = {"x", "y"};
  const char* oname[2] = {"f", "g"};
  mgr.DumpDot(vec1, iname, oname, fp1);
  mgr.DumpDot(vec2, iname, oname, fp2);

  // cleaned dump
  const vector<ADD> vec3 = {f.Add(), g.Add()};
  auto fp3 = fopen("dot/output3.dot", "w");
  mgr.DumpDot(vec3, iname, oname, fp3);
  return 0;
}
