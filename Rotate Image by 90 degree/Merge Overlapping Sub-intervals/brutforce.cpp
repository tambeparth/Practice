#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int size = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;

    for (int i = 0; i < size; i++)
    {
        int startTime = intervals[i][0];
        int endTime = intervals[i][1];

        if (!merged.empty() && endTime <= merged.back()[1])
        {
            continue;
        }

        for (int j = i + 1; j < size; j++)
        {
            if (intervals[j][0] <= endTime)
            {
                endTime = max(endTime, intervals[j][1]);
            }
            else
            {
                break;
            }
        }
        merged.push_back({startTime, endTime});
    }
    return merged;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> result = mergeIntervals(intervals);
    cout << "Merged intervals: " << "\n";
    for (auto interval : result)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}
