#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
    bool isNumber(string s)
    {
        int state = 0;
        for (char c : s)
        {
            Type t = GetType(c);
            if (t == Error)
                return false;
            auto iter = map.find(pair<int, Type>(state, t));
            if (iter == map.end())
                return false;
            state = iter->second;
        }
        if (state == 2 || state == 3 || state == 5 || state == 7 || state == 8)
        {
            return true;
        }
        return false;
    }

private:
    enum Type
    {
        Digit,
        E,
        Sign,
        Dot,
        Blank,
        Error
    };

    Type GetType(char c)
    {
        if (c >= '0' && c <= '9')
        {
            return Digit;
        }
        else if (c == 'e' || c == 'E')
        {
            return E;
        }
        else if (c == '-' || c == '+')
        {
            return Sign;
        }
        else if (c == '.')
        {
            return Dot;
        }
        else if (c == ' ')
        {
            return Blank;
        }
        else
        {
            return Error;
        }
    }

    std::map<pair<int, Type>, int> map = {
        {pair<int, Type>(0, Blank), 0},
        {pair<int, Type>(0, Sign), 1},
        {pair<int, Type>(0, Digit), 2},
        {pair<int, Type>(0, Dot), 9},
        {pair<int, Type>(1, Digit), 2},
        {pair<int, Type>(1, Dot), 9},
        {pair<int, Type>(2, Digit), 2},
        {pair<int, Type>(2, Dot), 3},
        {pair<int, Type>(2, E), 4},
        {pair<int, Type>(2, Blank), 8},
        {pair<int, Type>(3, Digit), 5},
        {pair<int, Type>(3, E), 4},
        {pair<int, Type>(3, Blank), 8},
        {pair<int, Type>(4, Sign), 6},
        {pair<int, Type>(4, Digit), 7},
        {pair<int, Type>(5, Digit), 5},
        {pair<int, Type>(5, E), 4},
        {pair<int, Type>(5, Blank), 8},
        {pair<int, Type>(6, Digit), 7},
        {pair<int, Type>(7, Digit), 7},
        {pair<int, Type>(7, Blank), 8},
        {pair<int, Type>(8, Blank), 8},
        {pair<int, Type>(9, Digit), 5},
        };
};

int main()
{
    Solution a;
    string s = "3.";
    cout << a.isNumber(s) << endl;
}
