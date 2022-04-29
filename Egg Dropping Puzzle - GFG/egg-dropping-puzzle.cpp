// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
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
            
            int ans = 1 + max(eggDrop(n-1 , p-1 , dp) , eggDrop(n , k - p , dp ));
            res = min( res , ans);
            
        }
        
        return dp[n][k] = res;
    }
    int eggDrop(int n, int k) 
    {
        vector<vector<int>>dp(n+1 , vector<int>(k+1 , -1));
        return eggDrop(n , k , dp );
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