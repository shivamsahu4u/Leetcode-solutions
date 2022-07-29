class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // 1. sort and find ( TC - O(NLOGN) SC - O(1))
        // 2. priorityQueue 
        
        priority_queue<int , vector<int> , greater<int>>pq;
        
        for(int i = 0 ; i < k ; i++){
            pq.push(nums[i]);
        }
        
        for(int i = k ; i < nums.size() ; i++){
            
            if(pq.top() < nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        
        return pq.top();
        
    }
};