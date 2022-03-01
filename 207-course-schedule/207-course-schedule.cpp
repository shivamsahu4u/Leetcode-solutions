class Solution {
public:
    
   
     bool dfs(int u , vector<int>arr[] , vector<bool>&visited , vector<bool>&dfsvisited){
      
          visited[u] = true;
         dfsvisited[u] = true;
         
         for(auto it : arr[u]){
             
             if(!visited[it]){
                 
                 bool ans = dfs(it , arr , visited ,dfsvisited);
                if(ans == true){
                    return true;
                }
             }else if(dfsvisited[it] == true){
                 return true;
             }
         }
         
         dfsvisited[u] = false;
         return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
      
         //cycle in directed graph
        //we can use dfs here , for that we need dfsvisited and visited array
        
        vector<int>arr[numCourses];
        
        //directed graph
        for(auto path : prerequisites){
            int a = path[0];
            int b = path[1];
            arr[b].push_back(a);
        }
        
        vector<bool>visited(numCourses , false);
        vector<bool>dfsvisited(numCourses , false);
        for(int i = 0 ; i < numCourses ; i++){
       
            if(!visited[i]){
            if(dfs(i , arr , visited , dfsvisited)){
            return false;
        }
            }
        } 
            return true;
        }
    
};






























// class Solution {
// public:
    
//     bool cycle(int s , vector<int>adj[] , vector<bool>&visited , vector<bool>&dfs){
        
//          visited[s] = true;
//         dfs[s] = true;
        
//         for(auto it : adj[s]){
//             A
//               if(visited[it] == false){
                  
//                    if(cycle(it , adj , visited , dfs )){
//                        return true;
//                    }
//               }else if(dfs[it] == true){
//                   return true;
//               }
//         }
        
//         //visited[s] = false;
//         dfs[s] = false;
//         return false;
//     }
//     bool canFinish(int n, vector<vector<int>>& pr) {
        
//         //question is fir directed graph
//         //i need to detect weather graph contain cycle or not
        
//         //make list
        
//         if(pr.size() == 0){
//             return true;
//         }
//         vector<int>adj[n];
//         vector<int>v;
//         for(int i = 0 ; i < pr.size() ; i++){
           
//              adj[pr[i][1]].push_back(pr[i][0]); // (0 ,1) means 1 -> 0
//         }
        
//         //check cycle , we can use dfs with two arrays 
//         //parent and dfs array
        
//         vector<bool>visited(n , false);
//         vector<bool>dfsv(n , false);
        
//         for(int i = 0 ; i < n ; i++){
            
//             if(!visited[i]){
                
//                 if(cycle(i , adj , visited , dfsv)){
//                     return false;
//                 }
//             }
//         }
        
//         return true;
//     }
// };