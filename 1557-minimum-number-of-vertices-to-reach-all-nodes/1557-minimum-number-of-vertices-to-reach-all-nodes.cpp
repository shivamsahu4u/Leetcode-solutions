class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        // we can use BFS Traversal for the same
        //Time Complexity is O(n) since we visit all vertices
        
        int indeegre[n];
        int outdeegre[n];
        for(int i = 0 ; i < n ; i++){
            indeegre[i] = 0;outdeegre[i] = 0;
        }
           for(auto path : edges){
               
               outdeegre[path[0]]++;
               indeegre[path[1]]++;
           }
        
        vector<int>ans;
        for(int i = 0 ; i < n ; i++){
            
            if(outdeegre[i] >=1  && indeegre[i] ==0){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};