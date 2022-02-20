#define ll long long int
class Solution {
public:
    
    const int mod = 1e9 + 7;
    int dp[1000009];
    int dfs(ll u , vector<pair<int,ll>>arr[] , int n , vector<ll>& distance , vector<bool>&visited){
        
        if(dp[u]!=-1){
            return dp[u]%mod;
        }
        
        if( u == n-1){
          //  dp[u] = 1;
            return dp[u] = 1%mod;
        }
        
        // if(dist <= 0){
        //     return 0;
        // }
       
        visited[u] = true;
        ll count = 0;
        
        for(auto it : arr[u]){
            
            if(!visited[it.first] && distance[it.first] == distance[u] + (ll)it.second)
            count = ((count)%mod + (dfs(it.first , arr , n , distance , visited) % mod)) % mod;
        }
        
        visited[u] = false;
        dp[u] =  count % mod;
        return dp[u];
    }
    int countPaths(int n, vector<vector<int>>& roads) {
     
        vector<pair<int , ll>>arr[n];
        
        for(auto path : roads){
            arr[path[0]].push_back({path[1] , path[2]});
            arr[path[1]].push_back({path[0] , path[2]});
        }
        
        //first we can use Dijkastra Algorithm to find shortest distance between 1 and n
        //after that we can do dfs to find number of paths having that shortest distance to visit n
        
        vector<ll>dist(n , 1e15);
        dist[0] = 0;
        
        //we use min priority queue here in Dijkastra to find shortest distance
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
        pq.push({0 , 0}); // distance , node data
        
        while(pq.size()!=0){
            
            int size = pq.size();
            
            for(int i = 0 ; i < size ; i++){
                //distance , node data
                pair<ll, int>front = pq.top();
                pq.pop();
                
                for(auto it : arr[front.second]){
                     //   node data         distance    next node data     
                    if(dist[front.second] + it.second < dist[it.first]){
                        dist[it.first] = dist[front.second] + it.second;
                        pq.push({dist[it.first] , it.first});
                    }
                }
                
            }
        }
        

        
        vector<bool>visited(n ,false);
        memset(dp ,-1 , sizeof(dp));
        return dfs(0 , arr , n , dist , visited)% mod;
    }
};

