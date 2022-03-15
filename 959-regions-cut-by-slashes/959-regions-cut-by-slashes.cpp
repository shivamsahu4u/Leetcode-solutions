class Solution {
public:
    
    int paren(int a , vector<int>&parent){
        
        if(parent[a] == a){
            return a;
        }
        
        return parent[a] = paren(parent[a] , parent);
    }
    int regionsBySlashes(vector<string>& grid) {
     
         // since it is a square , we can take size of any edge
         int n = grid.size();
         int dots = n + 1;
         int count= 0;
        vector<int>parent(dots*dots);
        vector<int>rank(dots*dots); 
        
        for(int i = 0 ; i < dots*dots ; i++){
            parent[i] = i;
        }
        //# Here we are using UNION FIND algorithm
        
        //connected the square by their parents
        //initially all points are connected together by parent 0 only
         for(int i = 0 ; i <= n ; i++){
             
             for(int j = 0 ; j <= n ; j++){
                 
                 if(i == 0 || j == 0 || i == dots-1 || j == dots-1){
                     
                     int point = i*dots + j;
                     parent[point] = 0; 
                 }
             }
         }
        
        for(int i = 0 ; i < n ; i++){
            
            string s = grid[i];
            
            for(int j = 0 ; j < n ; j++){
                
                if(grid[i][j] == '/'){
                    
                    int p1 = (i+1)*dots + j;
                    int p2 = i*dots + (j+1);
                    
                    int par1 = paren(p1 , parent);
                    int par2 = paren(p2 , parent);
                    
                    if(par1 != par2){
                        parent[par1] = par2;
                    }else{
                        count++;
                    }
                    
                }else if( grid[i][j] == '\\'){
                    
                    int p1 = i*dots + j;
                    int p2 = (i+1)*dots + (j+1);
                    
                    int par1 = paren(p1 , parent);
                    int par2 = paren(p2 , parent);
                    
                    if(par1 != par2){
                        parent[par1] = par2;
                    }else{
                        count++;
                    }
                }
            }
        }
        return count+1;
    }
};


// class Solution {
// public:
//       int count = 1;
  
//       int paren(int ele , int par[]){
        
//         if(par[ele] == ele){
//             return ele;
//         }
        
//         int temp = paren(par[ele] , par);
//         par[ele] = temp;
//         return temp;
//     }
    
// //     void unio(int a , int b , int parent[] , int rank[]){
        
// //         int parenta = paren(a,parent);
// //         int parentb = paren(b,parent);
        
// //         if(parenta != parentb){
            
// //             if(rank[parenta] < rank[parentb]){
// //                 parent[parenta] = parentb;
// //             }else if(rank[parenta] > rank[parentb]){
// //                 parent[parentb] = parenta;
// //             }else{
// //                 parent[parentb] = parenta;
// //                 rank[parenta]++;
// //             }
// //         }else{
// //             count++;
// //         }
// //     }
    
//     int regionsBySlashes(vector<string>& grid) {
       
//         int n = grid.size();
//         int dots = n+1;
        
//         int *parent = new int[dots*dots];
//         int *rank = new int[dots*dots];
        
//         for(int i = 0 ; i < dots*dots ; i++){
//             parent[i] = i;
//             rank[i] = 1;
//         }
        
//         for(int i = 0 ; i < dots ; i++){
            
//             for(int j = 0 ; j < dots ; j++){
                
//                  if(i == 0 || j == 0 || i == dots-1 || j == dots-1){
                     
//                      int first = i*dots + j;
    
//                       if(first != 0){
//                       // unio(0 , first , parent , rank);
                       
                         
//                           parent[first] = 0;
//                       }
//                  }
//             }
//         }
        
//         for(int i = 0 ; i <grid.size() ; i++){
            
//             string s = grid[i];
//             for(int j = 0 ; j < s.size() ; j++){
                
//                 if(s[j] == '/'){
                    
//                     int first = i*dots + (j+1);
//                     int second = (i+1)*dots + j;
                    
//                     // unio(first , second , parent ,rank);
                    
//                      int x = paren(first , parent);
//                     int y = paren(second , parent);
                    
//                     if(x != y){
//                         parent[x] = y;
                       
//                     }else{
//                          count++;
//                     }
                    
//                 }else if(s[j] == '\\'){ 
                    
//                     int first = i*dots + j;
//                     int second = (i+1)*dots + (j+1);
//                      int x = paren(first , parent);
//                     int y = paren(second , parent);
                    
//                     if(x != y){
//                         parent[x] = y;
                        
//                     }else{
//                         count++;
//                     }
//                     // unio(first , second , parent , rank);
//                 }
//             }
//         }
        
//         return count;
//     }
    
  
// };