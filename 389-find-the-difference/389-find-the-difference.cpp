class Solution {
public:
    char findTheDifference(string s, string t) {
      
        unordered_map<char , int>hash;
        
        for(int i = 0 ; i < s.size() ; i++){
            hash[s[i]]++;
        }
        
        for(int j = 0 ; j < t.size() ; j++){
            
            if(hash[t[j]] == 0){
                return t[j];
            }else{
                  hash[t[j]]--;
            }
        }
        return 'c';
    }
};