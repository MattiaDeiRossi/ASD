#include <vector>
using namespace std;

void merge(int array[], int const left, int const mid, int const right)
{
    int const n1 = mid - left + 1;
    int const n2 = right - mid;
  
    auto *leftArray = new int[n1];
    auto *rightArray = new int[n2];
  
    for (auto i = 0; i < n1; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < n2; j++)
        rightArray[j] = array[mid + 1 + j];
  
    int i = 0; 
    int j = 0; 
    int k = left; 
  
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        }
        else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}
  
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; 
  
    auto mid = begin + (end - begin) / 2;   //floor((begin +end)/2);
    mergeSort(array, begin, mid);           // T(n/2)
    mergeSort(array, mid + 1, end);         // T(n/2)
    merge(array, begin, mid, end);          // T(n) =  θ(n1 + n2) +  θ(n) =  θ(n) 
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

// T(n) = θ(nlogn) + θ(n) = θ(nlogn)
void differenze(vector<int>& arr){ 
    mergeSort(arr.data(), 0, arr.size()-1);     // T(n) = θ(nlogn)
    sortDiff(arr);                              // T(n) = θ(n) 
}