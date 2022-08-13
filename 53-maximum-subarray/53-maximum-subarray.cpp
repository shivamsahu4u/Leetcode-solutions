class Solution {
public:
    int maxSubArray(vector<int>& arr) {
          int n = arr.size();
          int dp[n];
         // dp[i] means maximum subarray till arr[i]
          dp[0] = arr[0];
        // int sum = arr[0];
        int ans = arr[0];
        for(int i = 1 ; i < n ; i++){
             // sum = sum + arr[i];
             dp[i] = arr[i] + (dp[i-1] > 0 ? dp[i-1]: 0) ;
            ans = max(ans , dp[i]);
        }
        return ans;
    }
};

//         // TC - O(N2)
//         // SC - O(1)
        
//          int n = arr.size();
//         int ans = INT_MIN;
//         for(int i = 0 ; i < n ; i++){
//              int sum = 0;
               
//             for(int j = i ; j < n ; j++){
                                    
//                 sum = sum + arr[j];
//                 ans = max(ans , sum);
//             }
//         }
//         return ans;
       
//     }    
    

//  int n = arr.size();
//         int ans = INT_MIN;
//         for(int i = 0 ; i < n ; i++){
            
//             for(int j = 0 ; j < n ; j++){
                
//                 int sum = 0;
//                 for(int k = i ; k <= j ; k++){
                    
//                     sum = sum + arr[k];
//                 }
                
//                 ans = max(ans , sum);
//             }
//         }
//         return ans;