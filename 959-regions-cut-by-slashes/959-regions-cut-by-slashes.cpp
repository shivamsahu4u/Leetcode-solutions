class Solution {
public:
      int count = 1;
  
      int paren(int ele , int par[]){
        
        if(par[ele] == ele){
            return ele;
        }
        
        int temp = paren(par[ele] , par);
        par[ele] = temp;
        return temp;
    }
    
    void unio(int a , int b , int parent[] , int rank[]){
        
        int parenta = paren(a,parent);
        int parentb = paren(b,parent);
        
        if(parenta != parentb){
            
            if(rank[parenta] < rank[parentb]){
                parent[parenta] = parentb;
            }else if(rank[parenta] > rank[parentb]){
                parent[parentb] = parenta;
            }else{
                parent[parentb] = parenta;
                rank[parenta]++;
            }
        }else{
            count++;
        }
    }
    
    int regionsBySlashes(vector<string>& grid) {
       
        int n = grid.size();
        int dots = n+1;
        
        int *parent = new int[dots*dots];
        int *rank = new int[dots*dots];
        
        for(int i = 0 ; i < dots*dots ; i++){
            parent[i] = i;
            rank[i] = 1;
        }
        
        for(int i = 0 ; i < dots ; i++){
            
            for(int j = 0 ; j < dots ; j++){
                
                 if(i == 0 || j == 0 || i == dots-1 || j == dots-1){
                     
                     int first = i*dots + j;
    
                      if(first != 0)
                      unio(0 , first , parent , rank);
                 }
            }
        }
        
        for(int i = 0 ; i <grid.size() ; i++){
            
            string s = grid[i];
            for(int j = 0 ; j < s.size() ; j++){
                
                if(s[j] == '/'){
                    
                    int first = i*dots + (j+1);
                    int second = (i+1)*dots + j;
                    
                    unio(first , second , parent ,rank);
                }else if(s[j] == '\\'){
                    
                    int first = i*dots + j;
                    int second = (i+1)*dots + (j+1);
                    
                    unio(first , second , parent , rank);
                }
            }
        }
        
        return count;
    }
    
  
};