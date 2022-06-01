class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        // o(nlogn) time complexity
        sort(nums.begin() , nums.end());
        int ans;
        
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums.size() > 1){
           if(nums[1] != nums[0]){
               ans = nums[0];
           }else{
               ans = -1;
           }    
        }
       
        for(int i = 1 ; i < nums.size() ; i++){
            
if(nums[i-1] != nums[i] && (i+1 < nums.size() && nums[i]!=nums[i+1])){
                 ans = nums[i];
             }
        }
        
        if(ans == -1){
            return nums[nums.size() - 1];
        }else{
            return ans;
        }
        
        
        // O(N) time complexity
        // O(N) space complexity
        // hashmap  // frequency array 
//         unordered_map<int,int>hash;
//         for(int i = 0 ; i < nums.size() ; i++){
//             hash[nums[i]]++;
//         }
        
//         int m = INT_MAX;
//         int index;
//         for(auto it = hash.begin() ; it!= hash.end() ; it++){
//            if(m > it->second){
//                m = it->second;
//                index = it->first;
//            }
//         }
//         return index;
        
       
    }
};