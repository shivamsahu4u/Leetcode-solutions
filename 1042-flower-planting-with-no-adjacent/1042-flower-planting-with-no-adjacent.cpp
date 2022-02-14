class Solution {
public:
    

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
      
         vector<int>adj[n];
        
        for(int i = 0 ; i < paths.size() ; i++){
              adj[paths[i][0]-1].push_back(paths[i][1]-1);
              adj[paths[i][1]-1].push_back(paths[i][0]-1);
        }
        
        vector<int>res( n , -1);
        
        for(int i = 0 ; i < n ; i++){
            
             bool color[5] = {};
            
            for(auto it : adj[i]){
                //either it is colored or not
                if(res[it]!=-1){
                    color[res[it]] = 1;
                    //yes this color is already used
                }
            }
            
            for(int j = 1 ; j < 5 ; j++){
                
                if(!color[j]){
                    res[i] = j;
                    break;
                }
            }
        }
        
        return res;
    }
};