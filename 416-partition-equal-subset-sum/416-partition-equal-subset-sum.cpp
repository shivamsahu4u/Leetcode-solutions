class Solution {
public:

    bool helper(vector<vector<int>>&dp , vector<int>&nums , int sum , int i){
        
        if(sum == 0){
            return true;
        }
        
        if(i == nums.size() || sum<0){
            return false;
        }
        
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        //either we will include that or not
        //we will include only when sum >= nums[i]
        
        bool ans1 = false , ans2 = false;
        if(sum >= nums[i]){
            ans1 = helper(dp , nums , sum - nums[i] , i+1);
        }
        // we dont want to include that 
          ans2 = helper(dp , nums , sum , i+1);
        
        return dp[i][sum] = ans1 || ans2;
    }
    bool canPartition(vector<int>&  nums) {
        
        // so we can follow the intution like this
        // if sum is already odd , then we cant partition the array
        // if sum is even then , to check partition , we can half the sum
        // then we can find weather we have elements for that sum or not
        // if not , we cant partition
        // if yes , indeed we can
        
        int sum = 0;
       for(int i = 0 ; i < nums.size();i++){
           sum = sum + nums[i];
       } 
         if(sum % 2 != 0)return false;
        cout<<sum;
      vector<vector<int>>dp(nums.size()+1 , vector<int>(sum/2 + 1 , -1));
        return helper(dp , nums , sum/2 , 0);
//         vector<int>dp(nums.size() , -1);
//         return helper(nums ,0 , nums.size() ,  0 , 0 , dp);
    }
};














































//     bool helper(vector<int>&nums , int u , int v,  int left , int right , vector<int>&dp){
        
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
        
//  return dp[u] = helper(nums , u+1 , v , left + nums[u] , right , dp) || helper(nums , u+1 , v , left , right + nums[u] , dp);
        
       
//     }