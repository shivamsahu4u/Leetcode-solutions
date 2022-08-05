class Solution {
public:
     // Method 1 : Brute Force
     // Sort and find the kth largest
     // Time Complexity - O(nlogn) 
     // Space Complexity - O(1)
    int findKthLargest(vector<int>& nums, int k) {
       
     // Method 2 : Priority Queue
     priority_queue<int , vector<int> , greater<int>>pq;     
     
     for(int i = 0 ; i < k ; i++){
         pq.push(nums[i]);
         cout<<nums[i]<<" ";
     }
        
        for(int i = k ; i < nums.size() ; i++){
            
            if(pq.top() < nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        
        // while(pq.size() != 0){
        //     cout<<pq.top()<<" ";
        //     pq.pop();
        // }
        return pq.size() > 0 ? pq.top() : -1;
      
    }
};