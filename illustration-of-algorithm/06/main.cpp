#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<int> reversePrint(ListNode *head)
{
    stack<int> s;
    ListNode* p = head;
    while(p->next!=NULL)
    {
        s.push(p->val);
        p = p->next;
    }
    s.push(p->val);
    vector<int> r;
    while (!s.empty())
    {
        r.push_back(s.top());
        s.pop();
        cout << r[r.size() -1]<<endl;
    }
    return r;
}

int main()
{
    ListNode a(1),b(3),c(2);
    a.next=&b;b.next=&c;
    auto r = reversePrint(&a);

}