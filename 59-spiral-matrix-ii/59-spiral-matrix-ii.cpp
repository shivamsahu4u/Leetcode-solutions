class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
     
         int i = 0 , j = 0 , d = 0 ;
        
        int **arr = new int*[n];
        for(int i = 0 ; i < n ; i++){
            arr[i] = new int[n];
            for(int j = 0 ; j < n ; j++){
                arr[i][j] = 0;
            }
        }
        int k  = 1 , traverse = 0;
        while(traverse <= n/2){
            
             while(j < n-traverse){
                 arr[i][j] = k;
                 k++;
                 j++;
             }
            
            j--;
            i++;
            
            while(i < n-traverse){
                arr[i][j] = k;
                k++;
                i++;
            }
            
            i--;
            j--;
            
            while(j >= d + traverse){
                arr[i][j] = k;
                k++;
                j--;
            }
            
            j++;
            i--;
            
            while(i > d + traverse){
                arr[i][j] = k;
                k++;
                i--;
            }
            
            i++;j++;
            traverse++;
        }
        
        vector<vector<int>>ans;
        
        for(int i = 0 ; i < n ; i++){
            vector<int>a;
            for(int j = 0 ; j < n ; j++){
                a.push_back(arr[i][j]);
            }
            ans.push_back(a);
        }
        
        return ans;
    }
};