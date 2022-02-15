class Solution {
public:

    bool dfs(int a , int b , vector<int>adj[] , int **mat){
        
        if(mat[a][b]!=-1){
            return mat[a][b];
        }
        
        for(auto it : adj[a]){
            
             if(dfs(it , b , adj , mat)){
                 mat[a][b] = true;
                 return true;
             }
        }
        
        mat[a][b] = false;
        return false;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
      
        int **mat = new int*[n];
        
        for(int i = 0 ; i < n ; i++){
            mat[i] = new int[n];
            for(int j = 0 ; j < n ; j++){
                mat[i][j] = -1;
            }
        }
        
        vector<int>adj[n];
        
        for(auto path : pre){
            
             mat[path[0]][path[1]] = 1;
             adj[path[0]].push_back(path[1]);     
        }
        
        vector<bool>ans(q.size() , false);
        for(int i = 0 ; i < q.size() ; i++){
            
            if(dfs(q[i][0] , q[i][1] , adj , mat)){
                ans[i]= true;
            }else{
                ans[i]= false;
            }
        }
        
        return ans;
    }
};