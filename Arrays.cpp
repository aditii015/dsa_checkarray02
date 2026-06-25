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

//Maximum subarray sum using kadane's algorithm
long long maxSubarraySum(int arr[], int n) {
    long long maxi = LLONG_MIN;
    long long sum = 0;
    int start = 0;
    int ans_start = -1;
    int ans_end = -1;
    for (int i = 0; i < n; i++) {
        if (sum == 0)
            start = i;
        sum += arr[i];
        if (sum > maxi) {
            maxi = sum;
            ans_start = start;
            ans_end = i;
        }
        if (sum < 0)
            sum = 0;
    }
    cout << "Maximum Sum = " << maxi << endl;
    cout << "Start Index = " << ans_start << endl;
    cout << "End Index = " << ans_end << endl;
    cout << "Subarray: ";
    for (int i = ans_start; i <= ans_end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;  //maxSubarraySum(arr, n) {-2,1,-3,4,-1,2,1,-5,4};  Maximum Sum = 6 Start Index = 3 End Index = 6 Subarray: 4 -1 2 1 
    return maxi;
}

//1929 Concatenation of array
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*n);
        for(int i=0;i<n;i++){
            ans[i] = nums[i];
            ans[i+n] = nums[i];
        }
        return ans;
    }

//724 Find Pivot index
int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        for(int num : nums){
            totalSum += num;
        }
        int leftSum = 0;
        for(int i=0;i<nums.size();i++){
            int rightSum = totalSum - leftSum - nums[i];
            if(leftSum==rightSum){
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }

//152 Maximun Product subarray
int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            if (nums[i]<0){
                swap(maxProd, minProd);
            }
            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);
            ans = max(ans, maxProd);
        }
        return ans;
    }
