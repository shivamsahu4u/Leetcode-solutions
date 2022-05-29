class Solution {
public:
    bool isPalindrome(int x) {
        
     long long y = 0 , z = x;
    
        if(x < 0){
            return false;
        }
     while(x > 0){
         
          long long p = x % 10;
         
          y = y*10 + p;
         
          x = x / 10;
     }
        
      return y == z;  
        
//         // Time Complexity is O(n)
//          int y = abs(x);
        
//          // this step takes O(n) time 
//          string st = to_string(x);
        
//         int i = 0 , j = st.size()-1;
        
//         // O(n)
//         while(i < j){
            
            
//             if(st[i] != st[j]){
//                 return false;
//             }
//             i++;
//             j--;
//         }
//         return true;
    }
};