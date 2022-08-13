class Solution {
public:
    void wiggleSort(vector<int>& nums) {

        sort(nums.begin() , nums.end());
      
        vector<int>ans({nums.begin() , nums.end()});
        // 1 1 1 4 5 6
        int j = nums.size()-1;
        for(int i = 1 ; i < nums.size() ; i+=2){
            
             ans[i] = nums[j];j--;
        }
    
        
        // int j = 0;
        for(int i = 0 ; i < nums.size() ; i+=2){
            
            ans[i] = nums[j];j--;
        }
        
  
        for(int i = 0 ; i < nums.size() ; i++){
            
            nums[i] = ans[i];
        }
        
//         for(int i = 1 ; i+1 < nums.size() ; i++){
            
//             swap(nums[i-1] , nums[i+1]);
//         }
//         1 1 1 4 5 6
//         1 4 1 1
//         1 4 5 6 1 1    
    }
};