// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // 5   0 1 2 3 4
    int recursion(vector<vector<int>>&dp , int arr[] , int s , int e){
        
    
        if(s == e || s +1 == e){
            return 0;
        }
        
        if(dp[s][e] != -1){
            return dp[s][e];
        }
        
        int ans = INT_MAX;
        for(int i = s+1 ; i < e ; i++){
            int left = recursion(dp,arr , s , i);
            int right = recursion(dp,arr , i , e);
            int cost = left+right+arr[s]*arr[i]*arr[e];
            ans = min(ans , cost);
        }
        return dp[s][e] = ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>>dp(N+1 , vector<int>(N+1 , -1));
       return recursion(dp , arr , 0 , N-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends