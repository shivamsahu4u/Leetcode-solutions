class Solution {
public:
 unordered_map<string , priority_queue<string , vector<string> , greater<string>>>hash ;
   
    void dfs(string u , unordered_map<string,bool>&visited , vector<string>&v){
        
       // visited[u] = true;
       
        
        // if(hash[u].size() == 0){
        //     return;
        // }
        ;
       while(hash[u].size()!= 0){
           string s = hash[u].top();
           hash[u].pop();
        dfs(s  , visited , v);
             
        }
         v.push_back(u);
        
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
     
        // unordered_map<string , priority_queue<string , vector<string> , greater<string>>hash;
        
        for(auto it : tickets){
            hash[it[0]].push(it[1]);
           // hash[it[1]].insert(it[0]);
        }
        
       unordered_map<string , bool>visited;
        vector<string>v;
       dfs("JFK"  , visited , v);
        
        reverse(v.begin() , v.end());
        return v;
    }
};