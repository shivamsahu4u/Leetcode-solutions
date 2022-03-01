class Solution {
public:
        int bitcount(uint32_t n){

  int count = 0; 
   
  while(n > 0){
 
    n = n & (n-1);
    count = count + 1;
 
 }
            return count;}
    int hammingWeight(uint32_t n) {
     
        return bitcount(n);
     }
};