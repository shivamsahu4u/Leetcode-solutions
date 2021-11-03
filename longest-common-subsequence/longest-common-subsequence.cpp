class Solution {
public:
  
/* int helper(string text1 , string text2 , int i , int j , int **arr){
     if (i == text1.size() || j == text2.size()) {
		return 0;
	}
  
      if(arr[i][j] != -1){
          return arr[i][j];
      }
     
	
	if (text1[i] == text2[j]) {

		arr[i][j] = 1 + helper(text1, text2 , i+1 , j+1 , arr);
	} else {
	   arr[i][j] = max(helper(text1 , text2 , i+1 , j , arr) , helper(text1 , text2 , i , j+1 , arr));
	}

	return arr[i][j];
 } */  
int longestCommonSubsequence(string text1, string text2) {

	/* int **arr = new int*[text1.size()];
    
     for(int i = 0 ; i < text1.size() ; i++){
         
         arr[i] = new int[text2.size()];
         
         for(int j = 0 ; j < text2.size() ; j++){
             
             arr[i][j] = -1;
         }
     }*/
    
    int n = text1.size();
    int m = text2.size();
    
    int arr[m+1][n+1];
    
    for(int i = 0 ; i <= n ; i++){
        
        arr[0][i] = 0;    
    }
    
    for(int i = 0 ; i <= m ; i++){
        
        arr[i][0] = 0;
    }
    
    for(int i = 1 ; i <= m ; i++ ){
        
        for(int j = 1 ; j <= n ; j++){
            
             if(text1[j-1] == text2[i-1]){
                 
                 arr[i][j] = 1 + arr[i-1][j-1];
             }else{
                 arr[i][j] = max(arr[i][j-1] , arr[i-1][j]);
             }
        }
    }
    
    return arr[m][n];
    
    //return helper(text1 , text2 , 0 , 0 , arr);
}
};