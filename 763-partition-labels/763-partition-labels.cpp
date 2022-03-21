class Solution {
public:
    vector<int> partitionLabels(string s) {
     
        unordered_map<char ,int>hash;
        for(auto it : s){
            hash[it]++;
        }
        vector<int>v;
        unordered_map<char , bool>present;
        
        int c = 0;
        present[s[0]] = true;
        hash[s[0]]--;
        c++;
        if(hash[s[0]] == 0){
             present[s[0]] = false;
            present.erase (s[0]);
            v.push_back(c);
            c = 0;
        }
        
        for(int i = 1 ; i < s.size() ; i++){
            
             if(present[s[i]] == true){
             hash[s[i]]--;
             c++;
            if(hash[s[i]] == 0 ){
                present[s[i]] = false;
            present.erase (s[i]);
             }
                 
                 if(present.size() == 0){
                     v.push_back(c);
                     c = 0;
                 }
        }else{
                 
                 present[s[i]] = true;
                 hash[s[i]]--;
                 c++;
                 if(hash[s[i]] == 0){
                     present[s[i]] = false;
                     present.erase(s[i]);
                     if(present.size() == 0){
                          v.push_back(c);
                        c = 0;
                     }
                 }
                 
             }
}
        
        return v;
        
    }
};