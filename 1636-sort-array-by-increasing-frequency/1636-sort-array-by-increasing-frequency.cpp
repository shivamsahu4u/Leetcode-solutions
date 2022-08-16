class Solution {
public:
    class cp{
  public : 
         bool operator()(pair<int,int>p , pair<int,int>q){
       
       if(p.first == q.first){
           return p.second < q.second; 
       }
       return p.first > q.first;
   }};
    vector<int> frequencySort(vector<int>& s) {
              
         priority_queue<pair<int,int> , vector<pair<int,int>> , cp>pq;
        
          unordered_map<int ,int>hash;
        
        for(int i = 0 ; i < s.size() ; i++){
            
             hash[s[i]]++;
        }
        
        for(auto it : hash){
            pq.push({it.second , it.first});
        }
        int i = 0;
        while(pq.size()!=0){
            
            pair<int,int>top = pq.top();
            pq.pop();
            
            while(top.first--){
                s[i] = top.second;
                i++;
            }
            
        }
        
        return s;
    }
};