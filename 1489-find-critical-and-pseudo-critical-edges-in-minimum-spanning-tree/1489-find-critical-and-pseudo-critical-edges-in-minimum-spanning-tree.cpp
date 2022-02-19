class Solution {
public:
    
    int par(int ele , int parent[]){
        if(parent[ele] == ele){
            return ele;
        }
        return parent[ele] = par(parent[ele] , parent);
    }
    
    void unio(int a , int b , int parent[] , int rank[]){
        
        int x = par(a , parent);
        int y = par(b , parent);
        
        if(x == y){
            return ;
        }else{
            
            if(rank[x] < rank[y]){
                parent[x] = y;
            }else if(rank[x] > rank[y]){
                parent[y] = x;
            }else{
                parent[x] = y;
                rank[y]++;
            }
          
        }
    }
    static bool comp(vector<int>&a , vector<int>&b){
        return a[2]<b[2];
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
         for (int i = 0; i < edges.size(); ++i) {
            edges[i].push_back(i);
        }
       sort(edges.begin() , edges.end() , comp); 
        vector<vector<int>>ans;
         int sum = mst(edges , n , -1,-1);
        
        //now we have to enumerate each edge one by one
       cout<<sum<<endl;
        vector<int>critical, noncritical;
        for(int i = 0 ; i < edges.size();  i++){
        
             if(sum < mst(edges , n , i , -1)){
                 cout<<mst(edges , n , i , -1)<<endl;
                 //critical edge i.e it is must part of the mst
                 //we check for critical edge by avoiding it and see if sum is greater that mst sum
                 critical.push_back(edges[i][3]);
             }else if(sum == mst(edges , n , -1 , i)){
                 //now it means its secondary edge , pseudo edge
                 //psedo edge , isko must include karke dekha tab bhi sum mst wala hi aaya , ab iska kya matlab hua? iska matlab hai ki ye mst ka part ho sakti bhi hai nhi bhi to isko non critical edge mein daal do 
                  cout<<mst(edges , n , -1 , i)<<" -- " <<endl;
                   noncritical.push_back(edges[i][3]);
             }
        
        }
        return {critical , noncritical};
    }
    
    int mst(vector<vector<int>>&edges , int n , int blockedge , int mustinclude){
       
       
    int *parent = new int[n];
    int *rank = new int[n];
        
        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
            rank[i] = 1;
        }
      int mstsum = 0;
      
        if(mustinclude != -1){
            mstsum = mstsum + edges[mustinclude][2];
            unio(edges[mustinclude][0] , edges[mustinclude][1] ,parent , rank);
        }
       for(int i = 0 ; i < edges.size() ; i++){
           
           if(i == blockedge){
               cout<<"shsh"<<blockedge<<endl;
               continue;
           }
           
           int x = edges[i][0];
           int y = edges[i][1];
           int w = edges[i][2];
           
           int p1 = par(x , parent);
           int p2 = par(y , parent);
           
           if(p1 != p2){
               
               mstsum = mstsum + w;
               unio(p1 , p2 , parent ,rank);
           }
       }
        
        for(int i = 0 ; i < n ; i++){
            if(par(i , parent) != par(0 , parent)){
                return 1e9+7;
            }
        }
        return mstsum;
        
    }
};