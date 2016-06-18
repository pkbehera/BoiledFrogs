//Tower of Hanoi - Recursive solution
#include <iostream>
#include <stdlib.h>

void toh(int n, const char* from, const char* to, const char* aux) {
  if (n < 1) {
    std::cout << "Number of disks should be 1 or more" << std::endl;
    return;
  }
  if (n > 1) {
    toh(n - 1, from, aux, to);
    std::cout << "move disk " << n << " from " << from << " to " << to << std::endl;
    toh(n - 1, aux, to, from);
  } else {
    std::cout << "move disk " << n << " from " << from << " to " << to << std::endl;
  }
}

int main(int argc, char const *argv[]) {
  toh(4, "F", "T", "A");
  return 0;
}
