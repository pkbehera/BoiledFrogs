#include <stdlib.h>
#include <iostream>
using namespace std;
//https://www.codechef.com/problems/TEST
int main(int argc, char const *argv[]) {
  int a;
  while (true) {
    cin >> a;
    if (a == 42) {
      return 0;
    }
    cout << a << endl;
  }
  return 0;
}
