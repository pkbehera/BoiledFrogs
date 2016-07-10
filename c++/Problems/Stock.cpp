#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/*Suppose we could access yesterday's stock prices as an array, where:

The indices are the time in minutes past trade opening time, which was 9:30 am.
The values are the price in dollars of a stock at that time.
So if the stock cost $500 at 10:30 am, prices[60] = 500.

Write a function that takes prices and returns the best profit that could have
made made from 1 purchase and 1 sale of 1 unit of stock yesterday.

For example:
  int[] prices = new int[]{10, 7, 5, 8, 11, 9};

MaxProfit(prices);
// returns 6 (buying for $5 and selling for $11)

No "shorting"—you must buy before you sell. You may not buy and sell in the
same time step (at least 1 minute must pass). */

//Replaces a with max(a, b)
void max(int& a, const int b) {
  if (b > a) {
    a = b;
  }
}

//Complexity: O(n), but 2 for loops
int maxProfit1(const int* prices, const int len) {
  int mi = 1;
  int max = prices[mi];
  int min = prices[0];
  for (int i = 2; i < len; i++) {
    if (prices[i] > max) {
      mi = i;
      max = prices[mi];
    }
  }
  for (int i = 1; i < mi; i++) {
    if (prices[i] < min) {
      min = prices[i];
    }
  }
  return max - min;
}

//Complexity: O(n), one for loop in backward direction
int maxProfit(const int* prices, const int len) {
  int maxProfit = 0 - prices[len - 1];
  int maxPrice = prices[len - 1];
  for (int i = len - 2; i >= 0; i--) {
    max(maxProfit, maxPrice - prices[i] );
    max(maxPrice, prices[i]);
  }
  return maxProfit;
}

int main(int argc, char const *argv[]) {
  cout << "Number of entries: ";
  int cnt;
  cin >> cnt;
  int* data = new int[cnt];
  for (int i = 0; i < cnt; i++) {
    cout << i << "th entry: ";
    cin >> data[i];
  }
  cout << "Maximum profit: " << maxProfit(data, cnt) << endl;
  cout << "Maximum profit: " << maxProfit1(data, cnt) << endl;
  delete[] data;
  return 0;
}
