class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
       
     vector<int>hash(30) , curr(30);
        
        for(auto it : s1){
            hash[it - 'a']++;
        }
        
        for(int i = 0 ; i < s2.size() ; i++){
            
             curr[s2[i] - 'a']++;
            
            if(i >= s1.size()){
                curr[s2[i-s1.size()] - 'a']--;
            }
            
            if(hash == curr){
                return true;
            }
        }
        return false;
    }
};