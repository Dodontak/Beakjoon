#include <iostream>
#include <vector>

using namespace std;

void print_front(const vector<pair<char, char>> &tree, int idx)
{
    cout << (char)('A' + idx);
    if (tree[idx].first != '.')
    {
        print_front(tree, tree[idx].first - 'A');
    }
    if (tree[idx].second != '.')
    {
        print_front(tree, tree[idx].second - 'A');
    }
    if (idx == 0)
        cout << endl;
}

void print_middle(const vector<pair<char, char>> &tree, int idx)
{
    if (tree[idx].first != '.')
    {
        print_middle(tree, tree[idx].first - 'A');
    }
    cout << (char)('A' + idx);
    if (tree[idx].second != '.')
    {
        print_middle(tree, tree[idx].second - 'A');
    }
    if (idx == 0)
        cout << endl;
}

void print_back(const vector<pair<char, char>> &tree, int idx)
{
    if (tree[idx].first != '.')
    {
        print_back(tree, tree[idx].first - 'A');
    }
    if (tree[idx].second != '.')
    {
        print_back(tree, tree[idx].second - 'A');
    }
    cout << (char)('A' + idx);
    if (idx == 0)
        cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<char, char>> tree(n);
    for (int i = 0; i < n; ++i)
    {
        char parent, left, right;
        cin >> parent >> left >> right;
        tree[parent - 'A'].first = left;
        tree[parent - 'A'].second = right;
    }
    print_front(tree, 0);
    print_middle(tree, 0);
    print_back(tree, 0);
}
