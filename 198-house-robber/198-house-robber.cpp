class Solution {
public:
    
    int rob(vector<int>&nums , int u , int v , vector<int>&dp){
        
        if(u >= v){
            return 0;
        }
        
        if(dp[u] != -1){
            return dp[u];
        }
        
        return dp[u] = max(rob(nums , u+2 , v , dp)+nums[u] , rob(nums , u+1 , v , dp));
    }
    int rob(vector<int>& nums) {
         
         int n = nums.size();
        vector<int>dp(n , -1);
        return rob(nums , 0 , n , dp);
    }
};