class Solution {
public:
    bool backspaceCompare(string s, string t) {
       int k = -1; 
        for(int i = 0 ; i < s.size() ; i++){
            
               if(s[i] == '#' && k != -1){
                   k--;
               }else if(s[i] != '#'){
                   s[++k] = s[i];
               }
            
        
        }
        int p = -1;
        for(int i = 0 ; i < t.size() ; i++){
            
            if(t[i] == '#' && p != -1){
                p--;
            }else if(t[i] != '#'){
                t[++p] = t[i];
            }
        }
        
        if(p != k){
            return false;
        }
            
            for(int i = 0 ; i <= k ; i++){
                
                if(s[i] != t[i]){
                    return false;
                }
            }
            return true;
        
        
        
    }
};