class Solution {
public:
    //since in dfs we are visiting each edge once only so time complexity will be O(no. of edges)
    
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
       
        //since we are using euler path so we know , vertex with odd deegre will be starting point and if we dont found the node with odd deegre then it means that these are in cycle in that case we can start with any node
        
        //and also we need to make sure , every edge is visited only once , so this is the case of eular algorithms in which start and end are odd or not and rest of the nodes are even
        
        /*
        1. algorithms begins with visiting all the friends of node u
        2. call dfs(it)
        3. push_back(u) 
       */
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
                break;
            }
        }
        
        if(startpoint == -1){
            startpoint = pairs[0][0];
        }
        
        vector<vector<int>>ans;
        unordered_map<int , bool>visited;
        dfs(startpoint , arr , visited , ans);
        
        //we need reverse the resul also
        reverse(ans.begin() , ans.end());
        return ans;
    }
};