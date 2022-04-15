// class Solution {
// public:
//     int lengthOfLIS(vector<int>& A) {
//         int len = 0;
//         for(auto cur : A) 
//             if(len == 0 || A[len-1] < cur) A[len++] = cur;             // extend
//             else *lower_bound(begin(A), begin(A) + len, cur) = cur;    // replace
//         return len;
//     }
// };
class Solution {
public:
    
   // #Recursion
    int ans = INT_MIN;
    void recursion(vector<int>&nums , int u , int v , int m , int count ){
        // since we have 2 choices for each index
        // so TC - O(2^n) SC - O(N) (recursion stack)
        if(u == v){
         if(count > ans){
             ans = count;   
         }
            return;
        }
        
        if(nums[u] > m){
            // either included
          recursion(nums , u+1 , v , nums[u] , count+1 );  
        }
        // not included , searching of any other small element
          recursion(nums , u+1 , v , m , count );
    }
    
    // # Memoization TC - O(N2) SC - O(N2)
    int memoization(vector<int>&nums , int u  , int v , int pre , vector<vector<int>>&mem){
        
        if(u == v){
            return 0;
        }
        
         if(mem[u][pre+1]!=-1){
            return mem[u][pre+1];
         }
        
         int include = 0 , notinclude = 0;
         if(pre == -1 || nums[u] > nums[pre]){
             include = 1+ memoization(nums , u+1 , v , u , mem);
         }
        
           notinclude = memoization(nums , u+1 , v , pre , mem);
        
        mem[u][pre+1] = max(include, notinclude);
        return mem[u][pre+1];
    }
    
    // #Dynamic Programming  TC-O(N2) SC - O(N)
    int dp(vector<int>&nums){
        int n = nums.size();
       vector<int>arr(n+1 , 1);
        arr[0] = 1;
        int u = 1;
        for(int i = 1 ; i < n ; i++){
            
            for(int j = i-1 ; j >=0 ; j--){
                
                if(nums[j] < nums[i]){
                
                    arr[i] = max(arr[i] , arr[j] + 1);
                    
                }
            }
            
            u = max(u , arr[i]);
        }

        return u;
    }
    
    // Further we can reduce this time complexity using a trick
    // we can use binary search to optimise the time complexity to O(nlogn)
    // we can use same array or diff array for the changes
    int binary(vector<int>&nums){
        
         int len = 0;
         
          for(int i = 0 ; i < nums.size() ; i++){
              
               if(len == 0 || nums[i] > nums[len-1]){
                   nums[len++] = nums[i];
               }else{
                   //else find the smallest element , larger than nums[i] and replace that with this
                   *lower_bound(begin(nums) , begin( nums) + len , nums[i]) = nums[i];
               }
          }
        return len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        // #recursion
        // int n = nums.size();
        // vector<vector<int>>mem(n , vector<int>(n+1 , -1));
        // return memoization(nums , 0 , n ,-1, mem);
         // return dp(nums);
         // recursion(nums , 0 , nums.size() , INT_MIN , 0 , arr);
         // return ans;
        return binary(nums);
    }
};