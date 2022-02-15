double t = a*it.second;
dfs(it.first , v , adj ,visited ,t);
}
}
visited[u] = false;
}
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
//we can use simple dfs for this
//time complexity - O(n) since we visit only n nodes at once
vector<pair<int , double>>adj[n];
int i = 0;
for(auto path : edges){
adj[path[0]].push_back(make_pair(path[1] , succProb[i]));
adj[path[1]].push_back(make_pair(path[0] , succProb[i]));
i++;
}
vector<bool>visited(n , false);
dfs(start , end , adj , visited , 1.0);
return mx;
}
};