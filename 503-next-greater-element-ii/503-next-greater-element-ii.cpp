class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
         stack<int>s;
         map<int,int>hash;
         int n = nums.size();
        
         for(int i =2*n-1 ; i >=0 ; i--){
            
            while(s.size() && nums[s.top()] <= nums[i % n]){
                 s.pop();
            }
            
            if(s.size() == 0 ){
                 hash[i%n] = -1;
            }else{
                hash[i%n] = s.top();
            }
            
            
            s.push(i % n);
         }
        vector<int>ans;
         for(int i = 0 ; i < n ; i++){
             
             if(hash[i] != -1)
             ans.push_back(nums[hash[i]]);
             else
             ans.push_back(-1);
         }
        
        return ans;
    }
};