class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        
     vector<string>t(words.size());
        for(int i = 0 ; i < words.size() ; i++){
            string c = words[i];
            sort(c.begin() , c.end());
            t[i] = c;
        }
        
        for(int i = words.size()-1 ; i > 0 ; i--){
            
            if(t[i] == t[i-1]){
                t[i] = "$";
            }
        }
                      vector<string>ans;
                    for(int i = 0 ; i < words.size() ; i++){
                        cout<<t[i]<<" ";
                        if(t[i] != "$"){
                            ans.push_back(words[i]);
                        }
                    }
                      return ans;
    }
};