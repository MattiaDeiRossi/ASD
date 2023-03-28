#include <vector>
#include <iostream>
#include <algorithm>


/*
* max = A[i]
* min = A[i+1]
* max – min < n
* A[i] - A[i+1] < n
*/ 
using namespace std;
void printVect(vector<int>& arr){
    cout<<"PRINT VECTOR"<< endl;
    for (int a : arr){
        cout<< a << endl;
    }
}

void sortDiff(vector<int>& arr){
    int min_index = 0;
    int max_index = arr.size()-1;
    vector<int> newArr;

    while(min_index < max_index){
        newArr.push_back(arr.at(min_index++));
        newArr.push_back(arr.at(max_index--));
    }

    if(min_index == max_index)
        newArr.push_back(arr.at(max_index));

    arr = newArr;

}

int getMin(vector<int>& arr){
    return *std::min(arr.begin(), arr.end());
}

int getMax(vector<int>& arr){
    return *max_element(arr.begin(), arr.end());
}

bool checker(vector<int>& arr){
    // |A[i] – A[i+1]| ≥ |A[i+1]−A[i+2]|
    for (int i = 0; i < arr.size()-2; i++)
    {
        if(! (abs(arr[i] - arr[i+1]) >= abs(arr[i+1]-arr[i+2])) ){
            return false;
        }
    }

    return true;
    
}

void countSort(vector<int>& array) {
  // The size of count must be at least the (max+1) but
  // we cannot assign declare it as int count(max+1) in C++ as
  // it does not support dynamic memory allocation.
  // So, its size is provided statically.
  int max = getMax(array);
  int output[max];
  int count[max];
  int size = array.size();
  

  // Initialize count array with all zeros.
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Store the count of each element
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  // Store the cummulative count of each array
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  // Copy the sorted elements into original array
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

void differenze(vector<int>& arr){
    countSort(arr);
    sortDiff(arr);
}
void differenzeSottoCondizione(vector<int>& arr){
    differenze(arr);
}


int main(){
    {
        std::vector<int> a = {17,14,12,16,19,11};
        printVect(a);
        differenzeSottoCondizione(a);
        printVect(a);
        cout << "checker: " <<checker(a) << endl;
    }
}