//Tower of Hanoi - Recursive solution
#include <iostream>
#include <stdlib.h>
using namespace std;

void toh(int n, const char* from, const char* to, const char* aux) {
  static int step = 0;
  if (step == 0 && n < 1) {
    cout << "Number of disks should be 1 or more" << endl;
    return;
  }
  if (n > 0) {
    toh(n - 1, from, aux, to);
    cout << "Step # " << ++step << ": Move disk " << n << " from " << from << " to " << to << endl;
    toh(n - 1, aux, to, from);
  }
}

int main(int argc, char const *argv[]) {
  cout << "Number of disks: ";
  int n;
  cin >> n;
  toh(n, "S", "D", "A");
  return 0;
}
