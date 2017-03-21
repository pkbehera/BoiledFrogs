#include<stdlib.h>
#include<iostream>
using namespace std;
typedef unsigned int ui;

//https://www.codechef.com/problems/FCTRL2
void print(ui* res, ui len) {
  bool p = false;
  while (len--) {
    if (p == false && res[len] > 0) {
      p = true;
    }
    if (p) {
      cout << res[len];
    }
  }
  cout << endl;
}

void mult(ui* res, ui len, ui n) {
  while (n > 0) {
    ui r = n % 10;
    n /= 10;
  }

  ui res[] = new ui[200];
  for (ui i = 0; i < 200; i++) {
    res[i] = 0;
  }
  ui c = 0;
  for (ui i = 0, ui < 200; i++) {
    res[i] = c + res[i] * n;
    c = res[i] / 10;
    res[i] = res[i] % 10;
  }
}

int main(int argc, char const *argv[]) {
  ui res[200];
  for (ui i = 1; i < 200; i++) {
    res[i] = 0;
  }
  res[0] = 1;

  ui t, n;
  cin >> t;
  while(t--) {
    cin >> n;
    while (n--) {
      mult(res, 200, n);
    }
    print(res, 200);
  }
  return 0;
}
