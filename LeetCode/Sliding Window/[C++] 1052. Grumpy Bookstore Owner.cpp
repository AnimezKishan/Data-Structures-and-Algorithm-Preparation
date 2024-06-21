class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int unsat = 0;

        // Initial Unsatisfied Customers for the first 'minutes' window
        for(int i=0; i<minutes; i++)
            unsat += customers[i] * grumpy[i];
        
        int i = 0, j = minutes, maxUnsat = unsat;

        // Using Sliding-Window, find out the window with max unsatisfied customers
        while(j < n){
            unsat += customers[j] * grumpy[j]; 
            unsat -= customers[i] * grumpy[i]; 

            maxUnsat = max(maxUnsat, unsat);
            i++;
            j++;
        }

        int totalCustomers = maxUnsat;
        
        // Add all satisfied customers
        for(int i=0 ;i<n; i++)
            totalCustomers += customers[i] * (1 - grumpy[i]);

        return totalCustomers;
    }
};