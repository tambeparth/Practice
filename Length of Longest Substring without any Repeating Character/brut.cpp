#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int longestStr(string str)
{
    int n = str.size();
    if (n == 0)
        return 0;
    int maxlen = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        unordered_set<int> map;
        for (int j = i; j < n; j++)
        {
            if (map.find(str[j]) != map.end())
            {
                maxlen = max(maxlen, j - i);
                break;
            }
            map.insert(str[j]);
        }
    }
    return maxlen;
}

int main()
{
    string str = "abcabcbb";
    cout << "Length of Longest Substring without any Repeating Character: " << longestStr(str);
    return 0;
}