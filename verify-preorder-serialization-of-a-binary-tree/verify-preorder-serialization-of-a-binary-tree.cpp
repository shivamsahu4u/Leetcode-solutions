class Solution {
public:
    bool isValidSerialization(string preorder) {
        
         int c = 1;
       
         for(int i = 0 ; i < preorder.size() ; i++){
              if(preorder[i] == ','){
                 continue;
             }
             c--;
             
            
             
             if(c < 0)return false;
             cout<<preorder[i]<< " ";
             if(preorder[i] != '#'){
                 
                 while(i < preorder.size() && preorder[i] != ','){
                     i++;
                 }
                 c+=2;
                 
             }cout<<"-- "<<c<<" ";
         }
       if(c < 0)return false;
        return c == 0;
    }
};