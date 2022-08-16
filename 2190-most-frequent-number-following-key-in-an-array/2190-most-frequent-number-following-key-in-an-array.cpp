class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        
        unordered_map<int,int>hash;
        for(int i = 0 ; i+1 < nums.size() ; i++){
            
            if(nums[i] == key){
                hash[nums[i+1]]++;
            }
        }
        int c = 0;
        int m = INT_MIN;
        for(auto it : hash){
            if(it.second > m){
                m = it.second;
                c = it.first;
            }
        }
        return c;
    }
};