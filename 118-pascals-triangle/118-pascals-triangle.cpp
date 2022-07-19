class Solution {
public:
    // O(1) Time 
    // It works constant while working with whole code
    
        int find(int n , int r){
             int res = 1;
            for(int i = 0 ; i < r ; i++){
                res = res * (n-i);
                res = res/ (i+1);
            }
            return res;
        }
        vector<vector<int>> generate(int numRows) {
             
             vector<vector<int>>ans(numRows);
            
            for(int i = 0 ; i < numRows ; i++){
                
                for(int j = 0 ; j < i+1 ; j++){
                    
                     ans[i].push_back(find(i,j));
                }
            }
            return ans;
              
        }
    
    
    // Brute Force 
    // TC - O(numRows * numRows)
    // SC - O(numRows * numRows)
    
    // Better Solution
    // TC - O(numRows * numRows)
    // SC - O(numRows * numRows)
    
    // Best Solution
    // TC - O(numRows * numRows)
    // SC - O(1)
    vector<vector<int>> generat(int numRows) {
                    // 4 4
        //int matrix[30][30] = {0};
        vector<vector<int>>ans(numRows , vector<int>(numRows));
        
        if(numRows == 0){
            return ans;
        }
        
        //matrix[0][0] = 1;
        ans[0].resize(1);
        ans[0][0] = 1;
                            // 1 2 3
        for(int i = 1 ; i < numRows ; i++){
                   // 0 1  0 1 2  0 1 2 3
            ans[i].resize(i+1);
            ans[i][0] = 1 ; ans[i][i] = 1;
            for(int j = 1 ; j < i ; j++){
                
                 // if(j == 0)    // 0 0   0 0 + 0 1
                 // ans[i][j] = ans[i-1][j];
                 // else if(j == i)
                 // ans[i][j] = ans[i-1][j-1];
                 // else
                 ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
            }
            
        }
        
        // for(int i = 0 ; i < numRows ; i++){
        //     vector<int>ele;
        //     for(int j = 0 ; j < i+1 ; j++){
        //          ele.push_back(matrix[i][j]);
        //     }
        //     ans.push_back(ele);
        // }
        return ans;
    }
};