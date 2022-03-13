class Solution {
public:
    stack<char>st;
   
    bool isValid(string s) {
        
         for(int i = 0 ; i < s.size() ; i++){
             
             if(st.size() == 0 && (s[i] == ')' || s[i] == '}' || s[i] == ']')){
                 return false;
             }
             else{
                 
                 if(s[i] == '{' || s[i] == '(' || s[i] == '['){
                     st.push(s[i]);
                 }else{
                     
                     if(st.size() > 0){
                         
                         if(s[i] == ')' && st.top() == '('){
                             st.pop();
                         }else if(s[i] == '}' && st.top() == '{'){
                             st.pop();
                         }else if(s[i] == ']' && st.top() == '['){ 
                            st.pop();
                         }else{
                             return false;
                         }
                     }
                 }
             }
         }
        
        return st.size() == 0;
    }
};