class Solution {
public:
    
    void helper(vector<vector<int>>&graph , vector<int> v , vector<vector<int>>&ans , int cur , int end){
        
        v.push_back(cur);
        
       if(cur == end){
        
            ans.push_back(v);
       }
        
        
        for(int node : graph[cur]){
            
            helper(graph , v , ans , node , end);
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      
         
        vector<vector<int>>ans;
        vector<bool>visited(graph.size() , false);
        vector<int>v;
        helper(graph ,v ,  ans ,  0 , graph.size() - 1 );
        
        return ans;
    }
};