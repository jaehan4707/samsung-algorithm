/*
9일차 중위순회(inorder)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
int N, num, l, r;
char v;
typedef struct node *node_ptr;
struct node
{
    int key;
    node_ptr left, right;
    string value;
};
node_ptr create_node(vector<string> tree[], int step);
node_ptr make_tree(vector<string> tree[], int step);
node_ptr inorder();
int main()
{

    cin >> N;
    vector<string> tree[N];
    getchar();
    for (int j = 0; j < N; j++)
    {
        string s;
        string buffer;
        getline(cin, buffer);
        istringstream ss(buffer);
        while (getline(ss, buffer, ' ')) // 0 : 정점, 1 : value, 2 : left child, 3 : right child
        {                                // 마지막 파라미터에 원하는 구분자 입력
            tree[j].push_back(buffer);
        }
        // create_node(tree);
    }
    make_tree(tree, 0);
}
node_ptr create_node(vector<string> tree[], int step)
{
    node_ptr temp = (node_ptr)malloc(sizeof(node));
    temp->key = stoi(tree[step][0]);
    temp->value = tree[step][1];
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
node_ptr make_tree(vector<string> tree[], int step)
{
    cout << step << endl;
    if (step >= N)
    {
        return NULL;
    }
    node_ptr Node = create_node(tree, step);
    if (tree[step].size() <= 4)
    {
        Node->left = make_tree(tree, stoi(tree[step][2]));
        Node->right = make_tree(tree, stoi(tree[step][3]));
    }
    else if (tree[step].size() <= 3)
    {
        Node->left = make_tree(tree, stoi(tree[step][2]));
    }
    return Node;
}