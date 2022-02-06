class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        //we can use unordered map
        
        map<int , int>ans;
        
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            ans[nums[i]]++;
        }
        int i = 0;
        for(auto it = ans.begin() ; it!= ans.end() ; it++){
            
             if(it->second > 1){
                 nums[i] = it->first;
                 i++;
                 nums[i] = it->first;
                 i++;
             }else{
                 nums[i] = it->first;
                 i++;
             }
        }
        
        return i;
    }
};