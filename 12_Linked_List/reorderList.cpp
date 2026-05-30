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
    ListNode *mid(ListNode *head)
    {
        ListNode *ptr1 = head, *ptr2 = head;
        while (ptr2->next != NULL && ptr2->next->next != NULL)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
        }
        return ptr1;
    }

    ListNode *reverse(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *rev = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return rev;
    }

    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode(-101), *ptr = ans;
        while (l1 != NULL)
        {

            if (l1 != NULL)
            {
                ptr->next = l1;
                l1 = l1->next;
                ptr = ptr->next;
            }
            if (l2 != NULL)
            {
                ptr->next = l2;
                l2 = l2->next;
                ptr = ptr->next;
            }
        }

        return ans->next;
    }

    void reorderList(ListNode *head)
    {
        ListNode *m = mid(head);
        ListNode *l2 = m->next;
        m->next = NULL;
        head = merge(head, reverse(l2));
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ListNode *helper;
    vector<int> v = {1, 2, 3, 4, 5};
    ListNode *l1 = helper->makeLinkedList(v);

    Solution S;
    S.reorderList(l1);
    helper->print(l1);

    return 0;
}
