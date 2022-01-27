class Solution {
public:
    
     bool helper(int s,vector<int>graph[] , vector<int>&color ){
   
          if(color[s] == -1){
              color[s] = 1;
          }
        
        for(auto it: graph[s]){
            
             if(color[it] == -1){
                 
                  color[it] = 1 - color[s];
                 
                 if(!helper(it , graph , color))
                     return false;    // we cant say true until we check all the graph
                 //but we say false , we in any part there is some mistake towards graph to be                           biparttie
                 
             }else if(color[s] == color[it]){
                 return false;
             }
        }
        
        return true;
    }
    bool isBipartite(vector<int>graph[] , int n) {
     
        
         //bipartite graph 
        //check for red and blue color nodes
        //check if graph is bipartitite or note
      
       
        vector<int>color(n , -1);
        
        for(int i = 0 ; i < n ; i++){
              
             if(color[i] == -1)
             if(!helper(i , graph , color )){
                 return false;
             }
            
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
      
           vector<int>a[n];
        
        for(int i = 0 ; i < dislikes.size() ; i++){
            
            a[dislikes[i][0]-1].push_back(dislikes[i][1]-1);
             a[dislikes[i][1]-1].push_back(dislikes[i][0]-1);
        }
        
        return isBipartite(a , n);
    }
};