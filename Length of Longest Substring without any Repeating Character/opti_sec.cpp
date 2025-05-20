
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int longestStr(string s)
{
    vector<int> mpp(256, -1); // Step 1
    int left = 0, right = 0;  // Step 2
    int n = s.size();         // Step 3
    int len = 0;              // Step 4

    while (right < n)
    {                                            // Step 5
        if (mpp[s[right]] != -1)                 // Step 6
            left = max(mpp[s[right]] + 1, left); // Step 7

        mpp[s[right]] = right; // Step 8

        len = max(len, right - left + 1); // Step 9
        right++;                          // Step 10
    }
    return len;
}

int main()
{
    string s = "takeuforward";
    cout << "Length of Longest Substring without any Repeating Character: " << longestStr(s);
    return 0;
}