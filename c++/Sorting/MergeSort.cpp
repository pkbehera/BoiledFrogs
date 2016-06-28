  #include <stdio.h>
  #include <iostream>
  using namespace std;

  /*Merges 2 sorted arrays left (of size l) and right (of size r) into a
  resultant sorted array, data[]*/
  void merge(int left[], int l, int right[], int r, int data[], bool asc) {
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < l && j < r) {
      if (asc) {
        if (left[i] < right[j]) {
          data[k++] = left[i++];
        } else {
          data[k++] = right[j++];
        }
    } else {
        if (left[i] > right[j]) {
          data[k++] = left[i++];
        } else {
          data[k++] = right[j++];
        }
      }
    }
    while (i < l) {
      data[k++] = left[i++];
    }
    while (j < r) {
      data[k++] = right[j++];
    }
   }

  /*Sorts an array data[] of length len*/
  void sort (int data[], int len, bool asc) {
    if (len == 1) {
      return;
    }
    int l = len / 2;
    int r = len - l;
    int left[l];
    int right[r];
    for (int i = 0; i < l; i++) {
      left[i] = data[i];
    }
    for (int i = 0; i < r; i++) {
      right[i] = data[l + i];
    }
    sort(left, l, asc);
    sort(right, r, asc);
    merge(left, l, right, r, data, asc);
  }

  void print(int data[], int len) {
    for (int i = 0; i < len; i++) {
      cout << data[i] << " ";
    }
    cout << endl;
  }

  int main(int argc, char const *argv[]) {
    int data[] = {9, 3, 5, 4, 6, 2, 1, 10, 7, 8, 20, 34, 22, 45, 12, 44, 13, 99, 14, 87};
    print(data, 20);
    sort(data, 20, false);
    print(data, 20);
    return 0;
  }
