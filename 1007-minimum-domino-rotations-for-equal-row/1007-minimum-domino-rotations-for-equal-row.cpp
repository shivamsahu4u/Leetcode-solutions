#include<climits>
#include<math.h>
using namespace std;
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
     
        set<int>s;
        
        int n = tops.size(); int m = bottoms.size();
        if(n != m){
            return -1;
        }
        
        for(auto it : tops){
            s.insert(it);
        }
        for(auto it : bottoms){
            s.insert(it);
        }
        int ans = INT_MAX;
        for(auto it : s){
            
            int ele = it;
            cout<<it<<" ";
            int min = INT_MIN;
            int t = 0;
            int b = 0;
            int p = 0;
            int q = 0;
            for(int i = 0 ; i < n ; i++){
                
                if(tops[i] == ele){
                    t++;
                }else if(bottoms[i] == ele){
                    b++;
                }
                
                if(bottoms[i] == ele){
                    p++;
                }else if(tops[i] == ele){
                    q++;
                }
            }
            
            if(t + b == n){
              
                int po ;
                if(t  > b){
                    po = t;
                }else{
                    po = b;
                }
               // ans = min(ans , n - po);
                if(ans > n-po){
                    ans = n-po;
                }
            }
            
            if(p +q == n){
                
                int po ;
                if(p  > q){
                    po = p;
                }else{
                    po = q;
                }
               // ans = min(ans , n - po);
                if(ans > n-po){
                    ans = n-po;
                } 
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};