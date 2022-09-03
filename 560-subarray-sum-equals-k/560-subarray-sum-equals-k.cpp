class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

    
         unordered_map<int,int>hash;
         int c = 0;
        hash[0] = 1;
          for(int i = 0 ; i < nums.size(); i++){
              
              nums[i] = nums[i] + (i-1 >= 0 ?nums[i-1] : 0);
              cout<<nums[i]<<" : "<<nums[i]-k<<" | ";
              if(hash.find(nums[i]-k) != hash.end()){
                  
                  c =c + hash[nums[i]-k];
              }
             
              hash[nums[i]]++;
          }
        
        return c;
    }
};