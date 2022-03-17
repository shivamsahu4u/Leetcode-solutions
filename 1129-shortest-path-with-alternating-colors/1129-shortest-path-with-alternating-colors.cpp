class Solution {
public:
    vector<int> red[102], blue[102];
    bool visited[102][2];
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        for(auto n : redEdges) red[n[0]].push_back(n[1]);
        for(auto n : blueEdges) blue[n[0]].push_back(n[1]);
        vector<int> dist(n, INT_MAX);
        queue<vector<int>>pq;
        for(auto it : red[0]) pq.push({it, 1, 0});              // red color = 0
        for(auto it : blue[0]) pq.push({it, 1, 1});             // blue color = 1
        dist[0] = 0;
        while(!pq.empty()){
            auto t = pq.front();
            pq.pop();
            int i = t[0];                                       // vertex
            int j = t[1];                                       // distance
            int k = t[2];                                       // color
            visited[i][k] = true;
            dist[i] = min(dist[i], j); 
            if(k == 1){
                for(auto it : red[i]){                               // if color is blue then we will traverse red edges
                    if (!visited[it][0]) pq.push({it, j + 1, 0});
                }
            }
            else if(k == 0){
                for (auto it : blue[i]){                             // if color is red then we will traverse blue edges
                    if (!visited[it][1]) pq.push({it, j + 1, 1});
                }
            }
        }
        for(int i = 0; i<n; i++){                                    // the vertex we can't reach we have to update it to -1
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist;
    }
};