
class Solution {
public:
    
    int maxPath = -1;
    
    void checkLongest(vector<int>&edges , int u , vector<int>&contain , vector<bool>&visited){
        
         if(edges[u] == -1){
             return;
         }
        
        if(visited[u] == true){
            
            // if this was visited earlier also
            // we need to find when it was actually visited to know the length of the cycle
            int find = -1;
            for(int i = 0 ; i < contain.size() ; i++){
                if(contain[i] == u){
                    find = i;
                    break;
                }
            }
            
            if(find == -1){
                return;
            }
            // maxPath = max(maxPath , (contain.size() - find));
            int d = contain.size() - find;
            
            if(maxPath < d){
                maxPath = d;
            }
            return;
        }else{
            
            visited[u] = true;
            contain.push_back(u);
            checkLongest(edges , edges[u] , contain , visited);
        }
        
     
    }
    
    int longestCycle(vector<int>& edges) {
         int n = edges.size();
         vector<bool>visited(n , false);
        
        
        for(int i = 0 ; i < n ; i++){
            
            vector<int>contain;
           
            if(!visited[i])
            checkLongest(edges , i , contain , visited);
        }
        
        return maxPath;
    }
};