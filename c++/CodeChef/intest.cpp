#include<stdlib.h>
#include<iostream>
using namespace std;
//https://www.codechef.com/problems/INTEST
int main(int argc, char const *argv[]) {
  unsigned int n, k, t, c = 0;
  cin >> n;
  cin >> k;
  while (n--) {
    cin >> t;
    if (t % k == 0) {
      c++;
    }
  }
  cout << c << endl;
  return 0;
}
