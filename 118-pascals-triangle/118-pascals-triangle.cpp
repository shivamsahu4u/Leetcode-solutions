class Solution {
public:
    vector<vector<int>> generate(int numRows) {
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
            for(int j = 0 ; j < i+1 ; j++){
                
                 if(j == 0)    // 0 0   0 0 + 0 1
                 ans[i][j] = ans[i-1][j];
                 else if(j == i)
                 ans[i][j] = ans[i-1][j-1];
                 else
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