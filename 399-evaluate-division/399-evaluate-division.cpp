class Solution {
public:
    
    double dfs(string u , string v ,  unordered_map<string , vector<pair<string , double>>>&arr , unordered_map<string , bool>visited , double ans){
        
        if(u == v){

            if(arr.count(u) == 0){
                return -1.00000;
            }
            
            return ans;
        }
        
        if(arr.count(u) == 0 || arr.count(v) == 0){
            return -1.00000;
        }
        
        visited[u] = true;
        
     
        //lets see if the answer already exists
        if(arr[u].size() == 0){
            return -1.00000;
        }
            
            for(auto it : arr[u]){
                
                if( it.first == v){
                    return ans*it.second;
                }
            }
        
        
        for(auto it : arr[u]){
            
              if(!visited[it.first]){
                 
                  double ar = ans*it.second;
                 // cout<<u<<" "<<it.first<<" "<<ar<<" "<<endl;
              double a = dfs(it.first , v , arr , visited , ar);
               if(a != -1.00000){
                   return a;
               }
              }
        }
        
        return -1.00000;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
       // [a , b] , a - > b - > a/b
       // b -> a =  1 / (a/b)
        
        int n = equations.size();
        int i = 0;
         unordered_map<string , vector<pair<string , double>>>arr; 
        
        for(auto path : equations){
             
            arr[path[0]].push_back(make_pair(path[1] , values[i]));
            // cout<<(1.0/values[i])<<" ";
            arr[path[1]].push_back(make_pair(path[0] , (1.0/values[i])));
           
            i++;
        }
        vector<double>ret;
        unordered_map<string  ,bool>visited;
        for(auto q : queries){
            
                
               double p =  dfs(q[0] , q[1] , arr , visited , 1.00000);
                
                ret.push_back(p);
                 // cout<<endl<<endl;
            
        }
        return ret;
    }
};




















































// class Solution {
// public:
    
//     double dfs(string s , string r , unordered_map<string , vector<pair<string , double>>>&hash , double ans , unordered_map<string  , int>&visited){
        
//          //if both of them are same
//          if(s == r){
//               if(hash.count(s) == 0){
//             return -1.00000;
//         }
             
//              return 1.00000;
//          }
        
//            //if one of them is not there
//         if(hash.count(s) == 0 || hash.count(r) == 0){
//             return -1.00000;
//         }
        
//         // if(visited.count(s) > 0){
//         //     return -1.00000;
//         // }
        
//         visited[s]++;
            
       
//         //if there is already a edge between them
//         // /if(hash.count(s) > 0 ){
//             //traverse vector of pairs and find string r , if exists return ansert
            
//             for(int i = 0 ; i < hash[s].size() ; i++){
                
//                 //if it is not visited yet
//                  if( hash[s][i].first == r){
//                      return ans*hash[s][i].second;
//                  }
//             }
//         // }
        
      
        
       
        
//         //both are different and present also , so simply we can apply dfs operation
        
//        for(int i = 0 ; i < hash[s].size() ; i++){
            
//            double a;
//              //traversing
//             if(visited.count(hash[s][i].first) == 0){
//               a = dfs(hash[s][i].first , r , hash , ans*hash[s][i].second , visited);
            
//             if(a != -1.00000){
//                 return a;
//             }
//             }
//         }
        
//         return -1.00000;
//     }
//     vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
     
//          unordered_map<string , vector<pair<string , double>>>hash;
        
//         int n = equations.size();
//         int m = queries.size();
        
//         for(int i = 0 ; i < n ; i++){
            
//              hash[equations[i][0]].push_back(make_pair(equations[i][1] , values[i]));
//              hash[equations[i][1]].push_back(make_pair(equations[i][0] , 1/values[i]));
             
//         }
        
        
//         vector<double>ans;
        
//         for(int i = 0 ; i < m ; i++){
//             unordered_map<string , int>visited;
//              ans.push_back(dfs(queries[i][0] , queries[i][1] , hash , 1.00000 , visited));
//         }
        
//         return ans;
//     }
// };