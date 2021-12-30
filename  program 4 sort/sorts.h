/*
 * @Author: Hao Yang
 * @Date: 2021-11-26 14:14:54
 * @LastEditTime: 2021-12-03 14:31:06
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /342/sorts.h
 */

#ifndef SORTS_H_
#define SORTS_H_
#include <vector>
using namespace std;

void swap(int& a, int& b);
void BubbleSort(vector<int>& vec, int l,
                int size);  //
void InsertionSort(vector<int>& vec, int l,
                   int size);  //
void Merge(vector<int>& vec, int first, int mid, int last);
void MergeSort(vector<int>& vec, int first, int last);  //
int partition(vector<int>& vec, int low, int high);
void QuickSort(vector<int>& vec, int low, int high);  //
void ShellSort(vector<int>& vec, int l, int size);    // bug last one does not
                                                      // sort

void IterativeMergeSort(vector<int>& vec, int l, int r);  //
/**
 * @brief
 *
 * @param a
 * @param b
 */

void swap(int& a, int& b) {
  int tmp = a;
  a = b;
  b = tmp;
}

/**
 * @description:
 * @param {int} l
 * @param {int} size
 * @return {*}
 */
void BubbleSort(vector<int>& vec, int l, int size) {
  int i, j;
  for (i = l; i < (size + 1); i++) {
    for (j = 0; j < size - i; j++) {
      if (vec[j] > vec[j + 1]) {
        swap(vec[j], vec[j + 1]);
      }
    }
  }
}

/**
 * @description:
 * @param {int} l
 * @param {int} size
 * @return {*}
 */
void InsertionSort(vector<int>& vec, int k, int size) {
  for(int i =k+1; i<=size;i++){
      int size = vec[i];
      int j = i-1;
      while(j>=k &&vec[j]>size){
        vec[j+1]=vec[j];
        j=j-1;
      }
      vec[j+1]=size;
  }
}

/**
 * @description:
 * @param {int} low
 * @param {int} high
 * @return {*}
 */
int partition(vector<int>& vec, int low, int high) {
  int pivot = vec[high];
  int i = (low - 1);

  for (int j = low; j <= high; j++) {
    if (vec[j] < pivot) {
      i++;
      swap(vec[i], vec[j]);
    }
  }
  swap(vec[i + 1], vec[high]);
  return (i + 1);
}

/**
 * @description:
 * @param {int} low
 * @param {int} high
 * @return {*}
 */
void QuickSort(vector<int>& vec, int low, int high) {
  if (low < high) {
    int pi = partition(vec, low, high);
    QuickSort(vec, low, pi - 1);
    QuickSort(vec, pi + 1, high);
  }
}

/**
 * @description:
 * @param {int} first
 * @param {int} mid
 * @param {int} last
 * @return {*}
 */
void Merge(vector<int>& vec, int first, int mid, int last) {
  int size = last - first + 1;
  int* tmp_arr;
  tmp_arr = new int[size];
  int first1 = first;
  int last1 = mid;
  int first2 = mid + 1;
  int last2 = last;
  int index = 0;
  while ((first1 <= last1) && (first2 <= last2)) {
    if (vec[first1] < vec[first2]) {
      tmp_arr[index] = vec[first1];
      first1++;
    } else {
      tmp_arr[index] = vec[first2];
      first2++;
    }
    index++;
  }

  while (first1 <= last1) {
    tmp_arr[index] = vec[first1];
    first1++;
    index++;
  }
  while (first2 <= last2) {
    tmp_arr[index] = vec[first2];
    first2++;
    index++;
  }
  for (index = 0; index < size; index++) {
    vec[first] = tmp_arr[index];
    first++;
  }
  delete[] tmp_arr;
}

/**
 * @description:
 * @param {int} first
 * @param {int} last
 * @return {*}
 */
void MergeSort(vector<int>& vec, int first, int last) {
  if (first < last) {
    int mid = (first + last) / 2;
    MergeSort(vec, first, mid);
    MergeSort(vec, mid + 1, last);
    Merge(vec, first, mid, last);
  }
}

/**
 * @description:
 * @param {int} l
 * @param {int} size
 * @return {*}
 */
void ShellSort(vector<int>& vec, int l, int size) {
  size =size + 1;
  for (int gap = size / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < size; i += 1) {
      int tmp = vec[i];
      int j;
      for (j = i; j >= gap && vec[j - gap] > tmp; j -= gap) {
        vec[j] = vec[j - gap];
      }
      vec[j] = tmp;
    }
  }
}

/**
 * @description:
 * @param {int} l
 * @param {int} r
 * @return {*}
 */
void IterativeMergeSort(vector<int>& vec, int l, int r) {
  if (l < r) {
    int* temp = new int[r + 1];
    int vecLength = (r - l) + 1;
    int vecEnd = r + 1;
    int subSize = 1;
    int f1, f2, l1, l2;
    int index1, index2, tempIndex;

    for (tempIndex = 0; tempIndex < l; tempIndex++)
      temp[tempIndex] = vec[tempIndex];

    while (subSize < vecLength) {
      f1 = l;
      tempIndex = l;
      while ((f1 + subSize) < vecEnd) {
        f2 = f1 + subSize;
        l1 = f2 - 1;
        l2 = ((f2 + subSize - 1) < vecEnd) ? (f2 + subSize - 1) : (vecEnd - 1);

        for (index1 = f1, index2 = f2; index1 <= l1 && index2 <= l2;
             tempIndex++) {
          if (vec[index1] <= vec[index2])
            temp[tempIndex] = vec[index1++];
          else
            temp[tempIndex] = vec[index2++];
        }

        while (index1 <= l1) temp[tempIndex++] = vec[index1++];

        while (index2 <= l2) temp[tempIndex++] = vec[index2++];

        f1 = l2 + 1;
      }

      for (index1 = f1; tempIndex < vecEnd; index1++)
        temp[tempIndex++] = vec[index1];

      for (int i = l; i < vecEnd; i++) vec[i] = temp[i];

      subSize *= 2;
    }
  }
}

#endif