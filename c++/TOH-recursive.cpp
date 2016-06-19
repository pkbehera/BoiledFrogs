//Tower of Hanoi - Recursive solution
#include <iostream>
#include <stdlib.h>

void toh(int n, const char* from, const char* to, const char* aux) {
  static int step = 0;
  if (step == 0 && n < 1) {
    std::cout << "Number of disks should be 1 or more" << std::endl;
    return;
  }
  if (n > 0) {
    toh(n - 1, from, aux, to);
    std::cout << "Step # " << ++step << ": Move disk " << n << " from " << from << " to " << to << std::endl;
    toh(n - 1, aux, to, from);
  }
}

int main(int argc, char const *argv[]) {
  std::cout << "Number of disks: ";
  int c;
  std::cin >> c;
  toh(c, "F", "T", "A");
  return 0;
}
