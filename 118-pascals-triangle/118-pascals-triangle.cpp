class Solution {
public:
    vector<vector<int>> generate(int numRows) {
                    // 4 4
        int matrix[30][30] = {0};
        vector<vector<int>>ans;
        
        if(numRows == 0){
            return ans;
        }
        
        matrix[0][0] = 1;
        
                            // 1 2 3
        for(int i = 1 ; i < numRows ; i++){
                   // 0 1  0 1 2  0 1 2 3
            for(int j = 0 ; j < i+1 ; j++){
                
                 if(j == 0)    // 0 0   0 0 + 0 1
                 matrix[i][j] = matrix[i-1][j];
                 else
                 matrix[i][j] = matrix[i-1][j] + matrix[i-1][j-1];
            }
            
        }
        
        for(int i = 0 ; i < numRows ; i++){
            vector<int>ele;
            for(int j = 0 ; j < i+1 ; j++){
                 ele.push_back(matrix[i][j]);
            }
            ans.push_back(ele);
        }
        return ans;
    }
};