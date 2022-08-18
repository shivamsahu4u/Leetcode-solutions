class Solution {
public:
    
    int rob(vector<int>&nums , int u , int v , int **dp , int com){
        
         if(u >= v){
             return 0;
         }
        
        if(dp[u][com] != -1){
            return dp[u][com];
        }
        if(com == true && u == nums.size()-1){
            return 0;
        }
        
        int ans1 = INT_MIN , ans2 = INT_MIN;
        if(u == 0){
       ans1 = max(rob(nums , u+2 , v , dp , 1) + nums[u] ,rob(nums , u+1 , v , dp , 0)) ;}
        else{
          ans2 = max(rob(nums , u+2 , v , dp , com) + nums[u] ,rob(nums , u+1 , v , dp , com)) ;  
        }
        return dp[u][com] = max(ans1 , ans2);
        
                
    }
    int rob(vector<int>& nums) {
      // cant rob 1st and last
        
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        // vector<int>dp(n,-1);
        int **arr = new int*[n];
        for(int i = 0 ; i < n ; i++){
            arr[i] = new int[2];
            
            for(int j = 0 ; j < 2 ; j++){
                arr[i][j] = -1;
            }
        }
        return rob(nums , 0 , nums.size() , arr , true);
    }
};