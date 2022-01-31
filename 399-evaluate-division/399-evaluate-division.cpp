class Solution {
public:
    
    double dfs(string s , string r , unordered_map<string , vector<pair<string , double>>>&hash , double ans , unordered_map<string  , int>&visited){
        
         //if both of them are same
         if(s == r){
              if(hash.count(s) == 0 || hash.count(r) == 0){
            return -1.00000;
        }
             
             return 1.00000;
         }
        
           //if one of them is not there
        if(hash.count(s) == 0 || hash.count(r) == 0){
            return -1.00000;
        }
        
        // if(visited.count(s) > 0){
        //     return -1.00000;
        // }
        
        visited[s]++;
            
       
        //if there is already a edge between them
        if(hash.count(s) > 0 ){
            //traverse vector of pairs and find string r , if exists return ansert
            
            for(int i = 0 ; i < hash[s].size() ; i++){
                
                //if it is not visited yet
                 if(visited.count(hash[s][i].first)== 0 && hash[s][i].first == r){
                     return hash[s][i].second;
                 }
            }
        }
        
      
        
       
        
        //both are different and present also , so simply we can apply dfs operation
        
       for(int i = 0 ; i < hash[s].size() ; i++){
            
           double a;
             //traversing
            if(visited.count(hash[s][i].first) == 0)
              a = dfs(hash[s][i].first , r , hash , ans*hash[s][i].second , visited);
            
            if(a != -1.00000){
                return a*hash[s][i].second;
            }
        }
        
        return -1.00000;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
     
         unordered_map<string , vector<pair<string , double>>>hash;
        
        int n = equations.size();
        int m = queries.size();
        
        for(int i = 0 ; i < n ; i++){
            
             hash[equations[i][0]].push_back(make_pair(equations[i][1] , values[i]));
             hash[equations[i][1]].push_back(make_pair(equations[i][0] , 1/values[i]));
             
        }
        
        
        vector<double>ans;
        
        for(int i = 0 ; i < m ; i++){
            unordered_map<string , int>visited;
             ans.push_back(dfs(queries[i][0] , queries[i][1] , hash , 1.00000 , visited));
        }
        
        return ans;
    }
};