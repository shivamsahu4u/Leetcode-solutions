class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     
        //O(n) TIME COMPLEXITY 
        //O(n) SPACE COMPLEXITY
        
        if(s.size() == 0 || s.size() == 1){
            return s.size();
        }
      unordered_map<char , int>hash;
        hash[s[0]] = 0;
        int max = 1;
        int count = 1;
        int st = 0;
        
        for(int i  = 1  ; i <s.size() ; i++){
                        
            if(hash.find(s[i]) == hash.end() || hash[s[i]] < st){     
                 count++;      
            }else{
               
                if(max < count){
                     max = count;   
                }
                
                //int so = st;
                st = hash[s[i]] + 1;
                count =  i - hash[s[i]];  
                 
                // for(int j = so ; j <= hash[s[i]] ; j++){
                //     hash.erase(s[j]);
                // }
               
            }
                
               hash[s[i]] = i; 
        }
        
       if(count > max){
           max = count;
       }
        
        return max == INT_MIN ? 0 : max;
    }
};