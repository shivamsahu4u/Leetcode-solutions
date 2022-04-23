// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int recursion(int arr[] ,int s ,  int e , vector<vector<int>>&dp){
        
           if(s == e){
               return 0;
           }
           
           if(s+1 ==e ){
               return 0;
           }
           
          if(s+2 == e){
              return arr[s]*arr[s+1]*arr[s+2];
          }
          
          if(dp[s][e] != -1){
              return dp[s][e];
          }
           
           int m = INT_MAX;
           // 1 , 2
           for(int k = s+1 ;k < e ; k++){
                                // 0 1
                                // 0 2
               int left = recursion(arr , s , k , dp);
                                // 1 3
                                // 2 3
               int right = recursion(arr , k , e , dp);
               
               m = min(m , (left + right + arr[s]*arr[k]*arr[e]));
           }
           
           return dp[s][e] =  m;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // Brute Force Solution
        vector<vector<int>>dp(N+1 , vector<int>(N , -1));
        return recursion(arr ,0 ,  N-1 , dp);
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