#include <iostream>
#include <stack>
using namespace std;

class CQueue
{
public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        a.push(value);
    }

    int deleteHead()
    {
        if (a.empty())
            return -1;
        while (!a.empty())
        {
            b.push(a.top());
            a.pop();
        }
        int r = b.top();
        b.pop();
        while (!b.empty())
        {
            a.push(b.top());
            b.pop();
        }
        return r;
    }

private:
    std::stack<int> a, b;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main()
{
    CQueue *obj = new CQueue();
    obj->appendTail(1);
    obj->appendTail(2);
    obj->appendTail(3);
    obj->appendTail(4);
    obj->appendTail(5);
    cout << obj->deleteHead()
         << obj->deleteHead()
         << obj->deleteHead()
         << obj->deleteHead()
         << obj->deleteHead();
}