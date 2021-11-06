class Solution {
public:
    
    /*
    -- Time Complexity - O(26*n);
    -- Space Complexity is O(26) + O(26)
    */
    bool checkInclusion(string s1, string s2) {
     
        vector<int>x(26) ;
        vector<int>y(26) ;
        
        int n = s1.size();
        int m = s2.size();
        
        for(int i = 0 ; i < n ; i++)
            x[s1[i] - 'a']++;
        
        for(int i = 0 ; i < m ; i++){
            
            y[s2[i] - 'a']++;
            
            if(i >= n)
                y[s2[i - n]-'a']--;
            
            if(x == y)return true;
        }
        return false;
    }
};