class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0){
            return 0;
        }
         int *arr = new int[n+1];
        
         arr[0] = 0; arr[1] = 1;
         int m = 1;
         for(int i = 1 ; i <= n/2 ; i++){
             
             if(i*2 < n+1)
              arr[i*2] = arr[i];
             
             if(i*2+1 < n+1)
              arr[i*2 + 1] = arr[i] + arr[i+1];
             
             if(i*2 < n+1)
              m = max(m , arr[i*2]);
           
             if(i*2+1 < n+1 )
              m = max(m , arr[i*2 + 1]);
         } 
        return m;
    }
};