#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void reverse(char* str) {
  size_t l = strlen(str);
  //If strlen can not be used
  /*while (str[l] != '\0') {
    l++;
  }*/
  for (size_t i = 0; i < l / 2; i++) {
    char t = str[i];
    str[i] = str[l - 1 - i];
    str[l - 1 - i] = t;
  }
}

void append(const char* src, char* dest, size_t start, size_t end) {
  size_t di = strlen(dest);
  for (size_t i = start; i <= end; i++) {
    dest[di++] = src[i];
  }
  dest[di] = '\0';
}

void reverseWords(const char* str, char* dest) {
  int l = strlen(str);
  int e = l - 1;
  for (int i = e; i >= 0; i--) {
    if (str[i] == ' ') {
      append(str, dest, i + 1, e);
      size_t s = strlen(dest);
      dest[s] = str[i];
      dest[s + 1] = '\0';
      e = i - 1;
    }
  }
  append(str, dest, 0, e);
}

//Example palindromes: noon, level, rotor, civic, radar, kayak, madam
bool palindrome(const char* str) {
  size_t len = strlen(str);
  for (size_t i = 0; i < len / 2; i++) {
    if (str[i] != str[len - 1 - i]) {
      return false;
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  if (argv[1] != NULL) {
    cout << "Palindrome: " << boolalpha << palindrome(argv[1]) << endl;
    reverse(argv[1]);
    cout << "Reversed: " << argv[1] << endl;
    reverse(argv[1]); //Get the original
    char* newStr = new char[strlen(argv[1])];
    newStr[0] = '\0';
    reverseWords(argv[1], newStr);
    cout << "Reversed Words: " << newStr << endl;
    delete[] newStr;
  } else {
    cout << "No input to reverse words!" << endl;
    exit(1) ;
  }
  return 0;
}
