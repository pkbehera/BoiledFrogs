#include<stdlib.h>
#include<iostream>
using namespace std;
typedef unsigned long long int ulli;
typedef unsigned int ui;
//https://www.codechef.com/problems/FCTRL
int main(int argc, char const *argv[]) {
  ui t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    ui c = 0;
    while (n > 0) {
      ui r = n / 5;
      c += r;
      n = r;
    }
    cout << c << endl;
  }
  return 0;
}
