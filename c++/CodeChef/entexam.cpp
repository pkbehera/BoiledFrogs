#include <stdlib.h>
#include <iostream>
using namespace std;
typedef unsigned int ui;

int main(int argc, char const *argv[]) {
  ui T;
  cin >> T;
  while (T--) {
    ui N, K, E, M;
    cin >> N >> K >> E >> M;
    N--;
    ui* top = new ui[K];
    ui sel = 0;
    while (N--) {
      ui tot;
      for (ui i = 0; i < E) {
        ui m;
        cin >> m;
        tot += m;
      }
    }
  }
  return 0;
}
