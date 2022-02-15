class Solution {
public:
    // We cant use dfs as it will give tle as we visit on the paths
    double mx = 0.0;
    
    void dfs(int u , int v , vector<pair<int , double>>adj[] , vector<bool>&visited , double a){
         cout<<"sfsf";
        if(u == v){
             cout<<"sfsf";
            if(mx < a){
                cout<<"sfsf";
                mx = a;
            }
            return ;
        }
        visited[u] = true;
        
        for(auto it : adj[u]){
            
          if(!visited[it.first]){
              
              double t = a*it.second;
              dfs(it.first , v , adj ,visited ,t);
          }
        }
        
        visited[u] = false;
    }
//     double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
//          //we can use simple dfs for this
//         //time complexity - O(n) since we visit only n nodes at once
        
//         vector<pair<int , double>>adj[n];
//         int i = 0;
//         for(auto path : edges){
//             adj[path[0]].push_back(make_pair(path[1] , succProb[i]));
//            adj[path[1]].push_back(make_pair(path[0] , succProb[i]));
//             i++;
//         }
        
//         vector<bool>visited(n , false);
        
//      //   dfs(start , end , adj , visited , 1.0);
       
        
//         queue<pair<int , double>>q;
//         q.push(make_pair(start , 1.0));
        
//         double mx = 0.0;
//         while(q.size()!=0){
            
            
                
//                 pair<int , double> front = q.front();
//                 q.pop();
//                 //visited[front.first] = true;
//                 if(front.first == end){
                    
//                      if(mx < front.second){
//                          mx = front.second;
//                      }
//                 }
                
//                 for(auto it : adj[front.first]){
                    
//                    // if(!visited[it.first])
//                     q.push(make_pair(it.first , it.second*front.second));
//                 }
//                 //visited[front.first] = false;
            
//         }
        
//         return mx;
        
        
        
        
        
        
        
        
        
        
        
//     }
     double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    vector<vector<pair<int, double>>> to(n);
        for(int i=0;i<edges.size();i++){
            to[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            to[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }
        vector<double> Prob(n, 0);
        queue<int> Q;
        Q.push(start);
        Prob[start] = 1;
        while (!Q.empty()){
            int node = Q.front();
            Q.pop();
            for (auto child : to[node]){
                int nxt = child.first;
                double p = child.second;
                if (Prob[nxt] < Prob[node] * p) Prob[nxt] = Prob[node] * p, Q.push(nxt);
            }
        }
        return Prob[end];
    }
};