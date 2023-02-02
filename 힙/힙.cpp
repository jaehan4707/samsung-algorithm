#include <iostream>
using namespace std;

int heap[100002];
int top;

void push(int x);
int pop();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cout << '#' << i+1 << ' ';
        top = 0;
        int n;
        cin >> n;
        for(int j = 0; j < n; j++) {
            int op,num;
            cin >> op;
            if(op == 1) {
                int num;
                cin >> num;
                push(num);
            } else {
                cout << pop() << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
void push(int val) {
    int pivot = top;
    heap[top++] = val;
    while(pivot > 0) {
        int ppivot = pivot;
        pivot--;
        pivot = pivot >> 1;
        if(heap[pivot] < val) {
            heap[ppivot] = heap[pivot];
            heap[pivot] = val;
        } else return;
    }
    return;
}
int pop() {
    if(top == 0) return -1;
    int val = heap[0];
    top--;
    heap[0] = heap[top];
    int pivot = 0;
    while(true) {
        int ppivot = pivot;
        pivot = pivot << 1;
        pivot++;
        if(pivot >= top) {
            break;
        } else if(pivot + 1 == top) {
            if(heap[ppivot] > heap[pivot]) break;
            int tmp = heap[ppivot];
            heap[ppivot] = heap[pivot];
            heap[pivot] = tmp;
            break;
        } else {
            if(heap[pivot] < heap[pivot + 1]) pivot++;
            if(heap[ppivot] > heap[pivot]) break;
            int tmp = heap[pivot];
            heap[pivot] = heap[ppivot];
            heap[ppivot] = tmp;
        }
    }
    return val;
}