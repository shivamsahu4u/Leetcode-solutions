class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int x = nums[0];
        int c = 1;
        for(int i = 1 ; i < nums.size(); i++){
            
            if(c == 0){
                x = nums[i];
                c = 1;
            }else if(c > 0 && nums[i] == x){
                c++;
            }else{
                c = c - 1;
            }
        }
        
        return x;
    }
};