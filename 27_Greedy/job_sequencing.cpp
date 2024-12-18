#include <bits/stdc++.h>

class Solution2
{
public:
    static bool cmp(
        tuple<int, int, int> &a,
        tuple<int, int, int> &b)
    {
        return get<2>(a) > get<2>(b);
    }

    vector<int> JobSequencing(
        vector<int> &id,
        vector<int> &deadline,
        vector<int> &profit)
    {
        // code here
        vector<tuple<int, int, int>> jobs;
        int n = id.size(), mx_date = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            mx_date = max(mx_date, deadline[i]);
            jobs.push_back(make_tuple(id[i], deadline[i], profit[i]));
        }
        sort(jobs.begin(), jobs.end(), cmp);
        vector<int> plan(mx_date + 1, -1);
        int tasks = 0, earned = 0;
        for (int i = 0; i < n; i++)
        {
            int _id = get<0>(jobs[i]);
            int _deadline = get<1>(jobs[i]);
            int _earned = get<2>(jobs[i]);
            for (int j = _deadline; j > 0; j--)
            {
                if (plan[j] == -1)
                {
                    plan[j] = _id;
                    earned += _earned;
                    tasks++;
                    break;
                }
            }
        }
        return {tasks, earned};
    }
};

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
