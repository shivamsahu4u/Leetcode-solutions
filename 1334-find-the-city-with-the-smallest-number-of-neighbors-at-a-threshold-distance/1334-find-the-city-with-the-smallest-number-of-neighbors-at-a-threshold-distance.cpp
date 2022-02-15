class Solution {
public:
   int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold ) {
        
      int dist[n][n];

      for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < n ; j++){
         dist[i][j] = INT_MAX;
      }
      }

      for(auto path : edges){

          dist[path[0]][path[1]] = path[2];
          dist[path[1]][path[0]] = path[2];
      }

      for(int i = 0 ; i < n ; i++){

         for(int j = 0 ; j < n ; j++){

         for(int k = 0 ; k < n ; k++){

            if(k == j || k == i || j == i){
            continue;
            }else{

              if(dist[j][i]!= INT_MAX && dist[i][k] != INT_MAX && dist[j][i] + dist[i][k] < dist[j][k]){

                  dist[j][k] = dist[j][i] + dist[i][k];
              }
            }
         }
         }
      }

   int mx = INT_MAX;
int index = 0;
     for(int i = 0 ; i < n ; i++){
      int x = 0;
     for(int j = 0 ; j < n ; j++){
             
            if(i != j && dist[i][j] <= distanceThreshold){
              x++;
            }
     }

     if(mx >= x){
       mx = x;
       index = i;
     }
     }
     return index; 
    }
};