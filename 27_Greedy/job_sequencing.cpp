#include <bits/stdc++.h>

struct Job
{
    int id;       // Job Id
    int deadline; // Deadline of job
    int profit;   // Profit if job is over before or on deadline
};

class Solution
{
public:
    // TODO Disjoint set

    static bool cmp(Job &a, Job &b) { return a.profit > b.profit; }

    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job jobs[], int n)
    {
        // your code here
        sort(jobs, jobs + n, cmp);

        int max_deadline = 0;
        for (int i = 0; i < n; i++)
            max_deadline = max(max_deadline, jobs[i].deadline);

        vector<int> planning(max_deadline + 1, -1);
        int tasks = 0, profit = 0;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = jobs[i].deadline; j > 0; j--)
            {
                if (planning[j] == -1)
                {
                    planning[j] = jobs[i].id;
                    tasks++;
                    profit += jobs[i].profit;
                    break;
                }
            }
        }
        return {tasks, profit};
    }
};

int main()
{
    FAST_IO

    return 0;
}
