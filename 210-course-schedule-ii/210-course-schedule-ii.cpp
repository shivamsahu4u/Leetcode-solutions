class Solution {
public:
    
      
    bool cycle(int s , vector<int>adj[] , vector<bool>&visited , vector<bool>&dfs , stack<int>&stack){
        
         visited[s] = true;
        dfs[s] = true;
        
        for(auto it : adj[s]){
            
              if(visited[it] == false){
                  
                   if(cycle(it , adj , visited , dfs , stack)){
                       return true;
                   }
              }else if(dfs[it] == true){
                  return true;
              }
        }
        
        //visited[s] = false;
        stack.push(s);
        dfs[s] = false;
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pr) {
        
        //question is fir directed graph
        //i need to detect weather graph contain cycle or not
        
        //make list
        
        // if(pr.size() == 0){
        //    vector<int>v;
        //              return v;
        // }
        vector<int>adj[n];
        vector<int>v;
        for(int i = 0 ; i < pr.size() ; i++){
           
             adj[pr[i][1]].push_back(pr[i][0]); // (0 ,1) means 1 -> 0
        }
        
        //check cycle , we can use dfs with two arrays 
        //parent and dfs array
        
        vector<bool>visited(n , false);
        vector<bool>dfsv(n , false);
        stack<int>stack;
        vector<int>ans;
        for(int i = 0 ; i < n ; i++){
            
            if(!visited[i]){
                
                if(cycle(i , adj , visited , dfsv , stack)){
                    vector<int>v;
                     return v;
                }
                
                //cycle(i , adj , visited , dfsv , ans);
            }
        }
        
        while(!stack.empty()){
            ans.push_back(stack.top());
            stack.pop();
        }
        return ans;
        //return true;
    }
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        
//     }
};







