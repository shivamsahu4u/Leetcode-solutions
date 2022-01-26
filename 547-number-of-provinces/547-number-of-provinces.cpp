class Solution {
public:
    
    void dfs(int u , vector<int> adj[] , vector<bool>&visited){
        
          visited[u] = true;
        
        for(auto it : adj[u]){
            
             if(!visited[it]){
                 // visited[it] = true;
                 dfs(it , adj , visited);
             }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
     
        int n = isConnected.size();
         vector<int>adj[n];
        
        for(int i = 0 ; i < n ; i++){
            
             for(int j = 0 ; j < n ; j++){
                 
                 if(i!=j && isConnected[i][j] == 1){
                     
                     adj[i].push_back(j);
                     adj[j].push_back(i);
                     isConnected[j][i] = 0;
                 }
             }
        }
        
  
        //count number of componenets somply
        int c = 0;
        vector<bool>visited(n , false);
        
        for(int i = 0 ; i < n ; i++){
            
              if(visited[i] == false){
                  cout<<"i"<<i<<" ";
                   dfs(i , adj , visited);
                  c++;
              }
        }
        
        return c;
    }
};