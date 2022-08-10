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
    
//     bool check(int n , vector<int>&nums , vector<int>&hash){
        
//         if(n+1 == 0){
//             return true;
//         }
        
//         if(hash[n] != -1){return hash[n];}
//         int ok = false;
        
//         if(case1(n , nums))ok=ok|check(n-2 , nums,hash);
//         if(case2(n , nums))ok=ok|check(n-3 , nums,hash);
//         if(case3(n , nums))ok=ok|check(n-3 , nums,hash);
        
//         return hash[n]=ok;
//     }
    bool dpp(vector<int>&nums , int u , int v){
        vector<int>dp(nums.size()+1 , -1);
        
        if(nums.size() == 0)
            return true;
        if(nums.size() == 1){
            return false;
        }
        dp[0] = true;
        dp[1] = false;
        if(case1(0 , nums)||case2(0,nums)||case3(0,nums))dp[1] = true;
        dp[2] = false;
        if(case1(1 , nums)||case2(1,nums)||case3(1,nums))dp[2] = true;
        
        for(int i = 3 ; i <=v ; i++){
            
             bool ok = false;
            
            if(case1(i-1 , nums))ok = ok | dp[i-2];
            if(case2(i-1 , nums))ok = ok | dp[i-3];
            if(case3(i-1 , nums))ok = ok | dp[i-3];
            
            dp[i] = ok;
        }
        
   
        return dp[v];
    }
    bool validPartition(vector<int>& nums) {
        // vector<int>hash(nums.size() , -1);
         // return check(nums.size() - 1 , nums , hash);
        return dpp(nums , 0 , nums.size() );
    }
};