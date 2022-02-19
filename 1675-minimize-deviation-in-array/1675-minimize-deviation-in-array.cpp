class Solution {
public:
    //Minimum deviation 
    
    //in this we have to notice two points
    //1. we can increase the even numbers 
    
    //intution : Intution is to increase the odd numbers and decrease the even numbers so as to decrease the gap between the min and max
    //for example - [1 2 3 4] we increase the numbers to its highest values first
    // its be like [2 2 6 4] now we decrease the hightest number to achieve the minimum difference
    // we start decreasing the even numbers step by step so to get closer to the min numbers , once top is odd we can decrease it anymore
    // 2 2 4 3  // 2 2 2 3  // 3 - 2 = 1 Ans
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