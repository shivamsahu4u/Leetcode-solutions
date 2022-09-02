#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
         // unordered<string , string>hash;
         unordered_map<string,  vector<string>>h;
        
        for(int i = 0 ; i <  strs.size() ; i++){
             string a = strs[i];
             sort(a.begin() , a.end());
             h[a].push_back(strs[i]);
        }
        
        int c = 0;
        vector<vector<string>>ans;
        for(auto it : h){
            ans.push_back(it.second);
        }
        
        // cout<<c<<endl;
        
        return ans;
    }
};