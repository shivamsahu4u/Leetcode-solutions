class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        
       int ll = 1;
       int cur = 0;
        
        while(cur < label){
            cur =cur + ll;
            ll = ll*2;
        }
        
        ll = ll/2; // starting point
        int lll = 2*ll - 1;
        
        int actual = (ll + lll - label);
        int actually = (3*ll - label - 1);
        vector<int>v;
        while(label != 1){
            
             v.push_back(label);
             int ans = 3*ll-label-1;
             int a = ans/2;
             label = a;
             ll = ll/2;
        }
        
        v.push_back(1);
        reverse(v.begin() , v.end());
        
        return v;
    }
};