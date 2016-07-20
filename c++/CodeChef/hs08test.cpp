#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;
//https://www.codechef.com/problems/HS08TEST
int main(int argc, char const *argv[]) {
  //0 < X <= 2000
  int x;
  cin >> x;
  //0<= Y <= 2000
  double y;
  cin >> y;
  if (x < y && x % 5 == 0 && x + 0.5 <= y) {
    y = y - x - 0.5;
  }
  cout << fixed << setprecision(2) << y << endl;
  return 0;
}
