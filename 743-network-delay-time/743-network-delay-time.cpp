#include <queue>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        //shortest distance from source to edge 
        //we can use djshstra algorithm
        //we need priority queue for that
        
     vector<pair<int ,int>>a[n]; // end , weight
        
        for(int i = 0 ; i < times.size(); i++){
            
             a[times[i][0]-1].push_back({times[i][1]-1 , times[i][2]});
        }
        
    priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>>pq;
     
    vector<int>dist(n , INT_MAX);
    vector<bool>visited(n , false);
        
        dist[k-1] = 0; 
        
        pq.push({0 , k-1}) ; // weight , source
        
         while(pq.size()!=0){
             
             pair<int , int>top = pq.top();
             pq.pop();
             int w = top.first; // start node weight
             int u = top.second; // start node 
             
             if(!visited[u]){
             visited[u] = true;
             for(auto it : a[u]){
                 cout<<" it"<<it.first<<" "<<it.second<<endl;
                 int  v = it.first; // end node
                 int weigh = it.second; //end node weight
                 
                    
                     if(w + weigh < dist[v]){
                         dist[v] = w + weigh;
                         pq.push({ dist[v] , v}); // source , weight 
                     }
                 
                 }
             }
         }
        
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            if(ans < dist[i]){
                ans = dist[i];
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};