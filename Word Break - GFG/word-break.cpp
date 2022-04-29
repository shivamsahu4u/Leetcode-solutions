// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int ispresent(string A , int s , int e , vector<string> &B){
        
        string str =  "";
        
        for(int i = s ; i <= e ; i++){
            str = str + A[i];
        }
    
      for(int i = 0 ; i < B.size() ; i++){
          
          if(str == B[i]){
              return 1;
          }
      }
      return 0;
    }
    int helper( string A , int s , int e , vector<string> &B , vector<vector<int>>&dp){
        
        // if(s > e){
        //     return 1;
        // }
         if(B.size() == 0){
             
             if(s >= e){
                 return 1;
             }
             return  0;
         }
         
         if(dp[s][e]!=-1){
             return dp[s][e];
         }
         // A is present in B already
         if(ispresent(A , s , e , B)){
             return 1;
         }
        
         for(int i = s ; i < e ; i++){
             
              int ans = helper(A , s , i , B , dp) && helper(A , i+1 , e , B , dp);
              
              if(ans){
                  return dp[s][e] = 1;
              }
         }
         
         return dp[s][e] = 0;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        vector<vector<int>>dp(A.size() , vector<int>(A.size() , -1));
       return helper(A , 0 , A.size()-1 , B , dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends