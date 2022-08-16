class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        
        // unordered_map<int,int>hash;
        vector<int>hash(1001 , 0);
        for(int i = 0 ; i+1 < nums.size() ; i++){
            
            if(nums[i] == key){
                hash[nums[i+1]]++;
            }
        }
        int c = 0;
        int m = INT_MIN;
        for(int i  = 0 ; i < 1001 ; i++){
            
            if(hash[i] > m){
                m = hash[i];
                c = i;
            }
        }
        return c;
    }
};