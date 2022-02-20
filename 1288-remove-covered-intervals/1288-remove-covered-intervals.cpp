class Solution {
public:
    
    //This is O(N*N) Approach
    
    static bool comp(vector<int>&a , vector<int>&b){
        
        if(a[0] == b[0]){
            return a[1] > b[1];
        }else{
            return a[0] > b[0];
        }
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
     
        sort(intervals.begin() , intervals.end());
        //sorting the intervals
        
        int x1 = intervals[0][0];
        int x2 = intervals[0][1];
        
        int res = 1;
        
        //firstly including the point
        
        for(int i = 1 ; i < intervals.size() ; i++){
            
            if(intervals[i][0] > x1 && intervals[i][1] > x2){
                res++;
            }
            
            if(intervals[i][1] > x2){
                
                x1 = intervals[i][0];
                x2 = intervals[i][1];
            }
        }
        return res;
    }
};

//    int c = 0;
//         for(int i = 0 ; i < intervals.size(); i++){
            
//             for(int j = 0 ; j < intervals.size() ; j++){
                
//                 if(i == j){
//                     continue;
//                 }
                
//                 if(intervals[i][0] >= intervals[j][0] && intervals[i][1] <= intervals[j][1]){
//                     c++;
//                     break;
//                 }
//             }
//         }
        
//         return intervals.size()-c;