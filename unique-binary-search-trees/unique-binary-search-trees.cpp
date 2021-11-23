class Solution {
public:
    
    
    long long helper(int n){
        
      long long *arr = new long long[n+3];
        arr[0] = 1;
        arr[1] = 1;
        arr[2] = 2;
        arr[3] = 5;
        
        for(int i = 4 ; i <= n ; i++){
            
            long long count = 0;
            
            for(int  j = 0 ; j < i ; j++){
                
                long long p = arr[j] * arr[i - 1 - j];
                count = count + p;
            }
            
            arr[i] = count;
        }
        
        return arr[n];
    }
    int numTrees(int n) {
       return helper(n);
       
    }
};