#include <bits/stdc++.h>
using namespace std;

class ListNode
{

public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

ListNode *insert_head(ListNode *head, int x)
{

    ListNode *new_node = new ListNode(x);

    new_node->next = head;
    return new_node;
}

ListNode *insert_val(ListNode *head, vector<int> &v)
{

    int n = v.size();

    if (head == nullptr)
    {
        head = insert_head(head, v[0]);
    }

    ListNode *cur = head;

    for (int i = 1; i < n; i++)
    {
        ListNode *val = new ListNode(v[i]);

        cur->next = val;
        cur = cur->next;
    }

    return head;
}

void print_list(ListNode *head)
{
    ListNode *cur = head;

    while (cur != nullptr)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
}

ListNode *reverse_linkList_II(ListNode *head, int a, int b)
{
    if (!head || a == b)
        return head;

    ListNode *left = head;
    ListNode *right = head;

    ListNode *prev = nullptr;
    ListNode *next = nullptr;

    int dif = b - a + 1;

    while (a > 1)
    {
        prev = left;
        left = left->next;
        a--;
    }

    ListNode *sublist_tail = left;

    while (b > 1)
    {
        right = right->next;
        b--;
    }

    next = right->next;

    while (dif-- > 0)
    {
        ListNode *nxt = left->next;
        left->next = next;
        next = left;
        left = nxt;
    }

    if (prev)
        prev->next = next;
    else
        head = next;
    sublist_tail->next = left;

    return head;
}

ListNode *reverse_linked_list_II_optimal(ListNode *head, int a, int b)
{
    ListNode *dummy = new ListNode(0);

    dummy->next = head;

    ListNode *prev = dummy;

    for (int i = 1; i < a; i++)
    {
        prev = prev->next;
    }

    ListNode *cur = prev->next;

    for (int i = 0; i < b - a; i++)
    {
        ListNode *tmp = cur->next;
        cur->next = tmp->next;
        tmp->next = prev->next;
        prev->next = tmp;
    }

    return dummy->next;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    ListNode *head = nullptr;

    head = insert_val(head, v);

    // head = reverse_linkList_II(head, a, b);
    head = reverse_linked_list_II_optimal(head, a, b);

    print_list(head);

    return 0;
}