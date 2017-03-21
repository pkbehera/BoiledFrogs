#include <iostream>
#include <stdlib.h>
using namespace std;

int main (int argc, char** argv) {
	string name("world");
	if (argc > 1) {
		name = argv[1];
	}
	cout << "hello " << name << endl;
	return 0;
}
