class Solution {
public:
    string countAndSay(int n) {
     
         vector<string>v(n+1);
        
         v[1] = "1";
        v[2] = "11";
        for(int i = 3 ; i <= n ; i++){
            
            string ans = v[i-1];
            
            int c = 1;
            string a = "";int j;
            
            for(j = 1 ; j <ans.size() ; j++){
                 
                 if(ans[j] != ans[j-1]){
                     char t= c + '0';
                     a = a + t + ans[j-1];
                     c = 1;
                 }else{
                     c++;
                 }
            }
             
            if(c > 0){
                     char t= c + '0';
                     a = a + t + ans[j-1];
                    
            }
          
             v[i] = a;
        }
        return v[n];
        // cout<<a<<endl;
    }
};