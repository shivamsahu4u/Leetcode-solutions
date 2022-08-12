class Solution {
public:
    
    
    int partition(vector<int>&nums , int u , int v){
        
      int last = nums[v];
      
      int count = u;
        
        for(int i = u ; i < v ; i++){
            
            if(nums[i] <= last){
                 
                count++;
            }
        }
  
        swap(nums[count] , nums[v]);
       
        int i = u , j= count + 1;
        
        while(i < count && j <= v){
            
             while(i < count && nums[i] <= last){
                 i++;
             }
            
            while(j <= v && nums[j] > last){
                j++;
            }
            
            if(i < count && j <= v){
                swap(nums[i] , nums[j]);
                i++;
                j++;
            }
        }
      
        return count;
                  
    }
    int quick(vector<int>& nums , int u , int v , int k){
        
         int par = partition(nums , u , v);
        
        if(u > v){
            return  0;
        }
        if(par == k){
            return nums[par];
        }
        
         if(k < par){
             return quick(nums , u , par-1 , k);
            
         }else{
             return quick(nums , par+1 , v , k);
         }
        return -1;
    }
    int findKthLargest(vector<int>& nums, int k) {
        
         // quick select method
        
 return quick(nums , 0 , nums.size() - 1 , nums.size()-k);
  
    }
};


 // Method 1 : Brute Force
     // Sort and find the kth largest
     // Time Complexity - O(nlogn) 
     // Space Complexity - O(1)
    // int findKthLargest(vector<int>& nums, int k) {
       
     // Method 2 : Priority Queue
// Time C - O(k + nlogk)
// Space C - O(k)
//      priority_queue<int , vector<int> , greater<int>>pq;     
     
//      for(int i = 0 ; i < k ; i++){
//          pq.push(nums[i]);
//          cout<<nums[i]<<" ";
//      }
        
//         for(int i = k ; i < nums.size() ; i++){
            
//             if(pq.top() < nums[i]){
//                 pq.pop();
//                 pq.push(nums[i]);
//             }
//         }
        
        // while(pq.size() != 0){
        //     cout<<pq.top()<<" ";
        //     pq.pop();
        // }
     //   return pq.size() > 0 ? pq.top() : -1;
      
   // }