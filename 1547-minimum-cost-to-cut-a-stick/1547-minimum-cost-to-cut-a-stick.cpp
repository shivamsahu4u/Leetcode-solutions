class Solution {
public:
    int dp[102][102];
    int helper(vector<int>&cuts , int cs , int ce , int s , int e ){
        
        if(cs > ce  ){
            return 0;
        }
        
        if(dp[cs][ce] != -1){
            return dp[cs][ce];
        }
        int res = INT_MAX;
        
        for(int i = cs ; i <= ce ; i++){
            
            int left = helper(cuts,   cs ,    i-1 ,      s , cuts[i] );
            int right = helper(cuts , i+1 ,    ce ,   cuts[i] , e ); 
            int ans = left + right + (e - s);
            res = min(ans , res);
        }
        return  dp[cs][ce] = res;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        int cuts_start = 0;
        int cuts_end = cuts.size() - 1;
        
        int start = 0;
        int end = n;
        memset(dp , -1 , sizeof dp);
         //vector<vector<int>>dp(cuts[cuts.size()-1]+1 , vector<int>(cuts[cuts.size()-1]+1 , -1));    
        return helper(cuts , cuts_start , cuts_end , start , end); 
    }
};