// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
// In every call we are passing the number of eggs left  and
// the number of floors left to check. So after checking k'th  
// floor if you pass k+1 you are increasing the. number of floors
// i.e(k+1) ,whereas (floor - k) gives you the remaining floors .
  
// Best of the worst
// min of the maxes 
// best choices in worst of luck 
public:
//Function to find minimum number of attempts needed in 
//order to find the critical floor.
    int eggDrop(int n , int k , vector<vector<int>> &dp){
        // if floor is 1 or 0
        if(k == 0 || k == 1){
            return k;
        }
        // we consider worst case in such type of questions
        if(n == 1){
            return k;
        }
        
        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        
        int res = INT_MAX;
        for(int p = 1 ; p <= k ; p++){
            
            int ans = 1 + max(eggDrop(n-1 ,  p-1 , dp) , eggDrop(n , k - p , dp ));
            res = min( res , ans);
            
        }
        
        return dp[n][k] = res;
    }
    
int dpp(int n , int k){
          vector<vector<int>>dp(n+1 , vector<int>(k+1 , -1));
           // n eggs , k floors
          // egg is 0
          for(int i = 0 ; i < k+1 ; i++){
              dp[0][i] = i; // worst case to be taken
          }
          // egg is one
          for(int i = 0 ; i < k+1 ; i++){
              dp[1][i] = i;
          }
          
          for(int i = 0 ; i < n+1 ; i++){
              dp[i][0] = 0;
          }
          
          for(int i = 0 ; i < n+1 ; i++){
              dp[i][1] = 1;
          }
          
          for(int i = 2 ; i < n+1 ; i++){
              
              for(int j = 2 ; j < k+1 ; j++){
                  
                   dp[i][j] = INT_MAX;
                   for(int k = 1 ; k <= j ; k++){
                       
                        dp[i][j] = min(dp[i][j] , 1 + max(dp[i-1][k-1] , dp[i][j-k]));
                   }
              }
          }
          return dp[n][k];
    }
    int eggDrop(int n, int k) 
    {
        // vector<vector<int>>dp(n+1 , vector<int>(k+1 , -1));
        // return eggDrop(n , k , dp );
        return dpp(n , k);
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
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends