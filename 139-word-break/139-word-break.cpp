class Solution {
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
        
      
         if(B.size() == 0){
             
             if(s == e){
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
    bool wordBreak(string A, vector<string>& B) {
          vector<vector<int>>dp(A.size() , vector<int>(A.size() , -1));
       return helper(A , 0 , A.size()-1 , B , dp);
    }
};