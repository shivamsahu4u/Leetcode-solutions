class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        int mx = INT_MIN ; int mi = INT_MAX;
        priority_queue<int>pq;
        
         for(int i = 0 ; i < nums.size() ; i++){
             
             if(nums[i]%2 != 0){
                 
                 nums[i] = nums[i]*2;
             }
             
             mx = max(mx , nums[i]);
             mi = min(mi , nums[i]);
             pq.push(nums[i]);
         }
        
        int mind =  mx - mi;
        while(pq.top()%2 == 0){
            
            int top = pq.top();
            pq.pop();
            
            mind = min(mind , top - mi);
            
            top = top/2;
            mi = min(mi , top);
            pq.push(top);
        }
        
        mind = min(mind , pq.top() - mi);
        
        return abs(mind);
    }
};