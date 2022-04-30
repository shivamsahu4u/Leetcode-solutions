// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
struct jobProfit {
    bool operator()(Job const& a, Job const& b)
    {
        return (a.profit < b.profit);
    }
};
class Solution 
{
    public:
    static bool comp(Job a, Job b){
        return a.dead < b.dead;
    }
    static bool com(Job a , Job b){
        return a.profit < b.profit;
    }
    vector< int> JobScheduling(Job arr[], int n) 
    { 
       // sorting the arr in the accending order
       sort(arr , arr+n , comp);
       
       priority_queue<Job , vector<Job> ,jobProfit>pq;
       int c = 0 , pre= 0;
       for(int i = n-1 ; i >=0 ; i--){
           
           int slotsInterval;
           
           if(i == 0){
               slotsInterval = arr[i].dead;
           }else{
               slotsInterval = arr[i].dead - arr[i-1].dead;
           }
           
           pq.push(arr[i]);
           
           while(pq.size() > 0 && slotsInterval > 0){
               
               Job job = pq.top();
               pq.pop();
               pre = pre + job.profit;
               c = c + 1;
               slotsInterval--;
           }
       }
       
       vector<int>a;
       a.push_back(c);
       a.push_back(pre);
       return a;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends