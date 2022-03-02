class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
                vector<int>a;
        if(n == 0)return a;
        
        if(n == 1){
            a.push_back(0);
            return a;
        }
        vector<int>indeegre(n , 0);
        vector<int>arr[n];
        
        for(auto path : edges){
            int a = path[0];
            int b = path[1];
            arr[a].push_back(b);
            arr[b].push_back(a);
            indeegre[a]++;
            indeegre[b]++;
        }
        
        queue<int>q;
        
        for(int i = 0 ; i < n ; i++){
           
            if(indeegre[i] == 1){
                q.push(i);
            }
        }
        int count = n;
        while(count > 2){
            
            int size = q.size();
            count = count - q.size();
            
            for(int i = 0 ; i < size ; i++){
                
                 int front = q.front();
                 q.pop();
                
                for(auto it : arr[front]){
                    
                     indeegre[it]--;
                   
                    
                    if(indeegre[it] == 1){
                        
                        q.push(it);
                    }
                }
            }
        }
        vector<int>ans;
        while(q.size() != 0){
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
    }
};






























































// class Solution {
// public:
//     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
//         //since we need to find root node
//         //we can make use of indeegre array
//         //since we know ,  answer will be center of gravity of graph
//         //so it may be 2 or 1 only
        
//         vector<int>a;
//         if(n == 0)return a;
        
//         if(n == 1){
//             a.push_back(0);
//             return a;
//         }
//         vector<int>arr[n];
//         vector<int>indeegre(n , 0);
        
//         for(int i = 0 ; i < edges.size() ; i++){
//             arr[edges[i][0]].push_back(edges[i][1]);
//             arr[edges[i][1]].push_back(edges[i][0]);    
//             indeegre[edges[i][0]]++;
//             indeegre[edges[i][1]]++;
//         }
        
//         queue<int>q;
        
//         for(int i = 0 ; i < indeegre.size() ; i++){
//             if(indeegre[i] == 1){
//                 q.push(i);
//             }
//         }
        
//         int count = n;
//         while(count > 2){
            
            
//              int coun = q.size();
//              count = count - q.size();
//             for(int i = 0; i < coun ; i++){
                
//                   int element = q.front();
//                   q.pop();
                
//                  for(auto it : arr[element]){
                     
//                        indeegre[it]--;
                     
//                      if(indeegre[it] == 1){
//                          q.push(it);
//                      }
//                  }
//             }
            
            
//         }
        
//         vector<int>ans;
//         while(q.size()!=0){
//             ans.push_back(q.front());
//             q.pop();
//         }
        
//         return ans;
//     }
// };