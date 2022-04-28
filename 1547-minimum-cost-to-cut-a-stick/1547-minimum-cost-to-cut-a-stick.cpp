class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
       
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin() , cuts.end());
        int s = cuts.size();
         vector<vector<int> > dp(cuts.size(),vector<int> (cuts.size(),INT_MAX));
    
	// Your base cases stores the answer between [i.i]  and [i][i+1] subarrays or ranges, of size 2 only
     for(int i=0;i<dp.size();i++) dp[i][i]=0;  // base cases as for a point cost is Zero
     for(int i=0;i<dp.size()-1;i++)  dp[i][i+1]=0; //for every two points which constitue a stick is also zero
        // 0 1 3 4 5 7
                  //2     //
        for(int l = 2 ; l < s ; l++){
            
                  for(int i = 0 ; i < s - l ; i++){
                      
                      int j = i + l;
                      
                      dp[i][j] = INT_MAX;
                      for(int k = i+1 ; k < j ; k++){
                          
                          dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j] + (cuts[j]-cuts[i]));
                      }
                  }
        }
        return dp[0][s-1];
    } 
};