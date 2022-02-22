class Solution {
public:
     map<pair<int ,int> , bool>vis;
    void dfs(int u , unordered_map<int , vector<int>>&arr , unordered_map<int , bool>&visited , vector<vector<int>>&ans){
        
        visited[u] = true;
        
        //var[]
        while(arr[u].size()){
            
               int ele = arr[u].back();
               arr[u].pop_back();                
                dfs(ele , arr , visited , ans);
                ans.push_back({u, ele});
            
        }
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        
        unordered_map<int , vector<int>>arr;
         map<int , int>indeegre;
       
        for(auto path : pairs){
            
            arr[path[0]].push_back(path[1]);
            indeegre[path[0]]++;
            indeegre[path[1]]--;
        }
        
        int startpoint = -1;
        
        //now we look for the startpoint, we will not able to find startpoint if they are in cycle , startpoint will remain -1 
        
        for(auto it : indeegre){
            
            if(it.second > 0){
                startpoint = it.first;
                // break;
            }
        }
        
        if(startpoint == -1){
            startpoint = pairs[0][0];
        }
        
        vector<vector<int>>ans;
        unordered_map<int , bool>visited;
        dfs(startpoint , arr , visited , ans);
        
        reverse(ans.begin() , ans.end());
        return ans;
    }
};