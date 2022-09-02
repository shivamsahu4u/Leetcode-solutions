class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
      
        // longest turbulent array ending at i such that arr[i-1] < arr[i]
        // longest turbulent array ending at i such that arr[i-1] > arr[i]
        // if(arr.size() == 0 || arr.size() == 1)return INT_MIN;
        vector<int>dp1(arr.size() + 1 , 1);
        vector<int>dp2(arr.size() + 1 , 1);
        
        dp1[0] = 1;
        dp2[0] = 1;
        int ans = 1;
        for(int i = 1 ; i < arr.size() ; i++){
            
            if(arr[i] > arr[i-1]){
                
                dp2[i] = 1 + dp1[i-1];
            }else if (arr[i] < arr[i-1]){
                dp1[i] = 1 + dp2[i-1];
            }
            
            ans = max({ans , dp1[i] , dp2[i]});
        }
        return ans;
        
    }
};