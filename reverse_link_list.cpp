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

ListNode *reverse_linked_list(ListNode *head)
{
    if (head->next == nullptr)
        return head;

    ListNode *new_head = reverse_linked_list(head->next);

    head->next->next = head;
    head->next = nullptr;

    return new_head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    ListNode *head = nullptr;

    head = insert_val(head, v);
    head = reverse_linked_list(head);

    print_list(head);

    return 0;
}