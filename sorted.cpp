//Check if array is sorted or not
#include <iostream>
using namespace std;

int sortedArray(int arr[], int n){
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    int arr[] = {1,3,2,3,1,4};
    int n = 6;

    sortedArray(arr , n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    if(sortedArray(arr, n)){
        cout<<"sorted"<<" ";
    }
    else {
        cout<<"not sorted"<<" ";
    }
    return 0;
}

