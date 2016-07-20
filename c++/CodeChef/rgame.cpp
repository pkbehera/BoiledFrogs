#include <stdlib.h>
#include <iostream>
using namespace std;

/*
  A0
    A0 A1                               : A0*A1
      A0 A1 A2                          : A1*A2
        A0 A1 A2 A3                     : A2*A3
          A0 A1 A2 A3 A4                : A3*A4
          A4 A0 A1 A2 A3                : A0*A4
        A3 A0 A1 A2                     : A0*A3
          A3 A0 A1 A2 A4                : A2*A4
          A4 A3 A0 A1 A2                : A3*A4
      A2 A0 A1                          : A0*A2
        A2 A0 A1 A3                     : A1*A3
          A2 A0 A1 A3 A4                : A3*A4
          A4 A2 A0 A1 A3                : A2*A4
        A3 A2 A0 A1                     : A2*A3
          A3 A2 A0 A1 A4                : A1*A4
          A4 A3 A2 A0 A1                : A3*A4
    A1 A0                               : A0*A1
      A1 A0 A2                          : A0*A2
        A1 A0 A2 A3                     : A2*A3
          A1 A0 A2 A3 A4                : A3*A4
          A4 A1 A0 A2 A3                : A1*A4
        A3 A1 A0 A2                     : A1*A3
          A3 A1 A0 A2 A4                : A2*A4
          A4 A3 A1 A0 A2                : A3*A4
      A2 A1 A0                          : A1*A2
        A2 A1 A0 A3                     : A0*A3
          A2 A1 A0 A3 A4                : A3*A4
          A4 A2 A1 A0 A3                : A2*A4
        A3 A2 A1 A0                     : A2*A3
          A3 A2 A1 A0 A4                : A0*A4
          A4 A3 A2 A1 A0                : A3*A4

score = 0, mul = 2*A0
  2*A0*A1 score = 2*score + mul * A1, mul += pow2(1)*A1
  2*A0*A1 + (2*A1 + 2*A0)*A2 score = 2*score + mul*A2, mul += pow2(2)*A2
  2*A0*A1 + (2*A1 + 2*A0)*A2 + (2*A0 + 2*A1 + 4*A2)*A3 mul = mul + pow2(3)*A3
  2*A0*A1 + (2*A1 + 2*A0)*A2 + (2*A0 + 2*A1 + 4*A2)*A3 + (2*A0 + 2*A1 + 4*A2 + 8*A3)*A4
*/

//Constraints:
//1 ≤ T ≤ 10
//1 ≤ N ≤ 10^5
//1 ≤ Ai ≤ 10^9

typedef unsigned long long int ulli;
typedef unsigned int ui;

//modulo 10^9 + 7
//https://www.quora.com/What-exactly-is-print-it-modulo-10-9-+-7-in-competitive-programming-websites
ui modulo(ulli input) {
  const unsigned int M = 1000000007;
  return input % M;
}

int main(int argc, char const *argv[]) {
  const int nLimit = 100000;
  ui pow2[nLimit];
  pow2[0] = 1;
  for (int i = 1; i < nLimit; i++) {
    pow2[i] = modulo(pow2[i - 1] << 1);
  }

  int T;
  cin >> T;
  int t = T;
  while (t--) {
    int N;
    cin >> N;
    ulli Ai;
    cin >> Ai; //scanned A0
    ui mul = modulo(2 * Ai);
    ui score = 0;
    for (int i = 1; i <= N; i++) {
      cin >> Ai;
      score = modulo(modulo(2 * score) + modulo(mul * Ai));
      mul = modulo(mul + modulo(pow2[i] * Ai));
    }
    cout << score << endl;
  }
  return 0;
}
