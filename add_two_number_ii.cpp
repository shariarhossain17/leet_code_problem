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

ListNode *add_two_number(ListNode *list1, ListNode *list2)
{
    ListNode *head = new ListNode(0);

    ListNode *tmp = head;

    int rem = 0;

    while (list1 != nullptr and list2 != nullptr)
    {
        int sum = list1->val + list2->val + rem;

        tmp->next = new ListNode(sum % 10);
        rem = sum / 10;
        tmp = tmp->next;
        list1 = list1->next;
        list2 = list2->next;
    }

    while (list1 != nullptr)
    {
        int sum = list1->val + rem;

        tmp->next = new ListNode(sum % 10);
        rem = sum / 10;
        tmp = tmp->next;
        list1 = list1->next;
    }
    while (list2 != nullptr)
    {
        int sum = list2->val + rem;

        tmp->next = new ListNode(sum % 10);
        rem = sum / 10;
        tmp = tmp->next;
        list2 = list2->next;
    }

    if (rem > 0)
        tmp->next = new ListNode(rem);

    return head->next;
}

ListNode *reverseList(ListNode *head)
{

    if (head == nullptr)
        return head;

    ListNode *cur = head;
    ListNode *prev = nullptr;

    while (cur != nullptr)
    {

        ListNode *tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }

    return prev;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> v(n), v2(m);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < m; i++)
        cin >> v2[i];

    ListNode *list1 = nullptr;
    ListNode *list2 = nullptr;

    list1 = insert_val(list1, v);
    list2 = insert_val(list2, v2);

    list1 = reverseList(list1);
    list2 = reverseList(list2);

    ListNode *head = add_two_number(list1, list2);

    head = reverseList(head);
    print_list(list1);
    cout << endl;
    print_list(list2);
    cout << endl;
    print_list(head);

    // print_list(list1);
    // cout << endl;
    // print_list(list2);

    return 0;
}