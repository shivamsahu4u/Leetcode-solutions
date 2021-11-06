class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
         unordered_map<string, vector<string>>hash;
        vector<vector<string>>res;
        for(int i = 0 ; i < strs.size() ; i++){
            
             string ans = strs[i];
             sort(ans.begin() , ans.end());
            
            hash[ans].push_back(strs[i]);
        }
        
        for(auto it = hash.begin(); it!=hash.end() ; it++){
            res.push_back(it->second);
        }
        
        return res;
    }
};