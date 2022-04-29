class Solution {
public:
    int eggDrop(int n , int k , vector<vector<int>> &dp){
        // if floor is 1 or 0
        if(k == 0 || k == 1){
            return k;
        }
        // we consider worst case in such type of questions
        if(n == 1){
            return k;
        }
        
        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        
        int res = INT_MAX;
        for(int p = 1 ; p <= k ; p++){
            
            int ans = 1 + max(eggDrop(n-1 ,  p-1 , dp) , eggDrop(n , k - p , dp ));
            res = min( res , ans);
            
        }
        
        return dp[n][k] = res;
    }
    
int dpp(int n , int k){
          vector<vector<int>>dp(n+1 , vector<int>(k+1 , -1));
           // n eggs , k floors
          // egg is 0
          for(int i = 0 ; i < k+1 ; i++){
              dp[0][i] = i; // worst case to be taken
          }
          // egg is one
          for(int i = 0 ; i < k+1 ; i++){
              dp[1][i] = i;
          }
          
          for(int i = 0 ; i < n+1 ; i++){
              dp[i][0] = 0;
          }
          
          for(int i = 0 ; i < n+1 ; i++){
              dp[i][1] = 1;
          }
          
          for(int i = 2 ; i < n+1 ; i++){
              
              for(int j = 2 ; j < k+1 ; j++){
                  
                   dp[i][j] = INT_MAX;
                   for(int k = 1 ; k <= j ; k++){
                       
                        dp[i][j] = min(dp[i][j] , 1 + max(dp[i-1][k-1] , dp[i][j-k]));
                   }
              }
          }
          return dp[n][k];
    }
    
    int optimisedMemo(int eggs , int floors , vector<vector<int>>& dp){
        if(floors == 0 || floors == 1){
            return floors;
        }
        
        if(eggs == 1){
            return floors;
        }
        
        if(dp[eggs][floors] != -1){
            return dp[eggs][floors];
        }
        //we will do binary search
        int l = 1;
        int h = floors;
        int res = INT_MAX;
        while(l <= h){
            
            int mid = (l+h)/2;
            int left = optimisedMemo(eggs -1 , mid - 1 , dp);
             // here floors - mid as we are calcuting rest no. of floors
            int right = optimisedMemo(eggs , floors - mid , dp);
            
            int ans = 1 + max(left , right);
            // since we take min of maximum bad
            res = min(res , ans);
            //as we get bad in left
            if(left < right){
                l = mid + 1;
            }else{
                                h = mid - 1;

            }
        }
        return dp[eggs][floors] =  res;
    }
    
    int dppOptimised(int n , int k){
          vector<vector<int>>dp(n+1 , vector<int>(k+1 , -1));
           // n eggs , k floors
          // egg is 0
          for(int i = 0 ; i < k+1 ; i++){
              dp[0][i] = i; // worst case to be taken
          }
          // egg is one
          for(int i = 0 ; i < k+1 ; i++){
              dp[1][i] = i;
          }
          
          for(int i = 0 ; i < n+1 ; i++){
              dp[i][0] = 0;
          }
          
          for(int i = 0 ; i < n+1 ; i++){
              dp[i][1] = 1;
          }
          
          for(int i = 2 ; i < n+1 ; i++){
              
              for(int j = 2 ; j < k+1 ; j++){
                  
                   int l = 1;
                  int h = j;
                   dp[i][j] = INT_MAX;
                  while(l <= h){
                      
                      int mid  = (l+h)/2;
                      
                      int left = dp[i-1][mid-1];
                      int right = dp[i][j - mid];
                      int ans = 1 + max(left , right);
                      
                      if(left < right){
                          l = mid + 1;
                      }else{
                          h = mid - 1;
                      }
                      dp[i][j] = min(dp[i][j] , ans);
                  }
              }
          }
          return dp[n][k];
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1 , vector<int>(n+1 , -1));
        // return eggDrop(k , n , dp );
        //  // return dpp(k , n);
        return dppOptimised(k , n);
    }
};