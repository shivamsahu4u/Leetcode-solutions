class Solution {
public:
    string frequencySort(string s) {
      
         priority_queue<pair<int,char>>pq;
        
          unordered_map<char ,int>hash;
        
        for(int i = 0 ; i < s.size() ; i++){
            
             hash[s[i]]++;
        }
        
        for(auto it : hash){
            pq.push({it.second , it.first});
        }
        int i = 0;
        while(pq.size()!=0){
            
            pair<int,char>top = pq.top();
            pq.pop();
            
            while(top.first--){
                s[i] = top.second;
                i++;
            }
            
        }
        
        return s;
    }
};