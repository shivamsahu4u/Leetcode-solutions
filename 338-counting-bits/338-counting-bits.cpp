class Solution {
public:
    
    int bitcount(int n){

  int count = 0; 
   
  while(n > 0){
 
    n = n & (n-1);
    count = count + 1;
 
 }

return count;
}
    vector<int> countBits(int n) {
       
         vector<int>ans;
        
        for(int i = 0 ; i <= n ; i++){
            
            ans.push_back(bitcount(i));
        }
        return ans;
    }
};