class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        
/* According to Wikipedia, a man named Narayana Pandita presented the following simple algorithm to solve this problem in the 14th century.

- Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just       reverse nums and done.
- Find the largest index l > k such that nums[k] < nums[l].
- Swap nums[k] and nums[l].
- Reverse the sub-array nums[k + 1:].*/
        
        
        int n = arr.size();
        int i;        
        
        for( i = n -2 ; i>=0 ; i--){
            
             if(arr[i] < arr[i + 1]){
                 
                 break;
             }
        }
        
        if(i < 0){
            
            reverse(arr.begin() , arr.end());
            
            return;
        }
        
        int l;
        
        for(l = n - 1 ; l > i ; l--){
            
            if(arr[l] > arr[i]){
                
                break;
            }
           
        }    
            swap(arr[i] ,arr[l]);
            
            reverse(arr.begin() + i + 1 , arr.end());
        
    } 
};