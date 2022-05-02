// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

// Time Complexity - O(n3)
//Space Complexity - O(n2)


// Time Complexity - O(2^n)
class Solution{
public:
    // 5   0 1 2 3 4
    
//     int dpp(int arr[] , int n){
        
//         vector<vector<int>>dp(n , vector<int>(n , 0));
        
//         for(int i = 1 ; i < n ; i++){
//             dp[i][i] = 0;
//             //single matrix have 0 multiplications
//         }
        
//         //since matrix will be filled crossly
        
//         for(int l = 2 ; l < n; l++){
            
//             for(int i = 1 ; i < n-l+1 ; i++){
                
//                 int j = i + l - 1;
//                 dp[i][j] = INT_MAX;
//                 for(int k = i ; k < j ; k++){
                    
//                     dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j]);
//                 }
//             }
            
//         }
//         return dp[1][n-1];
//     }
    
// int recmemo(vector<vector<int>>&dp , int arr[] , int s , int e){
        
    
//         if(s == e || s +1 == e){
//             return 0;
//         }
        
//         if(dp[s][e] != -1){
//             return dp[s][e];
//         }
        
//         int ans = INT_MAX;
//         for(int i = s+1 ; i < e ; i++){
//             int left = recmemo(dp,arr , s , i);
//             int right = recmemo(dp,arr , i , e);
//             int cost = left+right+arr[s]*arr[i]*arr[e];
//             ans = min(ans , cost);
//         }
//         return dp[s][e] = ans;
//     }


    int dpp(int n , int arr[]){
        vector<vector<int>>dp(n , vector<int>(n , 0));
        
        for(int i = 0 ; i < n ; i++){
            dp[i][i] = 0;
        }
        
        for(int i = 0 ; i < n-1 ; i++){
            dp[i][i+1];
        }
        
        for(int l = 2 ; l <= n-1 ; l++){
            
            for(int i = 0 ; i < n-l ; i++){
                
                int j = i + l ;
                dp[i][j] = INT_MAX;
                for(int k = i+1 ; k < j ; k++){
                    
                    int left = dp[i][k];
                    int right = dp[k][j];
                    int ans = left + right + arr[i]*arr[k]*arr[j];
                   
                   dp[i][j]= min(dp[i][j] , ans); 
                }
            }
        }
        return dp[0][n-1];
    }
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>>dp(N+1 , vector<int>(N+1 , -1));
       return dpp( N, arr );
    }
};













// int recmemo(vector<vector<int>>&dp , int arr[] , int s , int e){
        
    
//         if(s == e || s +1 == e){
//             return 0;
//         }
        
//         if(dp[s][e] != -1){
//             return dp[s][e];
//         }
        
//         int ans = INT_MAX;
//         for(int i = s+1 ; i < e ; i++){
//             int left = recursion(dp,arr , s , i);
//             int right = recursion(dp,arr , i , e);
//             int cost = left+right+arr[s]*arr[i]*arr[e];
//             ans = min(ans , cost);
//         }
//         return dp[s][e] = ans;
//     }

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