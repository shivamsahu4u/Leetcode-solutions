class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        // LETS TRY KADANE ALGO
        
        int n = nums.size();
        
        int i  = 0;
        int m = 0 , t = 0;
        int ans = INT_MIN;
        while(i < n){
            
            m = m + nums[i];
            t = t + nums[i];
            ans = max(ans , m);
            ans = max(abs(t) , ans);
            
            if(m < 0){
                m = 0;
            }
            
            if(t > 0){
                t = 0;
            }
            
            i++;
        }
        

        return ans;
    }
};