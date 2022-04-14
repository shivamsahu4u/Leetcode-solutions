class Solution {
public:
    int maxProduct(vector<int>& nums) {
      
        // answer will either start from left or right
        // answer can be negetive or postivie
        // so lets say if answer lies in middle
        // a ans b
        // + ans + , + ans - , - ans + , - ans -
    // -   left or right  , right , left , left or right
    // +   left*right*mid , left * mid , mid * right , left*mid*right
        
        int m = INT_MIN;
        int ans = 1;
        for(int i = 0 ; i < nums.size() ; i++){
            
            ans = ans*nums[i];
            m = max(m ,ans);
            
            if(nums[i] == 0){
                ans = 1;
            }
        }
        ans = 1;
        for(int i = nums.size()-1 ; i >=0 ; i--){
            
            ans = ans*nums[i];
            m = max(m ,ans);
            
            if(nums[i] == 0){
                ans = 1;
            }
        }
        
        return m;
    }
};