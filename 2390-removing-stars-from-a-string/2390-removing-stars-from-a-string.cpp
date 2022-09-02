class Solution {
public:
    string removeStars(string s) {
       
         
        string res;
        for (char c : s)
            if (c == '*')
                res.pop_back();
            else
                res += c;
        return res;
    
        
    }
};



         // using stack
        
//         stack<char>st;
        
//         for(int i = 0 ; i < s.size() ; i++){
            
//              if(s[i] == '*'){
                 
//                  if(st.size() > 0)
//                  st.pop();
//              }else{
//                  st.push(s[i]);
//              }
//         }
        
//         s = "";
        
//         while(st.size() != 0){
//             s = st.top() + s;
//             st.pop();
//         }
        
//         return s;