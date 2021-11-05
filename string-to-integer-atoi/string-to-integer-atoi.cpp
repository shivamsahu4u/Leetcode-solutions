class Solution {
public:
   int myAtoi(string s){
  int sign  = 1 ;long long base = 0;
 int i = 0;
   while(s[i] == ' '){
    i++;
 } // removing the blank spaces if present from the front

  //now figuring out the sign
  if(s[i] == '-' || s[i] == '+'){
   sign = 1 - 2*(s[i++] == '-');
}    

 //now getting the base value
 while(s[i] >= '0' && s[i] <= '9'){ // s[i] >= '0' && s[i] <= '9'
  base = base*10 + (s[i] - '0');
  i++;

  if(base > INT_MAX){
  return sign == 1? INT_MAX : INT_MIN;
}
} 

return (int)(sign*base);
}

 

 
};