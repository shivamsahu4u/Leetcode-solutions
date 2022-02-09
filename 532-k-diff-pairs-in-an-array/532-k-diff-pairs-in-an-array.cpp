class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
      
        
         unordered_map<int , int>hash;
        int count = 0;
        for(int i = 0 ; i < nums.size() ; i++){
             hash[nums[i]]++;
        }
        
        // 3 - 1
        // 4 - 1
        // 1 - 2
        // 5 - 1
        // 3 4 5 1   k = 2
        for(auto it = hash.begin() ; it!=hash.end() ; it++){
        
            // 3 , -1
            
            if(k == 0){
                
                if(hash.count(it->first - k) > 0 && hash[it->first-k] > 1){
                 cout<<it->first-k<<" "<<it->first<<endl;
                  count = count + 1;
                hash[it->first - k]=0;
              
            }
                continue;
            }
                        if(hash.count(it->first - k) > 0){
                 cout<<it->first-k<<" "<<it->first<<endl;
                  count = count + 1;
                hash[it->first - k]=0;
              
            }
            
//             if(hash.count(k + it->first) > 0){
//                cout<<k+it->first<<" "<<it->first<<endl;
//                  count = count + 1;
//                 hash[k+it->first]=0;
               
                
//             }
            
            
            
            // 3 1  = 2
//             if(hash.count(it->first - k) > 0){
//                  cout<<it->first-k<<" "<<it->first<<endl;
//                   count = count + 1;
//                 hash[it->first - k]=0;
              
//             }
        }
        return count;
        
    }
};