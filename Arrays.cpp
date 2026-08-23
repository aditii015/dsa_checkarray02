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

//162 Find Peak Element
int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while(low<high){
            int mid = low + (high-low)/2;
            if(nums[mid] < nums[mid+1]){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }

//2643 Find Row with Maximum 1's
vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
       int maxOnes = 0;
        int rowIndex = 0;
       
        for(int i=0;i < mat.size();i++){
            int count = 0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j] == 1) count ++;
            }
            if(count>  maxOnes){
                maxOnes = count;
                rowIndex = i;
            }
        }
        return {rowIndex, maxOnes};
    }


//1021 Remove Outermost Paranthesis
string removeOuterParentheses(string s) {
        string result = "";
        int level = 0;
        for(char ch : s){
            if(ch == '('){
                if(level>0) result += ch;
                level++;
            }
            else if(ch == ')'){
                level--;
                if(level>0) result += ch;
            }
        }
        return result;
    }

//151 Reverse Words in a string
string reverseWords(string s) {
        string result = "";
        int i = s.size()-1;
        while(i >= 0){
            while(i>=0 && s[i] == ' '){
                i--;
            }
            if(i<0) break;
            int end = i;
            while(i >= 0 && s[i] != ' '){
                i--;
            }
            string word = s.substr(i + 1, end - i);
            if(!result.empty()){
                result += " ";
            }
            result += word;
        }
        return result;
    }

//1903 Largest Odd Number in string
string largestOddNumber(string num) {
        for(int i=num.size()-1;i>=0;i--){
            if((num[i]-'0')%2 == 1){
                return num.substr(0, i+1);
            }
        }
        return "";   
    }

//14 Longest Common Prefix
string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs[strs.size() - 1];

        int i=0;
        while(i<first.size() && i<last.size() && first[i]==last[i]){
            i++;
        }
        return first.substr(0, i);
    }

//205 Isomorphic Strings
bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0};
        int n = s.size();
        for(int i=0;i<n;i++){
            if(m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]]  = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }

//796 Rotate String
 bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        string doubled = s + s;
        return doubled.find(goal) != string::npos;
    }

//242 Valid Anagram
bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int freq[26] = {0};
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++){
            freq[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(freq[i]!= 0) return false;
        }
        return true;
    }

//451 Sort Characters by frequency
unordered_map<char, int> mp;
        for(char ch : s) {
            mp[ch]++;
        }
        vector<pair<int, char>> freq;
        for(auto it : mp) {
            freq.push_back({it.second, it.first});
        }
        sort(freq.begin(), freq.end(),
             [](pair<int, char>& a, pair<int, char>& b) {
                 return a.first > b.first;
             });
        string ans = "";
        for(auto it : freq) {
            int count = it.first;
            char ch = it.second;
            while(count--) {
                ans += ch;
            }
        }
        return ans;
}

//1614 Maximum Nesting Depth of parantheses
int maxDepth(string s) {
        int p = 0;
        int ans = 0;
        for(char ch : s){
            if(ch == '(') p++;
            else if(ch == ')') p--;     
            ans =max(ans, p);
        }
        return ans; 
    }

//13 Roman to Integer
int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> roman = {{'I',1}, {'V',5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for(int i=0;i<s.size()-1;i++){
            if(roman[s[i]] < roman[s[i+1]]){
                res -= roman[s[i]];
            }
            else{
                res += roman[s[i]];
            }
        } 
        return res + roman[s.back()];
    }

//1781 Sum of Beauty of all substrings
int beautySum(string s) {
        int n = s.length();
        int sum = 0;
        for(int i=0;i<n;i++){
            unordered_map<char, int> freq;
            for(int j=i;j<n;j++){
                freq[s[j]]++;          
                int mini = INT_MAX;
                int maxi = INT_MIN;
                for(auto it : freq){
                    mini = min(mini, it.second);
                    maxi = max(maxi, it.second);
                }
                sum += (maxi - mini);
            }
        }
        return sum;
    }

//8  Stirng to Integer(atoi)
int myAtoi(string s) {
        int i=0;
        int n = s.size();
        while(i<n && s[i] == ' '){
            i++;
        }
        int sign = 1;
        if(i<n && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-'){
                sign = -1;
            }
            i++;
        }
        long long num = 0;
        while(i<n && isdigit(s[i])){
            int digit = s[i] - '0';
            if(num > (INT_MAX - digit)/10){
                if(sign == 1){
                    return INT_MAX;
                }
                return INT_MIN;
            } 
             num = num * 10 + digit;

            i++;
        }
        return sign * num;
    }

