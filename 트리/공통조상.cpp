#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>
using namespace std;
int N, num, l, r;
typedef struct node *node_ptr;
vector<int> result;
struct node
{
    int key;
    node_ptr left, right;
};
node_ptr create_node(int num);
node_ptr make_tree(int num, vector<int> graph[]);
node_ptr postOrder(node_ptr node);
void go_back(int num, vector<int> &ary, vector<int> tracking[], int depth);
void sum_node(int num, vector<int> graph[]);
int t, v, e, x, y, s, f, sum = 0, sub = 0;
vector<int> first;
vector<int> second;
vector<int> d;
bool flag = false;
int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> v >> e >> x >> y; // v : 정점개수 , e: 간선갯수 x,y 서브트리

        sum = 0;
        flag = false;
        sub = 0;
        vector<int> graph[10001];
        vector<int> tracking[10001];
        first.assign(v + 1, 0);
        second.assign(v + 1, 0);
        d.assign(v + 1, 0);
        for (int j = 0; j < e; j++)
        {
            cin >> s >> f;
            graph[s].push_back(f);
            tracking[f].push_back(s);
        }
        node_ptr Node = make_tree(1, graph);
        go_back(x, first, tracking, 0);
        go_back(y, second, tracking, 0);
        int depth = 10001;
        for (int i = v; i >= 1; i--) // sub을 구하는 방식이 잘못됨.
        {
            if (first[i] == 1 && second[i] == 1)
            {
                if (depth > d[i])
                {
                    sub = i;
                    depth = d[i];
                }
                // break;
            }
        }
        sum_node(sub, graph);
        cout << "#" << i + 1 << " " << sub << " " << sum + 1 << endl;
    }
}
node_ptr create_node(int num)
{
    node_ptr temp = (node_ptr)malloc(sizeof(node));
    temp->key = num;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
node_ptr make_tree(int num, vector<int> graph[])
{

    node_ptr Node = create_node(num);
    vector<int> temp;
    for (int i = 0; i < graph[num].size(); i++)
    {
        temp.push_back(graph[num][i]);
    }
    for (int i = 0; i < temp.size(); i++)
    {
        if (Node->left == NULL)
        {
            Node->left = make_tree(temp[i], graph);
        }
        else
        {
            Node->right = make_tree(temp[i], graph);
        }
    }
    return Node;
}
void go_back(int num, vector<int> &ary, vector<int> tracking[], int depth)
{
    if (num == 1)
    {
        return;
    }
    int parent = tracking[num][0];
    ary[parent] = 1;
    d[parent] = depth;
    go_back(parent, ary, tracking, depth + 1);
}
void sum_node(int num, vector<int> graph[])
{

    sum += graph[num].size();
    for (int i = 0; i < graph[num].size(); i++)
    {
        sum_node(graph[num][i], graph);
    }
}