class Solution {
public:
    
    static bool comp(pair<int , int>a , pair<int , int>b){
        
        return a.second < b.second;
    }
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        int indeegre[n];
        
        for(int i = 0 ; i < n ; i++)
            indeegre[i] = 0;
        
        int mat[n][n];
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                
                mat[i][j] = 0;
            }
        }
        
        for(auto path : roads){
            indeegre[path[0]]++;
            indeegre[path[1]]++;
            mat[path[0]][path[1]] = 1;
            mat[path[1]][path[0]] = 1;
        }
        
        vector<pair<int , int>>v;
        
        for(int i = 0 ; i < n ; i++){
            
            v.push_back(make_pair(i , indeegre[i]));
        }
        
        sort(v.begin() , v.end() , comp);
        int mx = INT_MIN;
        for(int i = 0 ; i < v.size() ; i++){
            
            for(int j = 0 ; j  < v.size() ; j++){
                
                if(i == j){
                    continue;
                }
                int ans = v[i].second + v[j].second;
                
                if(mat[v[i].first][v[j].first] == 0){
                    
                    if(mx < ans){
                        mx = ans;
                    }
                }else{
                    if(mx < (ans-1)){
                        mx = ans-1;
                    }
                }
            }
        }
        
        return mx;
        
    }
};