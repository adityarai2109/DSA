#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

// Insert at the end
ListNode *insertListNode(ListNode *head, int val)
{
    ListNode *temp = new ListNode();
    temp->val = val;
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        ListNode *ptr = head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
    return head;
}

// Insert at the beginning
ListNode *unshiftListNode(ListNode *head, int val)
{
    ListNode *temp = new ListNode();
    temp->val = val;
    if (head == NULL)
    {
        temp->next = NULL;
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    return head;
}

ListNode *InsertAfterListNode(ListNode *head, int val, int point)
{
    if (head == NULL)
        return head;
    ListNode *ptr = head;
    while (ptr->val != point)
        ptr = ptr->next;
    ListNode *temp = new ListNode();
    temp->val = val;
    temp->next = ptr->next;
    ptr->next = temp;
    return head;
}

ListNode *InsertBeforeListNode(ListNode *head, int val, int point)
{
    if (head == NULL)
        return head;
    if (head->val = point)
        return unshiftListNode(head, val);
    else
    {
        ListNode *ptr = head;
        ListNode *temp = new ListNode();
        temp->val = val;
        while (ptr->next->val != point)
            ptr = ptr->next;
        temp->next = ptr->next;
    }
    return head;
}

// Delete a particular ListNode
ListNode *deleteListNode(ListNode *head, int val)
{
    if (head == NULL)
        return head;
    else if (head->val == val)
    {
        ListNode *ptr = head->next;
        head = ptr;
        return head;
    }
    else
    {
        ListNode *ptr = head;
        while (ptr->next->val != val)
            ptr = ptr->next;
        ListNode *n = ptr->next;
        ptr->next = ptr->next->next;
        delete n;
        return head;
    }
}

// Printing the nexted list
void print(ListNode *head)
{
    cout << "\n";
    ListNode *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->val;
        if (ptr->next != NULL)
            cout << " -> ";
        ptr = ptr->next;
    }
    cout << "\n";
}

// Sorting the values of the nexted list
ListNode *sortll(ListNode *head)
{
    ListNode *i, *j;
    for (i = head; i != NULL; i = i->next)
        for (j = i->next; j != NULL; j = j->next)
            if (i->val > j->val)
                swap(i->val, j->val);
    return head;
}

// Reverse the even ListNodes in the nexted list
ListNode *evenreverse(ListNode *head)
{
    vector<int> ll;
    while (head != NULL)
    {
        ll.push_back(head->val);
        head = head->next;
    }
    ListNode *newhead = NULL;
    for (int i = 0; i < ll.size(); i++)
    {
        (i % 2 == 0) ? newhead = insertListNode(newhead, ll[i])
                     : newhead = insertListNode(newhead, ll[ll.size() - i]);
    }
    return newhead;
}

// Reverse the nexted list
ListNode *rev(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *next = NULL;
    ListNode *curr = head;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

// detection of a cycle
bool hasCycle(ListNode *head)
{
    if (!head)
        return false;
    ListNode *f = head;
    ListNode *s = head->next;
    while (s != NULL && s->next != NULL)
    {
        f = f->next;
        s = s->next->next;
        if (s == f)
            return true;
    }
    return false;
}

// Adding 2 reverse nexted lists
ListNode *sum(ListNode *A, ListNode *B)
{
    int a = 1, b = 1, i;
    i = 0;
    while (A != NULL)
    {
        a += A->val * pow(10, i);
        i++;
        A = A->next;
    }
    i = 0;
    while (B != NULL)
    {
        b += B->val * pow(10, i);
        i++;
        B = B->next;
    }
    a += b;
    ListNode *newList = NULL;
    while (a > 0)
    {
        newList = insertListNode(newList, a % 10);
        a /= 10;
    }
    newList = rev(newList);
    return newList;
}

// Delete duplicates in a ll
ListNode *deleteDuplicates(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *ptr = head;
    while (ptr->next != NULL)
    {
        if (ptr->val == ptr->next->val)
        {
            ListNode *n = ptr->next;
            ptr->next = ptr->next->next;
            free(n);
        }
        else
            ptr = ptr->next;
    }
    return head;
}

ListNode *mergetwoll(ListNode *A, ListNode *B)
{
    if (A == NULL)
        return B;
    if (B == NULL)
        return A;
    ListNode *newll = NULL;
    while (A != NULL || B != NULL)
    {
        if (A->val <= B->val)
        {
            newll = insertListNode(newll, A->val);
            A = A->next;
        }
        else
        {
            newll = insertListNode(newll, B->val);
            B = B->next;
        }
    }
    return newll;
}

ListNode *deleteMiddle(ListNode *head)
{
    ListNode *ptr = head;
    ListNode *ptr2 = head;
    while (ptr2 != nullptr)
    {
        ptr = ptr->next;
        ptr2 = ptr2->next->next;
    }
    cout << ptr->val;
    return head;
}

int main()
{
    ListNode *head = NULL;
    // head = insertListNode(head, 1);
    // head = insertListNode(head, 2);
    // head = insertListNode(head, 3);
    // head = insertListNode(head, 4);

    head = insertListNode(head, 1);
    head = insertListNode(head, 3);
    head = insertListNode(head, 4);
    head = insertListNode(head, 7);
    head = insertListNode(head, 1);
    head = insertListNode(head, 2);
    head = insertListNode(head, 6);

    // head = insertListNode(head, 2);
    // head = insertListNode(head, 4);
    // head = insertListNode(head, 3);
    // head = unshiftListNode(head, 1);
    // head = unshiftListNode(head, 43);
    // head = unshiftListNode(head, 54);
    // head = unshiftListNode(head, 365);
    // head = deleteDuplicates(head);
    print(head);
    head = deleteMiddle(head);
    print(head);

    // cout << "\n\nMiddlemost element : ";
    // mid(head);

    // ListNode *head2 = NULL;
    // head2 = insertListNode(head2, 5);
    // head2 = insertListNode(head2, 6);
    // head2 = InsertAfterListNode(head2, 10, 6);
    // head2 = insertListNode(head2, 4);

    // ListNode *newll = NULL;
    // newll = mergetwoll(head, head2);
    // print(newll);

    // head = deleteListNode(head, 2);

    // head = evenreverse(head);

    // ListNode *sumListNode = NULL;
    // sumListNode = sum(head, head2);
    // print(sumListNode);

    return 0;
}
