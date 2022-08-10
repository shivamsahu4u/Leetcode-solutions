class Solution {
public:
    
    bool case1(int ind , vector<int>&nums){
        return (ind >=1 && nums[ind] == nums[ind-1]);
    }
     bool case2(int ind , vector<int>&nums){
        return (ind >=2 && nums[ind] == nums[ind-1] && nums[ind-1]== nums[ind-2]);
    }
     bool case3(int ind , vector<int>&nums){
          return (ind >=2 && nums[ind]-1 == nums[ind-1] && nums[ind-1]-1== nums[ind-2]);   
    }
    
    bool check(int n , vector<int>&nums , vector<int>&hash){
        
        if(n+1 == 0){
            return true;
        }
        
        if(hash[n] != -1){return hash[n];}
        int ok = false;
        
        if(case1(n , nums))ok=ok|check(n-2 , nums,hash);
        if(case2(n , nums))ok=ok|check(n-3 , nums,hash);
        if(case3(n , nums))ok=ok|check(n-3 , nums,hash);
        
        return hash[n]=ok;
    }
    bool validPartition(vector<int>& nums) {
        vector<int>hash(nums.size() , -1);
         return check(nums.size() - 1 , nums , hash);
    }
};