//66 Plus One(array)
vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i=n-1;i>=0;i--){
            if(digits[i] < 9){
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }

//136 Single Number(Hash Map)
int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int x : nums)
           mp[x]++;
        for(auto it : mp)
           if(it.second == 1)
               return it.first;           
        return -1;
    }

//169 Single Element(Moore's Voting Algorithm)
int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for(int num : nums){
            if(count == 0) 
                candidate = num;
            if(candidate == num){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate;
    }

//20 Valid Paranthese(stack)
bool isValid(string s) {
        stack<char> st;
        for(char ch : s){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                if(st.empty()) return false;

                if(ch == ')' && st.top() != '(')
                   return false;
                if(ch == '}' && st.top() != '{')
                   return false;
                if(ch == ']' && st.top() != '[')
                   return false;
                st.pop();
            }
        }
        return st.empty();
    }

//21 Merge Two Sorted Lists
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode current(-1);
        ListNode* tail = &current;

        while(list1 != NULL && list2 != NULL) {
            if(list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        if(list1 != NULL)
            tail->next = list1;
        if(list2 != NULL)
            tail->next = list2;
        return current.next;
    }

//58 Length of last word(string)
int lengthOfLastWord(string s) {
        int count = 0;
        int i = s.length() - 1;
        while(i >= 0 && s[i] == ' '){
            i--;
        }
        while(i >= 0 && s[i] != ' '){
            count++;
            i--;
        }
        return count;
    }

//28 Find the Index of the first Occurrence in String 
int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        for(int i=0;i<=n-m;i++){
            int j = 0;
            while(j<m && haystack[i+j] == needle[j]){
                j++;
            }
            if(j == m){
                return i;
            }
        }
        return -1;
    }

//125 Valid Palindrome(two pointer)
bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            while(left < right && !isalnum(s[left]))
               left++;
            while(left < right && !isalnum(s[right]))
               right--;
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

//206 Reversed Linked List(3 pointer)
ListNode* reverseList(ListNode* head) {
       ListNode* prev = NULL;
       ListNode* temp = head;
    
       while(temp != NULL){
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
       }
       return prev;
    }

//141 Linked List cycle
bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast -> next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return true;
            }
        }
        return false;
    }

//142 Linked List cycle II
ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast -> next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                slow = head;

                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }

//290 Word Pattern
bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;

        while(ss >> word){
            words.push_back(word);
        }
        if(pattern.size() != words.size()){
            return false;
        }
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        for(int i=0;i<pattern.size();i++){
            char ch = pattern[i];
            string w = words[i];

            if(mp1.count(ch) && mp1[ch] != w)
                return false;
            if(mp2.count(w) && mp2[w] != ch)
                return false;

            mp1[ch] = w;
            mp2[w] = ch; 
        }
        return true;
    }

//234 Palindrome Linked List
ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev= curr;
            curr = next;
        } 
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == nullptr && head->next == nullptr){
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = reverseList(slow->next);
        ListNode* first = head;
        ListNode* temp = second;

        while(temp != nullptr){
            if(first->val != temp->val){
                return false;
            }
            first = first->next;
            temp = temp->next;
        }
        slow->next = reverseList(second);
        return true;
    }

//19 Remove Nth node from end of LL(slow & fast approach)
ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow  = dummy;
        ListNode* fast = dummy;
        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }

//876 Middle of the linked list
ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

//2095 Delete the Middle Node of LL
ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* middle = slow->next;
        slow->next = slow->next->next;
        delete middle;
        return head;
    }

//148 Sort List(merge sort)
ListNode* mergeTwoSortedLL(ListNode* list1, ListNode* list2){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                temp ->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp -> next;
        }
        if(list1 != NULL){
            temp->next = list1;
        }
        else{
            temp->next = list2;
        }
        return dummyNode->next;
    }

    ListNode* findMiddle(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);
        return mergeTwoSortedLL(left, right);
    }


