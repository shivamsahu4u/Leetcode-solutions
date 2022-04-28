class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
           int count = 0;
     
         for(int i = 0; i  < nums.size() ; i++){
             count  = count  + nums[i];
         }
        
        int half= count/2;
        
        if(count % 2 != 0){
            return false;
        }
        
        vector<bool>dp(half + 1 , false);
        
        dp[0] = true;
        
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            for(int j = half ; j >= nums[i] ; j--){
                
                if(dp[j-nums[i]]){
                    dp[j]=true;
                }
            }
        }
        
        return dp[half];
    }
};