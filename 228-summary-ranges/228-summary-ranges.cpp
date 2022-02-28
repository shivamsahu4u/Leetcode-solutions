class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
     vector<string>ans;
        if(nums.size() == 0){
            return ans;
        }
        
        string pre = to_string(nums[0]);
        string cur = "";
        for(int i = 1 ; i < nums.size() ; i++){
            
             if(nums[i] != nums[i-1] + 1){
                 if(cur == ""){
                     string c = pre;
                     ans.push_back(c);
                 }else{
                     string a = pre;
                     string d = cur;
                     string s = a + "->" + d;
                     ans.push_back(s);
                 }
                 pre = "";
                 cur = "";
             }
            
            if(pre == ""){
                pre = to_string(nums[i]);
            }else{
                cur = to_string(nums[i]);
            }
        }
        
         if(cur == ""){
                     string c = pre;
                     ans.push_back(c);
                 }else{
                     string a = pre;
                     string d = cur;
                     string s = a + "->" + d;
                     ans.push_back(s);
                 }
        
        return ans;
    }
};