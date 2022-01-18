class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
         unordered_map<int , int>h1;
        unordered_map<int , int>h2;
        unordered_map<int , int>h3;
        for(int i = 0 ; i < edges.size() ; i++){
                   
           h3[edges[i][0]]++;
            h3[edges[i][1]]++;
            h1[edges[i][0]]++;
            h2[edges[i][1]]++;
        }
        
         int n = h3.size();
        
        for(int i = 1 ; i <= n ; i++){
            
            if(h1[i] + h2[i] == n-1){
                return i;
            }
        }
        return 0;
    }
};