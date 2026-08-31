#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job{
    char id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

int main()
{
    int n;
    cout << "Enter number of jobs : ";
    cin >> n;

    vector<Job> jobs(n);

    cout << "Enter Job ID, Deadline, Profit: " << endl;

    for(int i = 0; i < n; i++)
    {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    sort(jobs.begin(), jobs.end(), compare); // these jobs are sorted by profit

    //find maximum deadline

    int maxDeadline = 0;

    for(int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    // create slot array based on maximum deadline
    vector<char> slot(maxDeadline + 1, '-');
    vector<bool> occupied(maxDeadline + 1, false);

    int totalProfit = 0;

    //time to schedule jobs -_-

    for(int i = 0; i < n; i++)
    {
        for(int j = jobs[i].deadline; j >= 1; j--)
        {
            //start from the deadline then check if it's available
            // if not decrease
            if(!occupied[j])
            {
                occupied[j] = true;
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << endl << "Selected jobs: " << endl;

    for(int i = 1; i <= maxDeadline; i++)
    {
        if(occupied[i])
        {
            cout << "time slot " << i << "-> job " << slot[i] << endl;
        }
    }

    cout << "maximum profit = " << totalProfit << endl;
    
    return 0;
}