//2 Add Two Numbers in LL
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
    
        int carry = 0;
        while((l1 != NULL || l2 != NULL) || carry){
            int sum = 0;
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;
            ListNode* node = new ListNode(sum % 10);
            temp -> next = node;
            temp = temp->next;
        } 
        return dummy->next;
    }

//5 Longest Palindromic Substring
int expand(string& s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left - 1;
    }
    string longestPalindrome(string s) {
        int start = 0;
        int maxLen = 0;
        for(int i=0;i<s.size();i++){
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i+1);

            int len = max(len1, len2);
            if(len > maxLen){
                maxLen = len;
                start = i - (len-1)/2;
            }
        }
        return s.substr(start, maxLen);
    }

//83 Remove Duplicates from Sorted List I
ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while(curr != nullptr && curr->next != nullptr){
            if(curr->val == curr->next->val){
                curr->next = curr->next->next;
            }
            else{
                curr = curr->next;
            }
        }
        return head;
    }

//82 Remove Duplicates from Sorted List II
ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr != nullptr){
            if(curr->next != nullptr && curr->val == curr->next->val){
                while(curr->next != nullptr && curr->val == curr->next->val){
                    curr = curr->next;
                }
                prev->next = curr->next;
            }
            else{
                prev = curr;
            }
            curr = curr->next;
        }
        return dummy->next;
    }

//25 Reverse Nodes in K-group(hard problem)
ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* groupPrev = dummy;
        while(true){
            ListNode* kth = getKthNode(groupPrev, k);
            if(!kth) break;

            ListNode* groupNext = kth->next;
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            for(int i=0;i<k;i++){
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp; 
            }
            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }
        return dummy->next;
    }
    ListNode* getKthNode(ListNode* curr, int k){
        while(curr && k>0){
            curr = curr->next;
            k--;
        }
        return curr;
    }

//50 Pow(x, n) (recursion)
class Solution {
private: 
    double power(double x, long n){
        if(n==0) return 1.0;
        if(n==1) return x;

        if(n%2 == 0){
            return power(x*x, n/2);
        }
        return x * power(x, n-1);
    }
public:
    double myPow(double x, int n) {
        long long num = n;
        if(num < 0){
            return (1.0 / power(x, -1 * num));
        }
        return power(x, num);
    }
};

//17 Letter Combinations of a phone number
class Solution {
public:
    vector<string> result;
    vector<string> letters = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    void solve(string& digits, int index, string current){
        if(index == digits.size()){
            result.push_back(current);
            return;
        }
        string comb = letters[digits[index] - '0'];
        for(char ch : comb){
            current.push_back(ch);

            solve(digits, index + 1, current);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        solve(digits, 0, "");
        return result;
    }
};

//100 Same Tree
 bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p==NULL || q==NULL) return false;

        if(p->val != q->val) return false;

        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        return left && right;
    }

//101 Symmetric Tree
bool mirror(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL) return true;
        if(left == NULL || right == NULL) return false;
        if(left->val != right->val) return false;

        bool outer = mirror(left->left, right->right);
        bool inner = mirror(left->right, right->left);

        return outer && inner;
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;        
        return mirror(root->left, root->right);
    }

//404  Sum of Left Leaves
int sum(TreeNode* root, bool isLeft){
        if(root == NULL) return 0;

        if(isLeft && root->left == NULL && root->right == NULL){
            return root->val;
        }
        return sum(root->left, true) + sum(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;        
        return sum(root->left, true) + sum(root->right, false);
    }

//501 Find Mode in Binary Search Tree
vector<int> ans;
    int currentCount = 0;
    int maxCount = 0;
    int prev = 0;
    bool hasPrev = false;
    void inorder(TreeNode* root){
        if(root == NULL) return;

        inorder(root->left);
        if(!hasPrev || root->val != prev){
            currentCount = 1;
        }else{
            currentCount++;
        }
        prev = root->val;
        hasPrev = true;

        if(currentCount > maxCount){
            maxCount = currentCount;
            ans.clear();
            ans.push_back(root->val);
        }else if(currentCount == maxCount){
            ans.push_back(root->val);
        }
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }

//236 Lowest Common Ancestor of a Binary Tree
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;
    
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left && right){
            return root;
        }
        if(left != NULL){
            return left;
        }
        return right;
    }
