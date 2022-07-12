class Solution {
public:
    
    bool safe(int x , int y , int m , int n){
        if(x < 0 || y < 0 || x >= m || y >= n){
            return false;
        }
        return true;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        
          
           int m = matrix.size(); // rows
           int n = matrix[0].size(); // columns
        
         vector<vector<bool>>check(m , vector<bool>(n , false));
        
        if(m == n && (m == 1 || m == 0)){
            
            return;
        }
        
        for(int i = 0 ; i < m ; i++){
            
            for(int j = 0 ; j < n ; j++){
                
                int element = matrix[i][j]; // current element
                
                if(element == 0 && check[i][j] == false){
                    int x = i , y = j; 
                    check[x][y] = true;
                    // traversal in right
                      while(safe(x ,y+1 ,m ,n)){
                          if(matrix[x][y+1] != 0){
                              matrix[x][y+1] = 0;
                              check[x][y+1] = true;
                          }else if(matrix[x][y+1] == 0 && !check[x][y+1]){
                              break;
                          }
                          y++;
                      }
                    x = i, y = j;
                     // traversal in left
                     while(safe(x+1 ,y ,m ,n)){
                          if(matrix[x+1][y] != 0){
                              matrix[x+1][y] = 0;
                              check[x+1][y] = true;
                          }else if(matrix[x+1][y] == 0 && !check[x+1][y]){
                              break;
                          }
                          x++;
                      }
                       x = i, y = j;
                     // traversal in upper
                     while(safe(x-1 ,y ,m ,n)){
                          if(matrix[x-1][y] != 0){
                              matrix[x-1][y] = 0;
                              check[x-1][y] = true;
                          }else if(matrix[x-1][y] == 0 && !check[x-1][y]){
                              break;
                          }
                          x--;
                      }
                       x = i, y = j;
                     // traversal in lower
                     while(safe(x ,y-1 ,m ,n)){
                          if(matrix[x][y-1] != 0){  // unvisited
                              matrix[x][y-1] = 0;
                              check[x][y-1] = true;
                          }else if(matrix[x][y-1] == 0 && !check[x][y-1]){
                              break;
                          }
                          y--;
                      }
                }
            }
        }
        
    }
};