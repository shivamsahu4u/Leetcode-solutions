class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        // Method 1 ( Brute Force)
        // TC - O(N LOG(N))
        // SC - O(1);
        
        // Method 2 ( Using Frequency Array)
        // TC - O(N)
        // SC - O(N)
        
        int arr[3] = {0};
        
        for(int i = 0 ; i < nums.size() ; i++){
            arr[nums[i]]++;
        }
        
        int j = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            
            while(arr[j] == 0){
                j++;
            }
            nums[i] = j;
            arr[j]--;
        }
        
    }
};