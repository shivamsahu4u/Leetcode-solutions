class Solution {
public:
    int maxAscendingSum(vector<int>& arr) {
         
        int n = arr.size();
        
        vector<int> dp(n , 0);
        
        dp[0] = arr[0];
        int ans = dp[0];
        for(int i = 1 ; i < n ; i++){
            
             if(arr[i] > arr[i-1]){
                 dp[i] = arr[i] + dp[i-1]; 
             }else{
                 dp[i] = arr[i];
             }
            
            ans = max(ans , dp[i]);
        }
        return ans;
    }
};