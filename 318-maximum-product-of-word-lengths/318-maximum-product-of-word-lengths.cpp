#include<climits>
#include<math.h>
using namespace std;
class Solution {
public:
    
    bool comp(string s , string t){
        
        return s.size() < t.size();
    }
    int maxProduct(vector<string>& words) {
      
         // rows containing the actual words
        // columns containing the hashmap type
         int arr[words.size()][1000];
         
         // initialise
         memset(arr , 0 , sizeof arr);
         
        
        for(int i= 0 ; i < words.size() ; i++){
            
             int  l = words[i].size();
            
            for(int j = 0 ; j < l ; j++){
                
                arr[i][words[i][j]] = 1;
            }
        }
        // descending order for the string 
        // sort(words.begin()  , words.end());
        
        
        // maximum of all 
        int mx = 0;
        
        for(int i = 0 ; i < words.size() ; i++){
            
            for(int j = i+1 ; j < words.size() ; j++){
                int f = 0;
                 for(int k = 0; k < words[j].size() ; k++){
                     
                      if(arr[i][words[j][k]] == 1){
                          f = 1;
                          break;
                 }
                 }
                
                if(f != 1){ 
                    // cout<<words[i] << " "<< words[j] << endl;
                    int ty = words[i].size()*words[j].size();
                    mx = max(mx , ty);
                }
            }
        }
        return mx;
    }
};