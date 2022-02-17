class Solution {
public:
      vector<vector<int>>ans;
    void helper(vector<int>&can ,int i ,  int n , int tar , vector<int>v){
        
      
        if(tar == 0){
          ans.push_back(v);
            return ;
        }

        if(i ==n ){
            return ;
        }
             helper(can , i + 1 , n , tar , v);
        //we put the 2 and move forward
        if(tar >= can[i]){
             v.push_back(can[i]); 
       helper(can , i , n , tar - can[i] , v);    
         
      // helper(can , i+1 , n , tar - can[i] ,v );
     }
            
      
        
        
        
        
        //we put the 2 and again standing to put the 2
            
            
        
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
       // vector<vector<int>>ans;
         if(candidates.size() == 0){
                 return ans;
         }    
        //recursion
        vector<int>c;
         helper(candidates ,0 ,  candidates.size() , target, c);
        return ans;
    }
};