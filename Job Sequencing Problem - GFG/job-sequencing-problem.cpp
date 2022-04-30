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
#include<vector>
using namespace std;
struct jobProfit {
    bool operator()(Job const& a, Job const& b)
    {
        return (a.profit < b.profit);
    }
};

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
         vector<Job> result;
    sort(arr, arr + n,
         [](Job a, Job b) { return a.dead < b.dead; });
    // set a custom priority queue
    priority_queue<Job, vector<Job>, jobProfit> pq;
    for (int i = n - 1; i >= 0; i--) {
        int slot_available;
        // we count the slots available between two jobs
        if (i == 0) {
            slot_available = arr[i].dead;
        }
        else {
            slot_available = arr[i].dead - arr[i - 1].dead;
        }
        // include the profit of job(as priority),
        // deadline and job_id in maxHeap
        pq.push(arr[i]);
        while (slot_available > 0 && pq.size() > 0) {
            // get the job with the most profit
            Job job = pq.top();
            pq.pop();
            // reduce the slots
            slot_available--;
            // add it to the answer
            result.push_back(job);
        }
    }
    // sort the result based on the deadline
    sort(result.begin(), result.end(),
         [&](Job a, Job b) { return a.dead < b.dead; });
    // print the result
    
    vector<int>att;
    int p = 0;
    for (int i = 0; i < result.size(); i++)
         p = p + result[i].profit;
           
 att.push_back(result.size());
    att.push_back(p);
    return att;
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