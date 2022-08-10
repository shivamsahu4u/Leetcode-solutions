#define h 1000000007
class Solution {
public:
    
    int no(int n){
        
         string s = to_string(n);
         reverse(s.begin() , s.end());
         int ans = stoi(s);
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        // cout<<no(1)<<endl;
        unordered_map<int,long long >hash;
        cout<<nums.size()<<endl;
        for(int i = 0 ; i < nums.size(); i++){
            hash[nums[i] - no(nums[i])]++;
            // cout<<nums[i]- no(nums[i])<<" ";
        }cout<<endl;
        long long  c = 0;
        for(auto it : hash){
         // cout<<""
            c = c + (it.second*(it.second-1))/2;
            cout<<endl<<it.second<<": ";
        }
        return c % h; 
    }
};

// You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it satisfies all of the following conditions:

// 0 <= i < j < nums.length
// nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
// Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.

 

// Example 1:

// Input: nums = [42,11,1,97]
// Output: 2
// Explanation: The two pairs are:
//  - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
//  - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.