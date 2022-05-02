// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int helper(int wt[] , int val[] , int s , int e , int w , vector<vector<int>>&dp){
        if(w == 0){
                  return 0;
              }
              
        if(s == e){
                 return 0;
             
        }
        
        if(dp[s][w]!=-1){
            return dp[s][w];
        }
        
        int ans1 = 0 , ans2 = 0;
        // either we can include the value
        if(w >= wt[s]){
            
            ans1 = helper(wt , val , s+1 , e , w - wt[s] , dp) + val[s] ;
            
          
        }
        //or we dont include the value
        ans2 = helper(wt , val , s + 1 , e , w , dp);
        
        return dp[s][w] = max(ans2 , ans1);
    }
    
    int dpp(int wt[] , int val[] , int W ,  int n){
        
          vector<vector<int>>dp(n+1 , vector<int>(W + 1 , 0));
          
          for(int i = 0 ; i <= n ; i++){
              
              dp[i][0] = 0;
          }
          
          for(int i = 0 ; i < W + 1 ; i++){
              
              dp[0][i] = 0;
          }
          
          for(int i = 1 ; i < n+1 ; i++){
              
              for(int j = 1 ; j < W + 1 ; j++){
                  
                  int ans1 = 0 , ans2 = 0;
                  if(wt[i-1] <= j){
                      
                      ans1 = val[i-1] + dp[i-1][j - wt[i-1]];
                      
                  }
                  
                     ans2 = dp[i-1][j];
                     
                     dp[i][j] = max(ans1 , ans2);
              }
          }
          return dp[n][W];
    }
    int knapSack(int W, int wt[], int val[], int n) 
    {
        // vector<vector<int>>dp(n+1 , vector<int>(W + 1 , -1));
        //  return helper(wt , val ,0 ,  n , W , dp);
        
        return dpp(wt , val , W ,n);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends