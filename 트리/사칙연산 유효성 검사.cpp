#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
int N, num, l, r;
bool flag = true;
typedef struct node *node_ptr;
vector<int> post;
struct node
{
    int key;
    node_ptr left, right;
    string value;
};
node_ptr create_node(vector<string> tree[], int step);
node_ptr make_tree(vector<string> tree[], int step);
node_ptr postOrder(vector<string> tree[], node_ptr node);
int main()
{

    for (int i = 0; i < 10; i++)
    {
        cin >> N;
        getchar();
        vector<string> tree[N + 1];
        post.assign(0, 0);
        flag = true;
        for (int j = 1; j <= N; j++)
        {
            string s;
            string buffer;
            getline(cin, buffer);
            istringstream ss(buffer);
            while (getline(ss, buffer, ' ')) // 0 : 정점, 1 : value, 2 : left child, 3 : right child
            {                                // 마지막 파라미터에 원하는 구분자 입력
                tree[j].push_back(buffer);
            }
        }
        node *Node;
        Node = make_tree(tree, 1);

        postOrder(tree, Node); // 오류
        // cout<<N<<" "<<"test"<<endl;
        if (flag == true)
        {
            cout << "#" << i + 1 << " " << 1;
        }
        else
            cout << "#" << i + 1 << " " << 0;
        cout << endl;
    }
}
node_ptr create_node(vector<string> tree[], int step)
{
    node_ptr temp = (node_ptr)malloc(sizeof(node));
    temp->key = stoi(tree[step][0]);
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
node_ptr make_tree(vector<string> tree[], int step)
{
    if (step > N)
    {
        return NULL;
    }
    node_ptr Node = create_node(tree, step);
    if (tree[step].size() == 4)
    {
        Node->left = make_tree(tree, stoi(tree[step][2]));
        Node->right = make_tree(tree, stoi(tree[step][3]));
    }
    else if (tree[step].size() == 3)
    {
        Node->left = make_tree(tree, stoi(tree[step][2]));
    }
    return Node;
}
node_ptr postOrder(vector<string> tree[], node_ptr node)
{
    int result = 0;

    if (flag == false)
    {
        return NULL;
    }
    if (node != NULL)
    {

        postOrder(tree, node->left);
        postOrder(tree, node->right);
        char a = tree[node->key][1][0];
        if (a < 48)
        {
            if (node->left == NULL || node->right == NULL)
            {
                flag = false;
                return NULL;
            }
            char b = tree[node->left->key][1][0], c = tree[node->right->key][1][0];
            if (b < 48 || c < 48)
            {
                flag = false;
                return NULL;
            }
            tree[node->key][1][0] = '1';
        }
    }
    return node;
}