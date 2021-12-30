/*
 * @Author: Hao Yang
 * @Date: 2021-11-26 14:14:40
 * @LastEditTime: 2021-12-03 14:32:13
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /342/sorter.cpp
 */
/*
#include <iostream>
#include <vector>

#include "sorts.h"
using namespace std;
const int kMaxNum = 100;


int main(){
    vector<int> numbers;
    int size =0;
    cout << "How big of an array?";
    cin >> size;

    for(int i = 0; i< size; i++){
        numbers.push_back(rand() % kMaxNum);
    }
    for(int i = 0; i < size; i++){
        cout << numbers[i]<< " ";
    }
    cout << endl << endl;

    IterativeMergeSort(numbers, 0, numbers.size()-1);
    for (int i = 0; i<size; i++)
    {
        cout << numbers[i] << " ";
    }



    cout << endl;

}*/

#include <sys/time.h>

#include <iostream>
#include <string>
#include <vector>

#include "sorts.h"
//#include <windows.h>
using namespace std;

void InitVector(vector<int>& item_vector, int size);
void PrintVector(const vector<int>& item_vector, string name);

int main(int argc, char* argv[]) {
  int size = 0;
  string sort_name = "";
  bool print_out = true;

  if ((argc != 3) && (argc != 4)) {
    cerr << "Usage: Sorter SORT_TYPE VECTOR_SIZE [YES|NO]" << endl;
    return -1;
  }

  sort_name = string(argv[1]);
  size = atoi(argv[2]);

  if (size <= 0) {
    cerr << "Vector size must be positive" << endl;
    return -1;
  }
  if (argc == 4) {
    string print_arr = string(argv[3]);
    if (print_arr == "NO") {
      print_out = false;
    } else if (print_arr == "YES") {
      print_out = true;
    } else {
      cerr << "Usage: Sorter SORT_TYPE VECTOR_SIZE [YES|NO]" << endl;
      return -1;
    }
  }

  srand(1);
  vector<int> items(size);
  InitVector(items, size);

  if (print_out) {
    cout << "Initial:" << endl;
    PrintVector(items, string("items"));
  }
  // GetTickCout is windows specific.
  // For linux use gettimeofday.  As shown::
  struct timeval startTime, endTime;
  gettimeofday(&startTime, NULL);
  // int begin = GetTickCount();

  //
  // PLACE YOUR CODE HERE
  //   ...Determine which sort to call on the vector
  //   ...The code below only looks for QuickSort
  // Other Signatures:
  //  BubbleSort(items, 0, size - 1)
  //  InsertionSort(items, 0, size – 1)
  //  MergeSort(items, 0, size – 1)
  //  IterativeMergeSort(items, 0, size – 1)
  //  ShellSort(items, 0, size – 1)
  // PLACE YOUR CODE HERE;  for instance:

  if (sort_name == "InsertionSort") {

    InsertionSort(items, 0, size - 1);
  }
  // int end = GetTickCount();
  // Linux timer:
  gettimeofday(&endTime, NULL);

  if (print_out) {
    cout << "Sorted:" << endl;
    PrintVector(items, string("item"));
  }

  // int elapsed_secs = end - begin;
  // int elapsed_secs = &endTime - &startTime;
  cout << "Time: "
       << (endTime.tv_sec - startTime.tv_sec) +
              1e-6 * (endTime.tv_usec - startTime.tv_usec)
       << "sec" << endl;
  // cout << "Time (ms): " << elapsed_secs << endl;
  return 0;
}

void InitVector(vector<int>& item_vector, int rand_max) {
  if (rand_max < 0) {
    return;
  }
  vector<int> pool(rand_max);
  for (int i = 0; i < rand_max; i++) {
    pool[i] = i;
  }

  int spot;
  for (int i = 0; i < rand_max; i++) {
    spot = rand() % (pool.size());
    item_vector[i] = pool[spot];
    pool.erase(pool.begin() + spot);
  }
}

void PrintVector(const vector<int>& item_vector, string name) {
  int size = item_vector.size();

  for (int i = 0; i < size; i++)
    cout << name << "[" << i << "] = " << item_vector[i] << endl;
}

// Function to calculate elapsed time if using gettimeofday (linux)

int elapsed(timeval& startTime, timeval& endTime) {
  return (endTime.tv_sec - startTime.tv_sec) * 1000000 +
         (endTime.tv_usec - startTime.tv_usec);
}
