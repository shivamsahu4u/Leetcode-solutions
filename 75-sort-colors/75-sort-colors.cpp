class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        // Method 1 ( Brute Force)
        // TC - O(N LOG(N))
        // SC - O(1);
        
        // Method 2 ( Using Frequency Array)
        // TC - O(N)
        // SC - O(1)
        
//         int arr[3] = {0}; // Constant Space
        
//         for(int i = 0 ; i < nums.size() ; i++){
//             arr[nums[i]]++;
//         }
        
//         int j = 0;
//         for(int i = 0 ; i < nums.size() ; i++){
            
//             while(arr[j] == 0){
//                 j++;
//             }
//             nums[i] = j;
//             arr[j]--;
//         }
        int i = 0 , k = nums.size()-1;
        for(int j = 0 ; j <= k;){
            
            if(nums[j] == 0){
                swap(nums[i] , nums[j]);
                i++;
                j++;
            }
            
          else if(nums[j] == 1){
                j++;
            }
            else if(nums[j] == 2){
                swap(nums[j] , nums[k]);
                k--;
            }
               
           
        }
        
    }
};