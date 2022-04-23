class Solution {
public:
    
    int recursion(string s1 , string s2, int **arr ){
        
        
      int m = s1.size(); int n = s2.size();
        if(s2.size() == 0){
            return s1.size();
        }
        
        if(s1.size() == 0){
            return s2.size();
        }
        
         if(s1 == s2){
             return 0;

         }
        
        if(arr[m][n] != -1){
            return arr[m][n];
        }
         if(s1[0] == s2[0]){
             // when both the characters are same
             return arr[m][n] = recursion(s1.substr(1) , s2.substr(1) , arr);
         }else{
             
             // either I can delete , insert or replace
             // insert
             int ans =  recursion(s1 , s2.substr(1), arr); 
              
             //delete
             int ans2 = recursion(s1.substr(1) , s2 , arr);
             
             //replace
             int ans3 = recursion(s1.substr(1) , s2.substr(1), arr);
          
              return arr[m][n] = min(ans , min(ans2 ,ans3)) + 1;
         }
    }
    
    int dp(string word1 , string word2){
           
        if(word1.size() == 0){
            return word2.size();
        }
        
        if(word2.size() == 0){
            return word1.size();
        }
        
         if(word1 == word2){
             return 0;

         }
        int m = word1.size();
        int n = word2.size();
        
        int arr[m+1][n+1];
        for(int i = 0 ; i <= m ; i++)
            for(int j = 0; j <= n ;j++)
                arr[i][j] = 0;
       
        for(int i = 0 ; i <= m ; i++){
             arr[i][0] = i;
        }
        
        for(int i = 0 ; i <= n ; i++){
            arr[0][i] = i;
        }
        
        for(int i = 1 ; i <= m ; i++){
            for(int j = 1 ; j <=n ; j++){
                
                if(word1[i-1] == word2[j-1]){
                    arr[i][j] = arr[i-1][j-1];
                }else{
                    // insert
                    arr[i][j] =  arr[i][j-1];
                    
                    //delete
                    arr[i][j] = min(arr[i][j],  arr[i-1][j]);
                    
                    //replace
                    arr[i][j] = 1 + min(arr[i][j],  arr[i-1][j-1]);
                }
            }
        }
        return arr[m][n];
    }
    int minDistance(string word1, string word2) {
      
      //  int **arr = new int*[word1.size() + 1];
      //   for(int i= 0 ; i <= word1.size() ; i++){
      //       arr[i]= new int[word2.size() + 1];
      //       for(int j = 0 ; j <= word2.size() ; j++)
      //       {
      //           arr[i][j] = -1;
      //       }
      //   }
      // return recursion(word1 , word2 , arr);
        return dp(word1 , word2) ;
    }
};