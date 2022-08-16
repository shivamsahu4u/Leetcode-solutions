class Solution {
public:
   int f(vector<int>A){
         int r = A[0]; int n = A.size();
 
    for (int i = 1, imax = r, imin = r; i < n; i++) {
      
        if (A[i] < 0)
            swap(imax, imin);

      
        imax = max(A[i], imax * A[i]);
        imin = min(A[i], imin * A[i]);

       
        r = max(r, imax);
    }
    return r;

   }
    int maxProduct(vector<int>A) {
      // lets try through dp
        int n = A.size();
        vector<int>mx(n , 0);
        vector<int>mn(n , 0);
        mx[0] = A[0];
        mn[0] = A[0];
        int ans = A[0];
        for(int i = 1 ; i < n ; i++){
            
            if(A[i] > 0){
             mx[i] = max(A[i] , A[i]*mx[i-1]);
             mn[i] = min(A[i] , A[i]*mn[i-1]);   
            }
            else{
                mx[i] = max(A[i], A[i] * mn[i-1]);
                mn[i] = min(A[i] , A[i] * mx[i-1]);
            }
            ans = max(ans , mx[i]);
        }
        return ans;
    }
};