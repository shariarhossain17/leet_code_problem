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
    head = newNode->next;
    return newNode;
}

Node *insert_value(vector<int> &v, Node *head)
{
    if (head == nullptr)
    {
        head = insert_head(v[0], head);
    }

    Node *cur = head;

    int n = v.size();

    for (int i = 1; i < n; i++)
    {
        Node *tmp = new Node(v[i]);
        cur->next = tmp;
        cur = cur->next;
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

Node *remove_duplicate_brute_force(Node *head)
{
    if (!head)
        return nullptr;

    vector<int> val;
    unordered_set<int> seen;

    Node *tmp = head;
    while (tmp)
    {
        if (seen.find(tmp->val) == seen.end())
        {
            val.push_back(tmp->val);
            seen.insert(tmp->val);
        }
        tmp = tmp->next;
    }

    Node *new_head = new Node(val[0]);
    Node *cur = new_head;

    for (int i = 1; i < val.size(); i++)
    {
        cur->next = new Node(val[i]);
        cur = cur->next;
    }

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

    Node *head = nullptr;

    head = insert_value(v, head);

    head = remove_duplicate_brute_force(head);

    print_list(head);

    return 0;
}