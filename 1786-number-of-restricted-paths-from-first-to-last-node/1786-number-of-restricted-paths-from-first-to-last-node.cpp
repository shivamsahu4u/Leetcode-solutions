
class Solution {
			public:
				const int mod = 1e9+7;
				int dp[20005];
				int dfs(int start,vector<pair<int,int>>adj[],int n,vector<int> &dist)
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

        vector<pair<int , int>>arr[n+1];
        for(int i = 0 ; i < edges.size() ; i++){
            arr[edges[i][0]].push_back(make_pair(edges[i][1] , edges[i][2]));
            arr[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
        }
        
       // Dijkastra Algorithm  
        priority_queue<pair<int, int> , vector<pair<int ,int>>, greater<pair<int ,int>> >pq;
        pq.push({1 , n});
        vector<int>at(n+1 , INT_MAX);
        at[n] = 0;
        while(pq.size()!=0){
            
            int size = pq.size();
          
            for(int i = 0 ; i < size ; i++){
                  
                  pair<int , int>front = pq.top();
                  pq.pop();
                
                for(auto it : arr[front.second]){
                    
                  
                    if(at[front.second] + it.second < at[it.first]){
                        
                        at[it.first] = at[front.second] + it.second;
                        
                        pq.push({at[it.first] , it.first});
                    }
                }
            }
        }

          memset(dp,-1,sizeof(dp));
		  return dfs(1,arr,n,at);

	}
};