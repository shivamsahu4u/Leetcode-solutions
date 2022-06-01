class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        // hashmap
        unordered_map<int,int>hash;
        for(int i = 0 ; i < nums.size() ; i++){
            hash[nums[i]]++;
        }
        
        int m = INT_MAX;
        int index;
        for(auto it = hash.begin() ; it!= hash.end() ; it++){
           if(m > it->second){
               m = it->second;
               index = it->first;
           }
        }
        return index;
        
        // frequency array 
    }
};