class Solution {
public:
    
    bool valid(int i , int j , int m , int n){
        if(i < 0 || j < 0 || i >=m || j >= n){
            return false;
        }
        return true;
    }
    int helper(vector<vector<int>>&grid , int i , int j , int m , int n , vector<vector<int>>&dp){
        
        if(i == m-1 && j == n-1){
            return grid[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans1 = INT_MAX, ans2 = INT_MAX;
        //moving towards right
        if(valid(i , j+1 , m , n)){
            ans1 = grid[i][j] + helper(grid , i , j+1 , m , n,dp);
        }
        //moving down
        if(valid(i+1 , j , m , n)){
            ans2 = grid[i][j] + helper(grid , i+1 , j , m , n,dp);
        }
        
        return dp[i][j] = min(ans1 , ans2);
    }
    int minPathSum(vector<vector<int>>& grid) {
          int m = grid.size();
          int n = grid[0].size();
          vector<vector<int>>dp(m , vector<int>(n , -1));
         return helper(grid , 0 , 0 , m , n , dp);
    }
};