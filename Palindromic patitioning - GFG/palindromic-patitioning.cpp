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
        int n = str.size();
        int c[n];
        int p[n][n];
        //aaabb
        //we can first find out the plimdrome of all substrings
        // 2 3 4 5
            for (int i = 0; i < n; i++) {
        p[i][i] = true;
    }
    
        for(int l = 2 ; l <= n ; l++){
         
         //                  5 - 5 + 1
          for(int i = 0 ; i < n-l+1 ; i++){
              
              //  0 + 5 - 1 = 4
              int j = i + l - 1;
              
              if(l == 2){
                  p[i][j] = str[i]==str[j];
              }else{
                  
                  p[i][j] = (str[i]==str[j]) && (p[i+1][j-1]);
              }
          }
        }
        
        // now we have answers that 
        // from i to j , weahter it is palimdrome or not
        
        for(int i = 0 ; i < n ; i++){
            
              if(p[0][i] == true){
                  c[i] = 0;
              }else{
                  
                  c[i] = INT_MAX;
                  
                  for(int j = 0 ; j < i ; j++){
                      
                       if(p[j+1][i] == true && 1 + c[j] < c[i]){
                           c[i] = c[j] + 1;
                       }
                  }
              }
        }
        return c[n-1];
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