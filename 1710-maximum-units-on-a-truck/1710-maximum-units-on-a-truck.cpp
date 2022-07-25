class Solution {
public:

     static bool comp(vector<int> a , vector<int>b){
         
         if(a[1] > b[1]){
             return true;
         }
         return false;
     }
    int maximumUnits(vector<vector<int>>& b, int t) {

         sort(b.begin() , b.end() , comp);
     
        int n = b.size();
        int j = t;
        
        int ans = 0;
        for(int i = 0 ; i < n && j > 0 ; i++){
            
            int s = b[i][0];
            int p = b[i][1];
            
            if(s >= j){
            
                ans = ans + j*p;
                j = 0;
            }else{
                
                ans = ans + (s)*p;
          
                j = j - s;
                
            }
            // cout<<j<<" ";
        }
        
        return ans;
    }
};