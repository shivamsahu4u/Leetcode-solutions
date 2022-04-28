class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = INT_MAX-1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return (dp[amount] == Max) ? -1 : dp[amount];
    }
};
/*class Solution {
public:*/
    //Recursion
    //TC - O(2^N)
    // SC - N ( RECURSIVE STACK SPACE)
    
    // MEMOIZATION
    //TC  - O(N * AMOUNT)
    //SC - O(N * AMOUNT)
  /*  int helper(vector<vector<int>>&dp , vector<int>&coins , int u , int v , int count){
        
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
    }*/
    
    // DP
    //TC  - O(N * AMOUNT)
    //SC - O(N * AMOUNT)
  /*  int dpp(vector<int>&coins , int amount){
        vector<vector<int>>dp(coins.size()+1, vector<int>(amount+1 , -1));
        
        for(int i = 1 ; i <= amount ; i++)
            dp[0][i] = INT_MAX-1;
        
        for(int i = 0 ; i <= coins.size() ; i++){
            dp[i][0] = 0;
        }
        
        for(int i= 1 ; i <= coins.size() ; i++){
            
            for(int j = 1 ; j <= amount ; j++){
                
                int ans1 = INT_MAX , ans2 = INT_MAX;
                if(coins[i-1] <= j){
                    ans1 = 1 + dp[i][j - coins[i-1]];
                }
                
                ans2 = dp[i-1][j];
                
                dp[i][j] = min(ans1 , ans2);
            }
        }
        return dp[coins.size()][amount];
    }*/
 /*   int coinChange(vector<int>& coins, int amount) {
        // vector<vector<int>>dp(coins.size(), vector<int>(amount+1 , -1));
        // int p = helper(dp, coins , 0 , coins.size() , amount);
        // return p== INT_MAX-1?-1:p;
        int p =  dpp(coins , amount);
        return p== INT_MAX-1?-1:p;
    }*/
/*};*/