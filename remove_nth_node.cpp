#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

Node *insert_head(int x, Node *head)
{
    Node *newNode = new Node(x);
    newNode->next = head;
    return newNode;
}

Node *insert_val(int n, vector<int> &v, Node *head)
{
    if (head == nullptr)
        head = insert_head(v[0], head);

    Node *tmp = head;

    for (int i = 1; i < n; i++)
    {
        Node *val = new Node(v[i]);
        tmp->next = val;
        tmp = tmp->next;
    }

    return head;
}

void print_list(Node *head)
{
    Node *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->val << " ";

        tmp = tmp->next;
    }
}

int cout_node(Node *head)
{
    Node *curr = head;

    int cnt = 0;
    while (curr != nullptr)
    {
        cnt++;

        curr = curr->next;
    }

    return cnt;
}

Node *removeHead(Node *head)
{

    if (head == nullptr)
        return nullptr;

    Node *cur = head;
    head = head->next;
    delete cur;
    return head;
}

Node *removeNth(Node *head, int sz)

{

    if (head == nullptr)
        return nullptr;

    Node *cur = head;
    Node *prev = cur;

    for (int i = 0; i < sz; i++)
    {
        prev = cur;
        cur = cur->next;
    }

    prev->next = cur->next;
    delete cur;
    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, pos;
    cin >> n >> pos;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    Node *head = nullptr;
    head = insert_val(n, v, head);
    int sz = cout_node(head);

    if (sz - pos == 0)
        head = removeHead(head);

    head = removeNth(head, sz - pos);

    print_list(head);

    return 0;
}