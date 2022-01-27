class Solution {
public:
    
    int parent(int node , vector<int>&paren){
        
        if(node == paren[node]){
            return node;
        }
        
        return paren[node] = parent(paren[node] , paren);
    }
    //it can be helpful in runtime cycle detection
    bool unionn(int a , int b , vector<int>&paren , vector<int>&rank){
        
        int x = parent(a , paren); int  y = parent(b , paren);
        
        if(x == y){
            return false; //parents are same so they were engage in making the cycle
        }
        
        if(rank[x] < rank[y]){
            paren[x] = y;
        }else if(rank[y] < rank[x]){
            paren[y] = x;
        }else{
            paren[y] = x;
            rank[x]++;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
      
           vector<int>parent(n);
        iota(begin(parent) , end(parent) , 0);
        vector<int>rank(n, 0);
    
        
        for(int i = 0 ; i < edges.size() ; i++){
            
             if(!unionn(edges[i][0]-1 , edges[i][1]-1 , parent , rank)){
                 vector<int>ans;
                 ans.push_back(edges[i][0]);
                 ans.push_back(edges[i][1]);
                 return ans;
             }
        }
        
        return {};
    }
    
    
};