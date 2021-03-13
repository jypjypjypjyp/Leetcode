#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 示例 1：
// 输入：s = "We are happy."
// 输出："We%20are%20happy."

string replaceSpace(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            s.replace(s.begin() + i, s.begin() + i + 1, "%20");
        }
    }
    return s;
}

int main()
{
    string s = "We are happy.";
    cout << replaceSpace(s);
}