class Solution {
public:
    int fourSumCount(vector<int>& x, vector<int>& y, vector<int>& z, vector<int>& p) {
        
        
        unordered_map<int , int>hash;
        
        for(int i = 0 ; i < x.size() ; i++){
            
            for(int j = 0 ; j < y.size() ; j++){
                
                hash[x[i] + y[j]]++;
            }
        }
        int count = 0;
        for(int i = 0 ; i < z.size() ; i++){
            
            for(int j = 0 ; j < p.size() ; j++){
                
                if(hash.find(-z[i]-p[j]) != hash.end()){
                    
                    auto it = hash.find(-z[i]-p[j]);
                    
                    count = count + it->second;
                }
            }
        }
        return count;
    }
};