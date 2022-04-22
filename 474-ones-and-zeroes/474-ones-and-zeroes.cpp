class Solution {
public:
    class count{
        public :
        int one;
        int zero;
        
        count(){
            one = 0;
            zero = 0;
        }
    };
     int dp[601][101][101];
    int helper(vector<string>& strs , count cc[] , int u , int v , int m , int n ){
        
          if(u == v){
              return 0;
          }
        
        if(m == 0 && n == 0){
            return 0;
        }
        
        if(dp[u][m][n] != -1){
            return dp[u][m][n] ;
        }
        
        int left = 0 , right = 0;
        if(m - cc[u].zero >= 0 && n - cc[u].one >= 0 ){
            
            left =  1 + helper(strs , cc , u+1 , v , m - cc[u].zero,n - cc[u].one );
        }
            right = helper(strs , cc , u+1 , v , m , n);
        
        
        return dp[u][m][n] = max(left , right);
    }
    
    int dp1(count cc[] , int v , int m , int n){
        
        //taking 3d array
        int arr[v+1][m+1][n+1];
        for(int i = 0 ; i <= v ; i++){
            for(int j = 0 ; j <= m ; j++){
                for(int k = 0 ; k <= n ; k++){
                    arr[i][j][k] = 0;
                }
            }
        }
        int ans = 0;
        for(int i = 1 ; i <= v ; i++){
            
            int ones =  cc[i-1].one;
            int zeros = cc[i-1].zero;
            // here we are not starting from 1 , because we have two parameter here, 
            // such that case can be 0 zero 1 one and 1 zero and 0 one
            for(int j = 0; j <= m ; j++){
                
                for(int k =0; k <= n ; k++){
                    
                    // if we do not include the string 
                    arr[i][j][k] = arr[i-1][j][k];
                    
                    //if we include the string
                    
                    if(zeros <= j && ones <= k){
                        
                        arr[i][j][k] = max(arr[i][j][k] , 1+arr[i-1][j-zeros][k-ones]);
                    }
                    
                     // ans = max(ans , arr[i][j][k]);
                }
            }
            
           
        }
        // return ans;
        return arr[v][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        
         int x = strs.size();
         count cc[x];
        
       // vector<vector<vector<int>>>dp(x , vector<int>(m+1 , vector<int>(n+1 , -1)));
        memset(dp  , -1 , sizeof(dp));
        for(int j = 0 ; j < x ; j++){
            
            for(int i = 0 ; i < strs[j].size(); i++){
                
                if(strs[j][i] == '0'){
                    cc[j].zero++;
                }else{
                    cc[j].one++;
                }
            }
        }
        
        
//         return helper(strs , cc , 0 , x , m , n);
        
        return dp1(cc ,x , m , n);
       
    }
};