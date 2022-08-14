class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        int n = arr.size();
 
        // vector<int>dp1(n , 1);
        // longest turbulent subarray ending at i such that arr[i] > arr[i-1]
        
        // vector<int>dp2(n , 1);
        // longest turbuleny subarray ending at i such that arr[i] < arr[i-1]
        
        int ans = 1;
        int pt =1, p = 1 , rt=1 , r = 1;
        for(int i = 1 ; i < n ; i++){                 //1 1 1 1 1
                                                     // 1 1 1 1 1
            if(arr[i] < arr[i-1]){
                // dp1[i] = 1 + dp2[i-1];
                pt = 1 + r;
            }
            
            if(arr[i] > arr[i-1]){
                // dp2[i] = 1 + dp1[i-1];
                rt = 1 + p;
            }
            
            ans = max({ans ,rt, pt});
            // ans = max({ans , dp1[i] , dp2[i]});

            p = pt; r = rt;
                                     pt = 1 ; rt = 1;
        }
        return ans;
        
    }
};