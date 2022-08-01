class Solution {
public:
    int minimumOperations(vector<int>& nums) {
     // space is constant so SC - O(1)
        vector<int>v(101 , 0);
        
        for(int i = 0 ; i < nums.size() ; i++){
            v[nums[i]] = 1;
        }
        int count = 0;
        for(int i = 1 ; i < v.size() ; i++){
            
            if(v[i] == 1){
               cout<<i<<" ";
                count++;
            }
        }
        return count;
//          priority_queue<int , vector<int> , greater<int>>pq;
        
//         for(int i = 0 ; i < nums.size() ; i++){
            
//             if(nums[i] != 0){
//                 pq.push(nums[i]);
//             }
//         }
        
//         int c  = 0 , p = 0;
        
//         while(pq.size() != 0){
            
//              int e = pq.top() - p;
//              pq.pop();
           
//              p = p + e;
            
//              if(e != 0)   // checking for the duplicates
//              c = c + 1;
            
         
//         }
        
//         return c;
        
    }
};