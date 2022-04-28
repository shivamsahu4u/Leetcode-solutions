class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        // Recursive : Using two variables
        
        // Recursive + Memoization : Using Intution 
        // Doing half and find sum to half
        
        // Dynamic Programming
        int cost = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            cost = cost + nums[i];
        }
        // means it is odd and cant be divided into two parts
        if(cost % 2 != 0){
            return false;
        }
        
        int sum = cost/2;
        
        bool dp[nums.size()+1][sum+1];
        
        for(int i = 1 ; i < sum+1 ; i++){
            dp[0][i] = false;
        }
        
        for(int i = 0 ; i < nums.size()+1 ; i++){
            dp[i][0] = true;
        }
        
        for(int i = 1 ; i < nums.size()+1 ; i++){
            
            for(int j = 1 ; j < sum + 1 ; j++){
                
                //either I will take it or not
                // I will take element only when its nums[i-1] <= j
                bool ans1 = false , ans2 = false;
                if(nums[i-1] <= j){
                    // Yes i included this element
                    ans1 = dp[i-1][j - nums[i-1]];
                }
                    ans2 = dp[i-1][j];
                
                dp[i][j] = ans1 || ans2;
            }
        }
        return dp[nums.size()][sum];
    }
};