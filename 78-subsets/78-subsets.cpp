class Solution {
public:
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>ans;
         if(nums.size() == 0){
                  
                 vector<int>v;
                ans.push_back(v);
                 return ans;
         }
        
         vector<int>pass(nums.begin() + 1 , nums.end());
        
        vector<vector<int>>rec = subsets(pass);
        
         int number = nums[0];
        
        for(int i = 0 ; i < rec.size() ; i++){
            
            ans.push_back(rec[i]);
        }
        
        for(int i = 0 ; i < rec.size() ; i++){
            
            
            rec[i].push_back(number);
            ans.push_back(rec[i]);
        }
        
    return ans;
    }
};