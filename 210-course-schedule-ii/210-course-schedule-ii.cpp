class Solution {
public:
    
    void dfs1(int u , vector<int>arr[] , vector<bool>&visited , vector<int>&ans){
        
        visited[u] = true;
       
        
        for(auto it : arr[u]){
          
            if(!visited[it])
            dfs1(it , arr , visited , ans);    
        }
         ans.push_back(u);
    } 
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
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>a;
      
         //cycle in directed graph
        //we can use dfs here , for that we need dfsvisited and visited array
        if(prerequisites.size() == 0){
            for(int i= 0 ; i < numCourses ; i++)
                a.push_back(i);
            
            return a;
        }
        vector<int>arr[numCourses];
        vector<int>indeegre(numCourses , 0);
        //directed graph
        for(auto path : prerequisites){
            int a = path[0];
            int b = path[1];
            arr[b].push_back(a);
            indeegre[a]++;
        }
        
   
        vector<int>ans;
        vector<bool>visited(numCourses , false);
        vector<bool>dfsvisited(numCourses , false);
        for(int i = 0 ; i < numCourses ; i++){
       
            if(!visited[i]){
            if(dfs(i , arr , visited , dfsvisited)){
            return ans;
        }
            }
        } 
            
        
               int startpoint = -1;
        
        for(int i = 0 ; i < numCourses  ;i++){
            
            if(indeegre[i] == 0){
                startpoint = i;
                break;
            }
        }
        
        if(startpoint == -1){
            return ans;
        }
        vector<bool>t(numCourses , false);
        // dfs1(startpoint , arr , t ,ans);
//         queue<int>q;
//         q.push(startpoint);
        
//         while(q.size()!=0){
            
//             int size = q.size();
            
//             for(int i = 0 ; i < size ; i++){
                
//                 int front = q.front();
//                 q.pop();
//                 if(t[front] == true){
//                     continue;
//                 }
//                 t[front] = true;
//                 ans.push_back(front);
//                 for(auto it : arr[front]){
                    
//                     if(!t[it])
//                     q.push(it);
//                 }
//             }
//         }
        
        for(int i = 0 ; i < numCourses ; i++){
            
            if(!t[i]){
                
                dfs1(i , arr , t ,ans);
            }
        }
        reverse(ans.begin() , ans.end());
        return ans;
        
        }
    
   
};






































// class Solution {
// public:
    
      
//     bool cycle(int s , vector<int>adj[] , vector<bool>&visited , vector<bool>&dfs , stack<int>&stack){
        
//          visited[s] = true;
//         dfs[s] = true;
        
//         for(auto it : adj[s]){
            
//               if(visited[it] == false){
                  
//                    if(cycle(it , adj , visited , dfs , stack)){
//                        return true;
//                    }
//               }else if(dfs[it] == true){
//                   return true;
//               }
//         }
        
//         //visited[s] = false;
//         stack.push(s);
//         dfs[s] = false;
//         return false;
//     }
//     vector<int> findOrder(int n, vector<vector<int>>& pr) {
        
//         //question is fir directed graph
//         //i need to detect weather graph contain cycle or not
        
//         //make list
        
//         // if(pr.size() == 0){
//         //    vector<int>v;
//         //              return v;
//         // }
//         vector<int>adj[n];
//         vector<int>v;
//         for(int i = 0 ; i < pr.size() ; i++){
           
//              adj[pr[i][1]].push_back(pr[i][0]); // (0 ,1) means 1 -> 0
//         }
        
//         //check cycle , we can use dfs with two arrays 
//         //parent and dfs array
        
//         vector<bool>visited(n , false);
//         vector<bool>dfsv(n , false);
//         stack<int>stack;
//         vector<int>ans;
//         for(int i = 0 ; i < n ; i++){
            
//             if(!visited[i]){
                
//                 if(cycle(i , adj , visited , dfsv , stack)){
//                     vector<int>v;
//                      return v;
//                 }
                
//                 //cycle(i , adj , visited , dfsv , ans);
//             }
//         }
        
//         while(!stack.empty()){
//             ans.push_back(stack.top());
//             stack.pop();
//         }
//         return ans;
//         //return true;
//     }
// //     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        
// //     }
// };







