class Solution {
public:
    bool isPalindrome(int x) {
        
         int y = abs(x);
        
         string st = to_string(x);
        
        int i = 0 , j = st.size()-1;
        
        while(i < j){
            
            if(st[i] != st[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};