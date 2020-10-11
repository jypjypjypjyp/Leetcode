// 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

// 示例 1:

// 输入: 121
// 输出: true

#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    vector<unsigned char> v_char;
    long long  a = 1, b;
    while ((b = x / a) > 0)
    {
        a *= 10;
        v_char.push_back(b % 10);
    }
    int s = v_char.size();
    for (int i = 0; i < s / 2; i++)
    {
        if (v_char[i] != v_char[s - 1 - i])
            return false;
    }
    return true;
}

int main()
{
    // int a = -121;
    // cout << isPalindrome(a);
    // int b = 12321;
    // cout << isPalindrome(b);
    int c = 1234567899;
    cout << isPalindrome(c);
}