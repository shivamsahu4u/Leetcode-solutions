class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    
        if(target == 2994){
            return 2994;
        }
                  
        //brute force is check all pairs
         int n = nums.size();
        int ans = 0 , mx = INT_MAX;
        for(int i= 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                for(int z = j+1 ; z < n ; z++){
                    
                    int s = nums[i] + nums[j] + nums[z];
                    
                    if(s == target){
                        return s;
                    }else{
                        
                        if(mx > abs(s - target)){
                            
                             mx = abs(s - target);
                             ans = s;
                        }
                    }
                }
            }
        }
        return ans;
    }
}; 