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

//Find Largest element in unsorted array
int largestElement(int arr[], int n){
    int largest = arr[0];
    for(int i=0;i<n;i++){
         if(arr[i] = largest){
             largest = arr[i];
         }
    }
    return largest;
}

//Left rotate the array by one place
void rotateArray(int arr[], int n){
    int temp = arr[0];
    
    for(int i=1;i<n;i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;     //{1,2,3,4,5} = {2,3,4,5,1}
}

//Find missing no. in array
int missingNumber(int arr[],int N){
    int xor1=0, xor2=0;
    int n = N-1;
    for(int i=0;i<n;i++){
        xor2=xor2 ^ arr[i];
        xor1=xor1 ^(i+1);
    }
    xor1 = xor1 ^ N;
    return xor1 ^xor2;
}
int main(){
    int arr[] = {1,2,4,5};
    int n = 4;
    int newLength = missingNumber(arr, n);
    cout<<newLength;
    return 0;
}

//Two Sum
string read(int n, int book[], int target){
    sort(book, book+n);
    int left=0;
    int right = n-1;
    while(left<right){
        int sum = book[left]+book[right];
        if(sum==target){
            return "YES";
        }
        else if(sum<target){
            left++;
        }
        else{
            right--;
        }
    }
    return "NO";
}   //cout<<read(n,book,9);  YES  cout<<read(n,book,29);   NO

//Find no. that appears once and others twice
int getSingleElement(int arr[], int n){
    int xOr=0;
    for(int i=0; i<n;i++){
        xOr=xOr ^ arr[i];
    }
    return xOr;
}   //cout<<"Single Element "<<getSingleElement(arr, n);  

//Find no. of subarrays with xor k
int subarrayWithSumK(int arr[], int n, int k) {
    int xr = 0;
    map<int, int> mpp;
    mpp[xr] = 1;  // Initialize for XOR = 0
    int count = 0;
    for (int i = 0; i < n; i++) {
        xr ^= arr[i];
        int x = xr ^ k;
        count += mpp[x];
        mpp[xr]++;
    }
    return count;
}  //cout << subarrayWithSumK(arr, n, k) << endl;   4
