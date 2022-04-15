class Solution {
public:
    // #recursive approach TC - O(2^N) SC - O(N)
    int longestCommonSubsequenceR(string text1, string text2) {
      if(text1 == "" || text2 == ""){
             return 0;
         }
        
        if(text1[0] == text2[0]){
            return 1 + longestCommonSubsequenceR(text1.substr(1) , text2.substr(1));
        }else{
            return max(longestCommonSubsequenceR(text1.substr(1) , text2) ,                                              longestCommonSubsequenceR(text1 , text2.substr(1)));    
    }
    }
    // # Memoization Approach
      int memoization(int u , int v , string text1 , string text2 , vector<vector<int>>&dp){
          if(u == text1.size() || v == text2.size()){
              return  0;
          }
          
          if(dp[u][v] != -1){
              return dp[u][v];
          }
           if(text1[u] == text2[v]){
            return dp[u][v] = 1 + memoization(u+1 , v+1 , text1 , text2,dp);
        }else{
            return dp[u][v] =  max( memoization(u , v+1 ,text1 , text2,dp) ,                                              memoization(u+1 , v , text1 , text2,dp));    
         }
          
      }  
    
    int dp(string text1 , string text2){
         
         int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>>dp(n , vector<int>(m , 0));
        
        for(int i = 0 ; i < m ; i++){
            if(text2[i] == text1[0]){
                dp[0][i] = 1;
            }
            if(i > 0 && dp[0][i-1] > 0){
                dp[0][i] = 1;
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(text1[i] == text2[0]){
                dp[i][0] = 1;
            }
             if(i > 0 && dp[i-1][0] > 0){
                dp[i][0] = 1;
            }
        }
        
        for(int i = 1 ; i < n ; i++){
            
            for(int j = 1 ; j < m ; j++){
                
                if(text1[i] == text2[j]){
                    
                    dp[i][j] = 1 + dp[i-1][j-1]; 
                }else{
                    dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[n-1][m-1];
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        //  int n = text1.size() ; int m = text2.size();
        // vector<vector<int>>dp(n , vector<int>(m , -1));
        // return memoization(0 , 0 , text1 , text2 , dp);
        return dp(text1 , text2);
    }
};