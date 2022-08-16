class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        // using kadane algorithm
        
        int m = 1;
        int i = 0;
        int n = nums.size();
        int ans = INT_MIN;
        while(i < n){
            
            m = m * nums[i];
            ans = max(ans , m);
            
            if(m ==0){
                m = 1;
            }
            i++;
        }
        
        i = nums.size()-1;
        m = 1;
        while(i >= 0){
            
            m = m * nums[i];
            ans = max(ans , m);
            
            if(m == 0){
                m = 1;
            }
            i--;
        }
        return ans;
    }
};