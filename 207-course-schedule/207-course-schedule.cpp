class Solution {
public:
    
    bool cycle(int s , vector<int>adj[] , vector<bool>&visited , vector<bool>&dfs){
        
         visited[s] = true;
        dfs[s] = true;
        
        for(auto it : adj[s]){
            
              if(visited[it] == false){
                  
                   if(cycle(it , adj , visited , dfs )){
                       return true;
                   }
              }else if(dfs[it] == true){
                  return true;
              }
        }
        
        //visited[s] = false;
        dfs[s] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pr) {
        
        //question is fir directed graph
        //i need to detect weather graph contain cycle or not
        
        //make list
        
        if(pr.size() == 0){
            return true;
        }
        vector<int>adj[n];
        vector<int>v;
        for(int i = 0 ; i < pr.size() ; i++){
           
             adj[pr[i][1]].push_back(pr[i][0]); // (0 ,1) means 1 -> 0
        }
        
        //check cycle , we can use dfs with two arrays 
        //parent and dfs array
        
        vector<bool>visited(n , false);
        vector<bool>dfsv(n , false);
        
        for(int i = 0 ; i < n ; i++){
            
            if(!visited[i]){
                
                if(cycle(i , adj , visited , dfsv)){
                    return false;
                }
            }
        }
        
        return true;
    }
};