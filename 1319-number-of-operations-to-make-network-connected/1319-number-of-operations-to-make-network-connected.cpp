class Solution {
public:
    
    void dfs(int u , vector<int>adj[] , vector<bool>&visited){
        
        visited[u] = true;
        
        for(auto it : adj[u]){
            
            if(!visited[it]){
                
                dfs(it , adj , visited);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        //its looking that we need to find the number of islands
        
        vector<int>adj[n];
        vector<bool>visited(n , false);
        
        for(auto path : connections){
            
            adj[path[0]].push_back(path[1]);
            adj[path[1]].push_back(path[0]);
        }
        
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            
            if(!visited[i]){
                
                count++;
                
                dfs(i , adj , visited);
            }
        }
        int x = connections.size();
        
        if(n-1 > x){
            return -1;
        }
        return count-1;
    }
};