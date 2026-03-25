#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Node
{
public:
    Node(Node* node) : x(node->x), y(node->y), name(node->name) {}
    Node(const vector<int>& vec, int _name) : x(vec[0]), y(vec[1]), name(_name) {}
    void Push(Node* node);
    void jeonwiPrint(vector<int>& vec);
    void huwiPrint(vector<int>& vec);
    int name;
    int x, y;
    Node* l = nullptr;
    Node* r = nullptr;
};

struct comp
{
    bool operator()(const Node* l, const Node* r)
    {
        if (l->y < r->y)
            return true;
        if (l->y == r->y)
            if (l->x > r->x)
                return true;
        return false;
    }
};

void Node::Push(Node* new_node)
{
    Node* cur_node = this;
    while (1)
    {
        if (new_node->x < cur_node->x)
        {
            if (cur_node->l == nullptr)
            {
                cur_node->l = new_node;
                return;                
            }
            else
                cur_node = cur_node->l;
        }
        else
        {
            if (cur_node->r == nullptr)
            {
                cur_node->r = new_node;
                return;
            }
            else
                cur_node = cur_node->r;
        }    
    }   
}

void Node::jeonwiPrint(vector<int>& vec)
{
    Node* cur_node = this;
    vec.push_back(cur_node->name);
    if (cur_node->l != nullptr)
    {
        cur_node->l->jeonwiPrint(vec);
    }
    if (cur_node->r != nullptr)
    {
        cur_node->r->jeonwiPrint(vec);
    }
}

void Node::huwiPrint(vector<int>& vec)
{
    Node* cur_node = this;
    if (cur_node->l != nullptr)
    {
        cur_node->l->huwiPrint(vec);
    }
    if (cur_node->r != nullptr)
    {
        cur_node->r->huwiPrint(vec);
    }
    vec.push_back(cur_node->name);
}


typedef priority_queue<Node*, vector<Node*>, comp> PQ;

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    PQ pq;
    for (int i = 0; i < nodeinfo.size(); i++)
        pq.push(new Node(nodeinfo[i], i + 1));
    Node* root = pq.top();
    pq.pop();
    while (!pq.empty())
    {
        root->Push(pq.top());
        pq.pop();
    }
    root->jeonwiPrint(answer[0]);
    root->huwiPrint(answer[1]);
    return answer;
}