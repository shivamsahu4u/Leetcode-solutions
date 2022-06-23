class Solution {
public:
         vector<vector<int>>ans;
    set<vector<int>>s;
    void helper(vector<int> nums , vector<int>v){
        if(nums.size() == 0){
            
            s.insert(v);
            
            return;
        }
        
        for(int i = 0 ; i < nums.size(); i++){
            
            int number = nums[i];
            
            swap(nums[0] , nums[i]);
            
            vector<int>arr(nums.begin() + 1 , nums.end());
            
            v.push_back(number);
            
            helper(arr , v);
            
            v.pop_back();
            arr.clear();
        }
        
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        //recursive , brute force solution
        
        /*as we know we will reach the base case n! times so there will be 3!recursive calls and at each call we are iterating over n elements so , time complexity is O(n * n!) */
        
        //T(n) = n * T(n-1) + O(1).
        
        
         vector<int>v;
        
        helper(nums , v);
        
        
        for(auto  i = s.begin() ; i!=s.end();i++){
            
              ans.push_back(*i);
        }
        return ans;
        
    }
};