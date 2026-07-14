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

//31 Next Permutation
void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index = i;
                break;
            }
        }
        if(index == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i=n-1;i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }
        reverse(nums.begin() + index + 1, nums.end());      
    }

//414 Third maximum number
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN;
        long second = LONG_MIN;
        long third = LONG_MIN;
        for(int num : nums){
            if(num==first || num==second || num==third){
                continue;
            }
            if(num>first){
                third = second;
                second = first;
                first = num;
            }
            else if(num>second){
                third = second;
                second = num;
            }
            else if(num>third){
                third = num;
            }
        }
        if(third == LONG_MIN){
            return first;
        }
        return third;
    }

//189 right Rotate the array by k times
void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }

//215 Kth Largest element in an array
int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.end() - k, nums.end());
        return nums[nums.size() - k];
}

//118 Pascal's Triangle
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows; i++){
            vector<int> row(i+1);
            row[0] = 1;
            row[i] = 1;
            for(int j=1; j<i;j++){
                row[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(row);
        }
        return ans;
    }
};

//145 Postorder Traversal in Binary Tree
void postorder(TreeNode* root, vector<int> &ans){
        if(root == NULL) return;
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }

//102 LevelOrder Traversal 
vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }

//103 ZigZag Traversal
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(!leftToRight){
                reverse(level.begin(), level.end());
            }
            ans.push_back(level);
            leftToRight = !leftToRight;
        }
        return ans;
    }

//199 Right Side View in B.T.
vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();            
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(i == size-1){
                    ans.push_back(node->val);
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return ans;
    }

//104 Max Depth
int maxDepth(TreeNode* root) {
    if(root == NULL) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return 1 + max(left, right);
}

//111 Min Depth 
int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
    
        if(root->left == NULL) return 1+right;
        if(root->right == NULL) return 1+left;

        return 1 + min(left, right);
    }

//235 LCA in BST
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if(root == NULL)
            return NULL;
        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }

//110 Balanced BT
int height(TreeNode* root){
        if(root==NULL) return 0;
        
        int left = height(root->left);
        if(left == -1) return -1;

        int right = height(root->right);
        if(right == -1) return -1;

        if(abs(left - right) > 1) return -1;

        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }

//543 Diameter of BT
int diameter = 0;
    int height(TreeNode* root){
        if(root == NULL) return 0;
        int left = height(root->left);
        int right = height(root->right);
        diameter = max(diameter, left + right);
        return 1+max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter; 
    }

//222 Count Complete Tree Nodes
int leftHeight(TreeNode* root){
        int h = 0;
        while(root){
            h++;
            root = root->left;
        }
        return h;
    }
    int rightHeight(TreeNode* root){
        int h = 0;
        while(root){
            h++;
            root = root->right;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        if(lh == rh)
            return (1 << lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

//112 Path Sum 
 bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        if(root->left==NULL && root->right==NULL)
            return targetSum == root->val;

        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }

//257 Binary Tree Paths
void dfs(TreeNode* root, string path, vector<string>& ans){
        if(root == NULL) return;
        if(path.empty())
           path += to_string(root->val);
        else
        path += "->" + to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            ans.push_back(path);
            return;
        }
        dfs(root->left, path, ans);
        dfs(root->right, path, ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        dfs(root, "", ans);
        return ans;
    }

//129 Sum Root to leaf Numbers
int dfs(TreeNode* root, int current){
        if(root == NULL) return 0;
        current = current * 10 + root->val;
        if(root->left == NULL && root->right == NULL) return current;
        return dfs(root->left, current) + dfs(root->right, current);
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
