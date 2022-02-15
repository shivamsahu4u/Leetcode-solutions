class Solution {
public:
    
    
    int dfs(vector<int>adj[] , vector<bool>&visited , int u){
        
        auto count = 0;
        
        visited[u] = true;
        
        for(auto it : adj[u]){
            
             if(!visited[abs(it)]){
                 
                  count = count + dfs(adj , visited , abs(it)) + (it > 0);
             }
        }
        
        return count;
    } 
    int minReorder(int n, vector<vector<int>>& connections) {
        
        
         vector<int>adj[n];
        
        for(auto path : connections){
            
            adj[path[0]].push_back(path[1]);
            adj[path[1]].push_back(-path[0]);
        }
        
      vector<bool>visited(n ,false);
        
        return dfs(adj , visited , 0);
    }
};