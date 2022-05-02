class Solution {
public:
    // Time Complexity O(n2)
    // Space cOMPLEXITY o(n)
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
                    // break;
                }
            }
        }
        
     
        
        return dp[half];
    }
};





 
    //Dynamic Programming 
    // Time Complexity - O(nxsum/2)
//     // Space Complxity - O(nxsum/2)
//     bool canPartition(vector<int>& nums) {
        
//         // Recursive : Using two variables
        
//         // Recursive + Memoization : Using Intution 
//         // Doing half and find sum to half
        
//         // Dynamic Programming
//         int cost = 0;
//         for(int i = 0 ; i < nums.size() ; i++){
//             cost = cost + nums[i];
//         }
//         // means it is odd and cant be divided into two parts
//         if(cost % 2 != 0){
//             return false;
//         }
        
//         int sum = cost/2;
        
//         bool dp[nums.size()+1][sum+1];
        
//         for(int i = 1 ; i < sum+1 ; i++){
//             dp[0][i] = false;
//         }
        
//         for(int i = 0 ; i < nums.size()+1 ; i++){
//             dp[i][0] = true;
//         }
        
//         for(int i = 1 ; i < nums.size()+1 ; i++){
            
//             for(int j = 1 ; j < sum + 1 ; j++){
                
//                 //either I will take it or not
//                 // I will take element only when its nums[i-1] <= j
//                 bool ans1 = false , ans2 = false;
//                 if(nums[i-1] <= j){
//                     // Yes i included this element
//                     ans1 = dp[i-1][j - nums[i-1]];
//                 }
//                     ans2 = dp[i-1][j];
                
//                 dp[i][j] = ans1 || ans2;
//             }
//         }
//         return dp[nums.size()][sum];
//     }


//   // Memoization Approach
//     // Tc - o(n*sum/2)
//     // sc - o(n*sum/2) where n is length of the nums     // sum/2
// bool helper(vector<vector<int>>&dp , vector<int>&nums , int sum , int i){
        
//         if(sum == 0){
//             return true;
//         }
        
//         if(i == nums.size() || sum<0){
//             return false;
//         }
        
//         if(dp[i][sum] != -1){
//             return dp[i][sum];
//         }
//         //either we will include that or not
//         //we will include only when sum >= nums[i]
        
//         bool ans1 = false , ans2 = false;
//         if(sum >= nums[i]){
//             ans1 = helper(dp , nums , sum - nums[i] , i+1);
//         }
//         // we dont want to include that 
//           ans2 = helper(dp , nums , sum , i+1);
        
//         return dp[i][sum] = ans1 || ans2;
//     }
    
//     // Memoization Approach
//     // Tc - o(n*n)
//     // sc - o(n) where n is length of the nums
    
//     //Recursion Approach
//     // tC - O(2^N)
//     // SC - O(N) where n is the length of the nums
//     // SC - O(1) -- Excluding stack space
//    bool helper(vector<int>&nums , int u , int v,  int left , int right , vector<int>&dp){
        
//         if(u == v){
            
//             if(left == right)
//                 return true;
            
//             return false;
//         }
        
//         if(dp[u]!= -1 ){
//             return dp[u];
//         }
        
//         if(left < right){
//              bool ans = helper(nums , u + 1 , v , left + nums[u] , right ,dp); 
//               if(ans == true){
//                   return ans;
//               }
//         }else if(right < left){
//            bool ans =  helper(nums , u+1 , v , left , right + nums[u] , dp);
//             if(ans == true){
//                 return ans;
//             }
//         }
        
//  return dp[u] = helper(nums , u+1 , v , left + nums[u] , right , dp) || helper(nums , u+1 , v , left , right +   nums[u] , dp);
        
       
//     }
