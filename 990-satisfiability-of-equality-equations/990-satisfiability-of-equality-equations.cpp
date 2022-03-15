class Solution {
public:
    
    int paren(int a , vector<int>parent){
        
        if(parent[a] == a){
            return a;
        }
        
        return parent[a] = paren(parent[a] , parent);
    }
    bool equationsPossible(vector<string>& equations) {
     
         vector<int>parent(27 , 0);
        
         for(int i= 0 ; i < 27 ; i++){
             parent[i] = i;
         }
        
        for(int i = 0 ; i < equations.size() ; i++){
            
             string str = equations[i];
             int a1 = str[0] - 'a';
             int a2 = str[3] - 'a';
             char si = str[1];
            
            if(si == '='){
                
                int par1 = paren(a1 , parent);
                int par2 = paren(a2 , parent);
                
                parent[par1] = par2;
            }
        }
        
         for(int i = 0 ; i < equations.size() ; i++){
            
             string str = equations[i];
             int a1 = str[0] - 'a';
             int a2 = str[3] - 'a';
             char si = str[1];
            
            if(si == '!'){
                
                int par1 = paren(a1 , parent);
                int par2 = paren(a2 , parent);
                
                if(par1 == par2){
                    return false;
                }
            }
        }
        return true;
    }
};




// class Solution {
//     vector<char>parent;
//     char find(char x) {
//        if(parent[x] == x)return x;
        
//         int temp = find(parent[x]);
        
//         parent[x] = temp;
//         return temp;
//     }
// public:
//     bool equationsPossible(vector<string>& equations) {
//         int n = equations.size();
//         parent.resize(26, 0);
//         for (int i = 0; i < 26; i++)
//             parent[i] = i;
        
//         for (int i = 0; i < n; i++) {
//             if (equations[i][1] == '=') {
//                 int x = find(equations[i][0]-'a');
//                 int y = find(equations[i][3]-'a');
//                 if (x != y)
//                     parent[y] = x;
//             }
//         }
//         for (int i = 0; i < n; i++) {
//             if (equations[i][1] == '!') {
//                 int x = find(equations[i][0]-'a');
//                 int y = find(equations[i][3]-'a');
//                 if (x == y)
//                     return false;
//             }
//         }
//         return true;
//     }
// };