class Solution {
public:
    
    bool isSubsequence(string s, string t) {
              if(s == ""){
             return true;
         }
        
        if(t == ""){
            return false;
        }
         int i = 0 , j = 0;
        
          for(i = 0 ; i < t.size() ; i++){
              
              if(t[i] == s[j]){
                  j++;
                  
                  if(j == s.size()){
                      return true;
                  }
              }
          }
        
    return false;
    }
    //Solved by recursion
    // Recursion
//     bool isSubsequence(string s, string t) {
        
//          if(s == ""){
//              return true;
//          }
        
//         if(t == ""){
//             return false;
//         }
        
        
//         bool ans1 = false , ans2 = false;
//         if(s[0] != t[0]){
//          ans1 = isSubsequence(s , t.substr(1));
//          if(ans1){
//              return true;
//          }
//         }
        
//         if(s[0] == t[0]){
//          ans2 = isSubsequence(s.substr(1) , t.substr(1));
//          if(ans2){
//              return true;
//          }
//         }
//         return ans1||ans2;
//     }
};