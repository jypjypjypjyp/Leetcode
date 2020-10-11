// 罗马数字转整数

// 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

// 字符          数值
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

std::map<char, int> m =
    {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

int romanToInt(string s)
{
    vector<int> v_int;
    int last = 0, current = 0, same_char = 0, sum = 0;
    for (char c : s)
    {
        current = m[c];
        if (last == 0 || last == current)
        {
            same_char += current;
        }
        else
        {
            if (current > last)
            {
                sum += current - same_char;
                same_char = 0;
            }
            else
            {
                sum += same_char;
                same_char = current;
            }
        }
        last = current;
    }
    sum += same_char;
    return sum;
}

int main()
{
    string a = "LVIII";
    cout << romanToInt(a);
    string b = "MCMXCIV";
    cout << romanToInt(b);
}