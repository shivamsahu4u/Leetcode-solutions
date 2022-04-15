class Solution {
public:
    
    int ans = INT_MIN;
    void recursion(vector<int>&nums , int u , int v , int m , int count ){
        
        if(u == v){
         if(count > ans){
             ans = count;   
         }
            return;
        }
        
        
        if(nums[u] > m){
            recursion(nums , u+1 , v , nums[u] , count+1 );
           // recursion(nums , u+1 , v , m , count);
            
        }
          recursion(nums , u+1 , v , m , count );
        
    }
    int dp(vector<int>&nums){
        int n = nums.size();
        int *arr = new int[n+1];
        arr[0] = 1;
        int u = 1;
        for(int i = 1 ; i < n ; i++){
            int m  = INT_MIN;
            int ind = -1;
            int mx = INT_MIN;
            for(int j = i-1 ; j >=0 ; j--){
                
                if(nums[j] < nums[i]){
                
                    if(mx < arr[j]){
                        mx = arr[j];
                        m = nums[j];
                        ind = j;
                    }
                }
            }
            
            if(m == INT_MIN){
                arr[i] = 1;
            }else{
                arr[i] = arr[ind] + 1;
            }
            
            u = max(u , arr[i]);
        }
        for(int i = 0 ; i < n ; i++){
            cout<<arr[i]<<" ";
        }
        return u;
    }
    int lengthOfLIS(vector<int>& nums) {
        
        //#recursion
        
         return dp(nums);
         // recursion(nums , 0 , nums.size() , INT_MIN , 0 , arr);
         // return ans;
    }
};