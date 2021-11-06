#include <cstdlib>
#include <iostream>
using namespace std;

// -- Time Complexity is O(max(m , n))
// -- Space Complexity is O(1)

class Solution {
public:
    int compareVersion(string version1, string version2) {
        
         int i = 0 , j = 0 , m  = version1.size() , n = version2.size();
        
        while(i < max(m,n) && j < max(n,m)){
            
            string s = "" , p = "";
            
            while(i < m && version1[i] == '0'){
                i++;
            }
            while(i < m && version1[i] != '.'){
                s = s + version1[i];
                    i++;
            }
            
            while(j < n && version2[j] == '0'){
                j++;
            }
            while(j < n && version2[j] != '.'){
                
                p = p + version2[j];
                j++;
            }
            
            int x = 0; 
               
              if(s != "")  
               x = stoi(s);
            int y = 0; 
                
              if(p!= "")
               y = stoi(p);
            cout<<s<<" "<<p<<endl;
            if(x == y){
                i++;
                j++;
            }else if(x > y){
                return 1;
            }else{
                return -1;
            }
             
        }
        
    return 0; 
    }
};
