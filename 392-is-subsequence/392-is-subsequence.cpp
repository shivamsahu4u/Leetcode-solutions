class Solution {
public:
    bool isSubsequence(string s, string t) {
        
         if(s == ""){
             return true;
         }
        
        if(t == ""){
            return false;
        }
        
        
        bool ans1 = false , ans2 = false;
        if(s[0] != t[0])
         ans1 = isSubsequence(s , t.substr(1));
        
        if(s[0] == t[0])
         ans2 = isSubsequence(s.substr(1) , t.substr(1));
        
        return ans1||ans2;
    }
};