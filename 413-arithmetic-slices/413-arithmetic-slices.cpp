class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
     
        int n = nums.size();
        
        if(n <= 2){
            return 0;
        }
        
        int c = 2;
        int ans = 0;
        int st = nums[1] - nums[0];
        for(int i = 2 ; i  < nums.size() ; i++){
            
              if((nums[i] - nums[i-1]) == st){
                  c++;
              }else{
                  
                  if(c >= 3){
                  int t= c-2;
                  ans = ans + (t*(t+1))/2;
                  }
                  c = 2;
                  st = nums[i] - nums[i-1];
              }
            
            // if(c >= 3){
            //     ans++;
            // }
        }
         int t= c-2;
                  ans = ans + (t*(t+1))/2;
                 
        return ans;
    }
};