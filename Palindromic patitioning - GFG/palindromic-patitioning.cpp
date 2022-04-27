// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str)
    {
        // code here
        // 5 aaabb
        int n = str.size();
        int c[n][n];
        int p[n][n];
        
       for(int i= 0 ; i < n ; i++){
           c[i][i] = 0;
           p[i][i] = true;
       }    
       // 2 3 4     // 4
       for(int l = 2 ; l <= n ; l++){
           
           // 0 1 2 3     // 0 1
           for(int i = 0 ; i < n-l+1 ; i++){
               
               // 1 2 3 4        // 
               int j = i + l - 1;
               
               if(l == 2){
                   // it means substring is of length 2
                   p[i][j] = str[i] == str[j];
               }else{
                   
                   p[i][j] = ((str[i] == str[j]) && p[i+1][j-1]);
               }
               
               if(p[i][j] == true){
                   c[i][j] = 0;
               }else{
               c[i][j] = INT_MAX;
               for(int k = i ; k < j ; k++){
                   
                    int ans = c[i][k] + c[k+1][j] + 1;
                    c[i][j] = min(c[i][j] , ans);
               }
               }
           }
       }
       return c[0][n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends