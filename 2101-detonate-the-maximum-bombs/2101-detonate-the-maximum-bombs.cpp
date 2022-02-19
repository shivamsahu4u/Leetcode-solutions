
class Solution {
public:
    long long int get(long long int a , long long int b){
        long long int x = a*a;
        long long int y  = b*b;
        int s = sqrt(x + y);
        
        return s;
    }
    int dfs(int u , vector<int>arr[] , vector<bool>&visited){
        
        visited[u] = true;
        
        int count = 1;
        for(auto it : arr[u]){
            
            if(!visited[it]){
                
                 count = count + dfs(it , arr , visited);
            
            }
        }
        
        return count;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        //Brute force
        int n = bombs.size();
        vector<int>arr[n];
        vector<int>path(bombs.size() , 0);
        for(int i = 0 ; i < bombs.size() ; i++){
            
            for(int j = 0 ; j < bombs.size() ; j++){
                
                if(i == j){
                    continue;
                }
                long long int f =(((long long int)bombs[i][0] - (long long int)bombs[j][0])*((long long int)bombs[i][0] - (long long int)bombs[j][0])) + (((long long int)bombs[i][1] - (long long int)bombs[j][1])*((long long int)bombs[i][1] - (long long int)bombs[j][1]));
                long long int r = (long long int)bombs[i][2]* (long long int)bombs[i][2];
                if(r >= f){
                    arr[i].push_back(j);
                }
            }
        }
       int mx = INT_MIN , index = 0;
        for(int i = 0 ; i < n ; i++){
            
          vector<bool>visited(n , false);
            
             int count = dfs(i , arr , visited);
            
            if(mx < count){
                mx = count;
                index = i;
            }
        }
        
        return mx;
    }
};