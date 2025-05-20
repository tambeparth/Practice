#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int longestStr(string str)
{
    int n = str.size();
    if (n == 0)
        return 0;
    int maxlen = 0;
    unordered_set<int> map;

    int l = 0;
    for (int r = 0; r < n; r++)
    {

        if (map.find(str[r]) != map.end())
        {
            while (l < r && map.find(str[r]) != map.end())
            {
                map.erase(str[l]);
                l++;
            }
        }
        map.insert(str[r]);
        maxlen = max(maxlen, r - l + 1);
    }
    return maxlen;
}

int main()
{
    string str = "qwertyuiop";
    cout << "Length of Longest Substring without any Repeating Character: " << longestStr(str);
    return 0;
}