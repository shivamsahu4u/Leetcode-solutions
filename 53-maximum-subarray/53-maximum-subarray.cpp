class Solution {
public:
// TC - O(N)
// SC - O(1)     
    int maxSubArray(vector<int>& arr) {
        
        int n = arr.size();
        int ans = INT_MIN;
        int  m = 0;
        for(int i = 0 ; i < n ; i++){
            m  = m + arr[i];
            ans = max(m , ans);
            if(m < 0){
                m = 0;
            }
            
        }
        return ans;
    }
};

// TC - O(N)
// SC - O(N)
//     int maxSubArray(vector<int>& arr) {
//           int n = arr.size();
//           int dp[n];
//          // dp[i] means maximum subarray till arr[i]
//           dp[0] = arr[0];
       
//         int ans = arr[0];
//         for(int i = 1 ; i < n ; i++){
            
//             dp[i] = arr[i] + (dp[i-1] > 0 ? dp[i-1]: 0) ;
//             ans = max(ans , dp[i]);
//         }
//         return ans;
        
      
//     }
