class Solution {
public:
    
    bool dfs(int u , int v , vector<int>adj[] , vector<bool>&visited){
        
        if(u == v){
            return true;
        }
         visited[u] = true;
        
        for(auto it : adj[u]){
            
            if(!visited[it]){
                
                if(dfs(it , v , adj , visited)){
                    return true;
                }
            }
        }
        
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& pre, vector<vector<int>>& q) {
        
        int n = numCourses;
            
         vector<int>adj[n];
        
        for(auto path : pre){
             adj[path[0]].push_back(path[1]);
        }
        
        
       
        vector<bool>ans;
        for(int i = 0 ; i < q.size() ; i++){
             vector<bool>visited(n , false);
            if(dfs(q[i][0] , q[i][1] , adj , visited)){
                ans.push_back(true);
            }else{
               
                ans.push_back(false);
            }
        }
        
        return ans;
    }
};