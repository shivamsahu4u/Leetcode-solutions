// class Solution {
// public:
 
//     const int mod = 1e9+7;
//     int dp[20005];

        
//     int dfs(int u , vector<pair<int, int>>arr[] , int n , vector<int>&dist){
        
//         //if 1 is the final point only
//         if(u == n-1){
//             return 1;
//         }
        
//         if(dp[u] != -1){
//             //this means we already have all the restricted paths from source to the end
//             return dp[u];
//         }
        
//         int count = 0;
        
//         for(auto it : arr[u]){
            
//             if(dist[u] > dist[it.first]){
                
//                 count = (count + dfs(it.first , arr , n , dist)% (mod));
//             }
//         }
        
//         dist[u] = count % (mod);
//         return dist[u];
//     }
//     int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        
//         //BFS
//         vector<pair<int , int>>*arr = new vector<pair<int, int>>[n];
        
//         for(int i = 0 ; i < edges.size() ; i++){
//             arr[edges[i][0]-1].push_back(make_pair(edges[i][1]-1 , edges[i][2]));
//             arr[edges[i][1]-1].push_back(make_pair(edges[i][0]-1, edges[i][2]));
//         }
        
//         //Djkastra Algorithm
        
//         priority_queue<pair<int, int> , vector<pair<int ,int>>, greater<pair<int ,int>> >pq;
//         pq.push({0 , n-1});
//         vector<int>at(n , INT_MAX);
//         at[n-1] = 0;
//         while(pq.size()!=0){
            
//             int size = pq.size();
//             //vector<bool>visited(n , false);
//             for(int i = 0 ; i < size ; i++){
//                   // distance , point
//                   pair<int , int>front = pq.top();
//                   pq.pop();
                
//                 for(auto it : arr[front.second]){
                    
//                     //point distance
//                     if(at[front.second] + it.second < at[it.first]){
                        
//                         at[it.first] = at[front.second] + it.second;
                        
//                         pq.push({at[it.first] , it.first});
//                     }
//                 }
//             }
//         }
//             for(int i = 0 ; i < 20005 ; i++)dp[i] = -1;
//         return dfs(0 , arr , n , at );
//       return 0;
      
//     }
// };
class Solution {
			public:
				const int mod = 1e9+7;
				int dp[20005];
				int dfs(int start,vector<pair<int,int>>adj[],int n,int dist[])
				{
					if(start==n)
					{
						return 1;
					}
					if(dp[start]!=-1)
					{
						return dp[start];
					}
					int ans = 0;
					for(auto x:adj[start])
					{

						if(dist[start]>dist[x.first])
						{
							ans = (ans + dfs(x.first,adj,n,dist))%mod;
						}
					}
					return dp[start] = ans%mod;
				}

				int countRestrictedPaths(int n, vector<vector<int>>& edges) {


					int dist[n+1];
					memset(dist,INT_MAX,sizeof(dist));

					memset(dp,-1,sizeof(dp));
					vector<pair<int,int>>adj[n+1];
					for(auto x:edges)
					{
						adj[x[0]].push_back({x[1],x[2]});   
						adj[x[1]].push_back({x[0],x[2]});
					}
					bool vis[n+1];
					memset(vis,false,sizeof(vis));
					priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
					dist[n] = 0;
					pq.push({0,n});
					for(int i = 0;i<n;i++)
					{
						dist[i] = INT_MAX;
					}
					while(!pq.empty())
					{

						auto cur = pq.top();
						pq.pop();
						int u = cur.second;
						vis[u] = true;


						for(auto v:adj[u])
						{

							if(!vis[v.first]  and dist[u]!=INT_MAX and dist[u]+v.second < dist[v.first])
							{
							   dist[v.first]  = dist[u] + v.second;  
								pq.push({dist[v.first],v.first});
							}

						}
					}
					return dfs(1,adj,n,dist);

				}
			};