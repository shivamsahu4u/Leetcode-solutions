class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        // LETS TRY KADANE ALGO
        
        int n = nums.size();
        
        int i  = 0;
        int m = 0;
        int ans = INT_MIN;
        while(i < n){
            
            m = m + nums[i];
            
            ans = max(ans , m);
            
            if(m < 0){
                m = 0;
            }i++;
        }
        m = 0;i=0;
        while(i < n){
            
            m = m + nums[i];
            
            ans = max(abs(m) , ans);
            
            if(m > 0){
                m = 0;
            }i++;
        }
        
        
        return ans;
    }
};