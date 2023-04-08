#include <vector>
#include <algorithm>
using namespace std;

/*
* max = A[i]
* min = A[i+1]
* max – min < n
* A[i] - A[i+1] < n
*/ 
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

void countSort(vector<int>& array) {
  int max = *max_element(array.begin(), array.end());
  vector<int> output(max);
  vector<int> occ(max);
  int size = array.size();
  
  for (int i = 0; i <= max; ++i) {
    occ[i] = 0;
  }

  for (int i = 0; i < size; i++) {
    occ[array[i]]++;
  }

  for (int i = 1; i <= max; i++) {
    occ[i] += occ[i - 1];
  }

  for (int i = size - 1; i >= 0; i--) {
    output[occ[array[i]] - 1] = array[i];
    occ[array[i]]--;
  }

  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

// T(n) = θ(n) + θ(n) = θ(n)  
void differenzeSottoCondizione(vector<int>& arr){
    countSort(arr); // T(n) = θ(n+k) = θ(n) perchè k è nell'ordine di n 
    sortDiff(arr);  // T(n) = θ(n) 
}