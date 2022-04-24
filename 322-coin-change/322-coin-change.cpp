class Solution {
public:
    int helper(vector<vector<int>>&dp , vector<int>&coins , int u , int v , int count){
        
        if(count == 0){
            return 0;
        }
   
        if(u == v){
            return INT_MAX-1;
          }
        
        if(dp[u][count] != -1){
            return dp[u][count];
        }
        
        int ans1 = INT_MAX , ans2 = INT_MAX;
        if(coins[u] <= count){
            //used coin 1 one time ( can be used multiple times)
            ans1 = 1 + helper(dp,coins , u , v , count - coins[u]);
        }
        ans2 = helper(dp,coins , u+1 , v , count);
        
        return dp[u][count] = min(ans2 , ans1);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1 , -1));
        int p = helper(dp, coins , 0 , coins.size() , amount);
        return p== INT_MAX-1?-1:p;
    }
};