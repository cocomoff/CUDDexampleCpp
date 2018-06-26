#include <iostream>
#include <random>
#include <vector>
#include "cuddObj.hh"

using namespace std;

int main() {
  Cudd mgr;
  
  // 乱数生成機
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> bin(0, 1);

  // 桁数4 (= 変数の個数)
  const int N = 4;
  vector<BDD> X(N);
  for (int i = 0; i < N; i++)
    X[i] = mgr.bddVar();

  BDD f = mgr.bddZero();
  for (int i = 0; i < (1 << N); i++) {
    int bj = bin(mt);
    if (bj == 1) {
      BDD termi = mgr.bddOne();
      for (int k = 0; k < N; k++)
        termi &= (i & (1 << k)) ? X[k] : !X[k];
      f |= termi;
    }
  }

  // dot dump
  const vector<ADD> vec = {f.Add()};
  auto fp = fopen("dot/random.dot", "w");
  const char* iname[4] = {"x1", "x2", "x3", "x4"};
  const char* oname[1] = {"F"};
  mgr.DumpDot(vec, iname, oname, fp);
  return 0;
}
