class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        int n = arr.size();
 
        vector<int>dp1(n , 1);
        // longest turbulent subarray ending at i such that arr[i] > arr[i-1]
        
        vector<int>dp2(n , 1);
        // longest turbuleny subarray ending at i such that arr[i] < arr[i-1]
        
        int ans = 1;
        for(int i = 1 ; i < n ; i++){
            
            if(arr[i] < arr[i-1]){
                dp1[i] = 1 + dp2[i-1]; 
            }
            
            if(arr[i] > arr[i-1]){
                dp2[i] = 1 + dp1[i-1];
            }
            
            ans = max({ans , dp1[i] , dp2[i]});
        }
        return ans;
        
    }
};