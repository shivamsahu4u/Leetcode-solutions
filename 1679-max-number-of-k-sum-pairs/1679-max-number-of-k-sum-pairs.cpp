class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
          sort(nums.begin() , nums.end());
        
        int i = 0 , j = nums.size() -1;
        int count = 0;
        while(i < j){
           // 1 3 3 3 4
             //   *   *
            if(nums[i] + nums[j] == k){
                
                if(nums[i] == nums[j]){
                // nums[i] ans nums[j] are equal
                 int c = j-i +1;
                 count = count + c/2;
                    i++;
                    j--;
                    break;
                }else{
                // they are not equal but multiple nums[i] and nums[j] exists
                  int s = i+1;
                  int p = j-1;
                    
                    while(s < nums.size() && nums[s] == nums[s-1]){
                        s++;
                    } 
                    
                    while(p >=  0 && nums[p] == nums[p+1]){
                        p--;
                    }
       //   4 5          
                    int t1 = s - i ;
                    int t2 = j - p ;
                       
                    count = count + min(t1,t2);
                    
                    i = s;
                    j = p;
                }
        
            }else if(nums[i] + nums[j]  < k){
                    i++;
            }else{
                    j--;
                }
    }
        return count;
    }
};