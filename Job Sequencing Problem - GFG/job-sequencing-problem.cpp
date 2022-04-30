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

class Solution 
{
    public:
    static bool comp(Job a , Job b){
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
         //sort with decreasing order of the profit
         //so that we can choose mazmimum profit first
         
         sort(arr , arr+n ,comp);
         
         // now we need to maintain slots , weather we can do job at a particular slot
         // or not
         // for this we maintain a slot array and will try to o work at last time of 
         // the slot , so that maximum jobs can ne done
       
        int mx = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            mx = max(mx , arr[i].dead);
        }
        
        //initially all slots are empty
        vector<bool>slots(mx+1 , false);
        int c = 0 , pro = 0;
        for(int i = 0 ; i < n ; i++){
            
            for(int j = arr[i].dead ; j > 0 ; j--){
                
                if(slots[j] == false){
                    // slot is empty ,so we can do job in this slot
                    
                    c++;
                    pro = pro + arr[i].profit;
                    slots[j] = true;
                    break;
                }
            }
        }
        vector<int>ans;
        ans.push_back(c);
        ans.push_back(pro);
        return ans;
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