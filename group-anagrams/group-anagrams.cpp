class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        //we can improve time complexity by using not using sort
        
      map<map<char, int> , vector<string>>hash;
        vector<vector<string>>ans;
        
        int n = strs.size();
        
        for(int i = 0 ; i < n ; i++){
            
              string ans = strs[i];
              map<char , int>press;
              for(int j = 0 ; j < ans.size() ; j++){
                  press[ans[j] - 'a']++;
              }
            
            hash[press].push_back(strs[i]);
        }
        
        for(auto  it = hash.begin() ; it !=hash.end() ; it++){
            ans.push_back(it->second);
        }
        
        return ans;
        
        
        // -- Time Complexity is O(n*k*log(k)) where n is length of strs and k is length of string
        // -- Space Complexity is O(n) 
        
       /*  unordered_map<string, vector<string>>hash;
        vector<vector<string>>res;
        for(int i = 0 ; i < strs.size() ; i++){
            
             string ans = strs[i];
             sort(ans.begin() , ans.end());
            
            hash[ans].push_back(strs[i]);
        }
        
        for(auto it = hash.begin(); it!=hash.end() ; it++){
            res.push_back(it->second);
        }
        
        return res;*/
    }
};