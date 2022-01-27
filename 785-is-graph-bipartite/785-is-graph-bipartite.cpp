class Solution {
public:
    
    bool helper(int s,vector<vector<int>>&graph , vector<int>&color ){
   
          if(color[s] == -1){
              color[s] = 1;
          }
        
        for(auto it: graph[s]){
            
             if(color[it] == -1){
                 
                  color[it] = 1 - color[s];
                 
                 if(!helper(it , graph , color))
                     return false;    // we cantt
                 
             }else if(color[s] == color[it]){
                 return false;
             }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
     
        
         //bipartite graph 
        //check for red and blue color nodes
        //check if graph is bipartitite or note
        int n = graph.size();
       
        vector<int>color(n , -1);
        
        for(int i = 0 ; i < n ; i++){
              
             if(color[i] == -1)
             if(!helper(i , graph , color )){
                 return false;
             }
            
        }
        return true;
    }
};