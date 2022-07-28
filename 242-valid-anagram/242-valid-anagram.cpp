class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size()){
            return false;
        }
        // constant space
        int arr[27] = {0};
        
        for(int i = 0 ; i < s.size() ; i++){
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
        }
        
        for(int i = 0 ; i < 27 ; i++){
            if(arr[i] != 0)
                return false;
        }
        return true;
    }
};