#include <stdio.h>
#include <iostream>
using namespace std;

//THESE MUST BE MEMORISED
int main(int argc, char const *argv[]) {
  //Print something on to the output stream
  cout << "Hello world " << "My age is " << 15 << endl;

  //Read an Input
  string str;
  //"Hello World" will be read as "Hello", anything after whitespace will not be read
  cin >> str;
  cout << "str: " << str << endl;

  //Entire line including whitespace will be read
  getline(cin, str);
  cout << "str: " << str << endl;

  int a, b;
  //12 14 will be read into a and b respectively
  cin >> a;
  cin >> b;
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  return 0;
}
