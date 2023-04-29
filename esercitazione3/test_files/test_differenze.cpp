#include "../differenze.cpp"
#include <iostream>

bool checker(vector<int>& arr){
    // |A[i] – A[i+1]| ≥ |A[i+1]−A[i+2]|
    for (size_t i = 0; i < arr.size()-2; i++)
    {
        if(! (abs(arr[i] - arr[i+1]) >= abs(arr[i+1]-arr[i+2])) ){
            return false;
        }
    }

    return true;
    
}

int main(){
    {
        std::vector<int> a = {7,4,2,6};
        differenze(a);
        cout<< checker(a) << endl;
    }
    {
        std::vector<int> a = {7,4,4,2,6};
        differenze(a);
        cout<< checker(a) << endl;
    }
    {
        std::vector<int> a = {3};
        differenze(a);
        cout<< checker(a) << endl;
    }
}