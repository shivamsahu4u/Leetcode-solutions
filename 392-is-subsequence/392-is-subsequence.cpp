class Solution {
public:
    //DYNAMIC PROGRAMMING 
    bool isSubsequence(string s, string t) {
         if(s == ""){
             return true;
         }
        
        if(t == ""){
            return false;
        }
        
        bool **ans = new bool*[s.size()];
        
        for(int i = 0 ; i < s.size() ; i++){
            
             ans[i] = new bool[t.size()];
            
            for(int j= 0 ; j < t.size() ; j++){
                
                ans[i][j] = false;
            }
        }
        
        if(s[0] == t[0]){
            ans[0][0] = true;
        }
        for(int i = 1 ; i < t.size() ; i++){
            
            if(ans[0][i-1] == true || t[i] == s[0]){
                ans[0][i] = true;
            }else{
                ans[0][i] = false;
            }
        }
        
        for(int j = 1 ; j < s.size() ; j++){
            
            ans[j][0] = false;
        }
        
        for(int i = 1 ; i < s.size() ; i++){
            
            for(int j = 1 ; j < t.size() ; j++){
                if(ans[i][j-1] == true){
                    ans[i][j] = true;
                }
                else if(ans[i-1][j-1] == true && s[i] == t[j]){
                    ans[i][j] = true;
                }else{
                    ans[i][j] = false;
                }
            }
            
           
        }
         return ans[s.size()-1][t.size()-1];
     }
};
//     bool isSubsequence(string s, string t) {
//               if(s == ""){
//              return true;
//          }
        
//         if(t == ""){
//             return false;
//         }
//          int i = 0 , j = 0;
        
//           for(i = 0 ; i < t.size() ; i++){
              
//               if(t[i] == s[j]){
//                   j++;
                  
//                   if(j == s.size()){
//                       return true;
//                   }
//               }
//           }
        
//     return false;
//     }
    //Solved by recursion
    // Recursion
    //Time Complexity - O(t.size())
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
// };