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
ListNode *find_kth_node(ListNode *head, int k)
{
    while (head && k--)
    {
        head = head->next;
    }
    return head;
}

ListNode *reverse_list(ListNode *tmp)
{
    ListNode *prev = nullptr;

    while (tmp)
    {
        ListNode *next = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = next;
    }

    return prev;
}

ListNode *reverse_k_group(ListNode *head, int k)
{
    ListNode *tmp = head, *next = nullptr, *prev = nullptr;

    while (tmp != nullptr)
    {
        ListNode *kthNode = find_kth_node(tmp, k - 1);

        if (kthNode == nullptr)
        {

            if (prev)
                prev->next = tmp;
            break;
        }

        next = kthNode->next;
        kthNode->next = nullptr;
        reverse_list(tmp);

        if (tmp == head)
        {
            head = kthNode;
        }
        else
        {
            prev->next = kthNode;
        }

        prev = tmp;
        tmp = next;
    }

    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    ListNode *head = nullptr;

    head = insert_val(head, v);
    head = reverse_k_group(head, k);

    print_list(head);

    return 0;
}