class Solution {
public:
     unordered_set<int>safe , cycle;
    //returns true if safe node , not forming cycle
    bool dfs(int u, vector<vector<int>>&graph , vector<bool>visited){
        
         //if node is already safe
        if(safe.find(u) != safe.end()){
            // safe[u]++;
            return true;
        }
        
        //if node is already visited
        if(cycle.find(u) != cycle.end()){
            // cycle[u]++;
            return false;
        }
        
        if(visited[u] == true){
            cycle.insert(u);
            return false;
        }
        visited[u] = true;
        
        for(auto it : graph[u]){
            
            if( !dfs(it , graph , visited)){
                cycle.insert(it);
                return false;
            }
        }
        
        safe.insert(u);
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      
        
         //this question sums up to find nodes that are not the part of the cycle in graph
        //to find nodes that are not the part of cycle
        //we perform dfs taking two unordered maps safe nodes and cycle nodes
         int n = graph.size();
        
         vector<bool>visited(n , false);
         vector<int>ans;
       for(int i = 0 ; i < n ; i++){
           
           if(dfs(i , graph, visited)){
               ans.push_back(i);
           }
       }
        return ans;
    }
};