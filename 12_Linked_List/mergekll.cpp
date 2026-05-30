#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ListNode *makeLinkedList(vector<int> &v)
    {
        ListNode *res = new ListNode(v.front()), *ptr = res;
        for (int i = 1; i < v.size(); i++)
        {
            ptr->next = new ListNode(v[i]);
            ptr = ptr->next;
        }
        return res;
    }
    void print(ListNode *head)
    {
        if (head == NULL)
        {
            cout << "X\n";
            return;
        }
        cout << head->val << "->";
        print(head->next);
    }
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *a, ListNode *b)
    {
        if (a == NULL)
        {
            return b;
        }
        if (b == NULL)
        {
            return a;
        }
        ListNode *ans = new ListNode(-101), *ptr = ans;
        while (a != NULL && b != NULL)
        {
            if (a->val < b->val)
            {
                ptr->next = a;
                a = a->next;
            }
            else
            {
                ptr->next = b;
                b = b->next;
            }
            ptr = ptr->next;
        }
        while (a != NULL)
        {

            ptr->next = a;
            a = a->next;
            ptr = ptr->next;
        }
        while (b != NULL)
        {

            ptr->next = b;
            b = b->next;
            ptr = ptr->next;
        }
        return ans->next;
    }

    ListNode *mergeKLists(vector<ListNode *> &ll)
    {
        int n = ll.size();
        if (n == 1)
            return ll.back();
        ListNode *res = NULL;
        for (int i = 0; i < n; i++)
        {
            res = mergeTwoLists(res, ll[i]);
        }
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ListNode *helper;

    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {1, 2, 3, 4};
    vector<int> v3 = {1, 2, 3, 4, 5};

    ListNode *l1 = helper->makeLinkedList(v1);
    ListNode *l2 = helper->makeLinkedList(v2);
    ListNode *l3 = helper->makeLinkedList(v3);

    vector<ListNode *> ll = {l1, l2, l3};

    Solution S;
    helper->print(S.mergeKLists(ll));

    return 0;
}
