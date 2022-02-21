class Solution {
public:
    
    int arr[4][2] = {{1,0},{0,1} , {-1,0} , {0,-1}};
    void dfs(int u , int v , vector<vector<int>>& grid , bool **visited , int n , int m){
        
        visited[u][v] = true;
        
        for(int i = 0 ; i < 4 ; i++){
            
            if((u + arr[i][0]) >= 0 && (v + arr[i][1] >= 0) && (u + arr[i][0] < n) && (v + arr[i][1] < m) && visited[u+arr[i][0]][v+arr[i][1]] == false &&  grid[u+arr[i][0]][v+arr[i][1]] == 1){
                dfs(u+arr[i][0] , v+arr[i][1] , grid , visited , n , m);
            }
        }
    }
    
    int helper(vector<vector<int>>& grid){
        //FIND OUT HOW MANY ISLANDS ARE THERE
        int n = grid.size();
        int m = grid[0].size();
        
        cout<<n << " ---- "<< m << endl ;
        bool **visited = new bool*[n];
        
        for(int i = 0 ; i < n ; i++){
            
            visited[i] = new bool[m];
            
            for(int j = 0 ; j < m ; j++){
                
                visited[i][j] = false;
            }
        }
        int count = 0;
        for(int i = 0 ; i < n ; i++  ){
            
            for(int j= 0 ; j < m ; j++){
                
                
                if(grid[i][j] == 1 && visited[i][j] == false){
                    
                    count++;
                    dfs(i , j , grid, visited , n , m);
                }
            }
        }
       return count;
    }
    int minDays(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int islands = helper(grid);
        
        if(islands == 0 || islands > 1){
            return 0;
        }else{
            
            for(int i = 0 ; i < n ; i++){
                
                for(int j = 0 ; j < m ; j++){
                    
                    if(grid[i][j] == 1)
                    {
                        grid[i][j] = 0;
                        
                        int islands = helper(grid);
                        
                        grid[i][j] = 1;
                        
                        if(islands == 0 || islands > 1){
                            return 1;
                        }
                    }
                }
            }
            
            return 2;
        }
        
    }
};