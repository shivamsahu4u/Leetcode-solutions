// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		
// Time Complexity - O(n2)
// Space Complexity - O(n)
	public:
    int dp(int arr[] , int n){
        
        vector<int>dp(n , 0);
        for(int i = 0 ; i < n ; i++){
            dp[i] = arr[i];
        }
        dp[0] = arr[0];
        int ans = arr[0];
        for(int i = 1 ;i < n ; i++){
            
            for(int j = i-1 ; j >=0 ; j--){
                
                if(arr[j] < arr[i]){
                dp[i] = max(dp[i] , dp[j] + arr[i]);
                ans = max(ans , dp[i]);
                }
            }
        }
        return ans;
    }
    
    // TC - O(2^n)  SC O(N)
    // MEMO TC- O(N2) SC - O(N2)
	int recursion(int arr[] , int s , int e , int pre , vector<vector<int>>&dp){
	    
	    if(s == e){
	        return 0;
	    }
	    
	    // if we are including this one
	    if(dp[s][pre + 1] != -1){
	        return dp[s][pre + 1];
	    }
	    
	    int include = 0; int notinclude= 0;
	    if(pre == -1 || arr[pre] < arr[s]){
	        
	        include = arr[s] + recursion(arr , s + 1 , e , s , dp);
	    }
	    
	    notinclude = recursion(arr , s+1 , e ,pre , dp);
	    
	    return dp[s][pre + 1] = max(include , notinclude);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // index + previous index
	    vector<vector<int>>dp(n+1 ,vector<int>(n+1 , -1));
	    return recursion(arr , 0 , n , -1 , dp);
	   
	   //return dp(arr,  n);
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends