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
    
    int rob(vector<int>&nums , int n){
        vector<int>dp(n+1, 0);
        
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2 ; i <= n ; i++){
            
             dp[i] = max(nums[i-1] + dp[i-2] , dp[i-1]);
        }
        
        return dp[n];
        
    }
    int rob(vector<int>& nums) {
         
         int n = nums.size();
        // vector<int>dp(n , -1);
        // return rob(nums , 0 , n , dp);
       return rob(nums , n);
    }
};