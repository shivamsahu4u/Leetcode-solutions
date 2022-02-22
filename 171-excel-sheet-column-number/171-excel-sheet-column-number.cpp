class Solution {
public:
    int titleToNumber(string columnTitle) {
     
        int ans = 0;
        long long int x = 0;
        long long int p = 1;
        int n = columnTitle.size();
         for(int i = n-1 ; i >=0 ; i--){
             
            long long int t = p;
             ans = ans + ( columnTitle[i] - 'A'+1)*t;
                p = p*26;
                
         }
        return ans;
    }
};