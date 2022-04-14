class Solution {
public:
    
    int dp(int n){
        
        if(n == 0)return 0;
        if(n==1 || n == 2)return 1;
        int arr[n+1];
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 1;
        for(int i = 3 ; i <n+1 ; i++){
            arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
        }
        return arr[n];
    }
    
    // # Memoization
    int helper(int n , int *arr){
        
        if(arr[n] != -1){
            return arr[n];
        }
        if(n== 0){
            arr[n] = 0;
            return 0;
        }
        
        if(n == 1 || n == 2){
            arr[n] = 1;
            return 1;
        }
        
        int a1 = helper(n-1 , arr);
        int a2 = helper(n-2 , arr);
        int a3 = helper(n-3 , arr);
        
        return arr[n] = a1+a2+a3;
    }
    int tribonacci(int n) {
        
      return dp(n);  
//         int *arr = new int[n+1];
        
//         for(int i= 0 ; i < n+1 ; i++){
//             arr[i] = -1;
//         }
        
//         return helper(n , arr);
        
        // # Recursive Method : Time Limit Exceeded
//          if(n == 0){
//              return 0;
//          }
//         if(n == 1 || n == 2){
//             return 1;
//         }
        
//         return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
};