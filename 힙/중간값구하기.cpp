#include <iostream>
#include <queue>
#include <vector>
#define swap(x, y, z) ((z) = (x), (x) = (y), (y) = (z))
using namespace std;

int max_heap[2000000];
int min_heap[2000000];

int Maxc, Minc, temp, sum = 0;
void pushMax(int x);
void pushMin(int x);
int popMax();
int popMin();
int main()
{
    int t;
    cin >> t;

    for (int k = 0; k < t; k++)
    {
        int n, A;
        cin >> n >> A;
        Maxc = 0, Minc = 0, sum = 0;
        pushMax(A);
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            if (a > max_heap[0])
                pushMin(a);
            else
                pushMax(a);
            if (b > max_heap[0])
                pushMin(b);
            else
                pushMax(b);
            if (Maxc < Minc)
                pushMax(popMin());
            else if (Maxc - 1 > Minc)
            {
                pushMin(popMax());
            }
            // sum =  ((sum%20171109)+(max_heap[0]%20171109))%20171109;
            sum += max_heap[0];
            // cout << max_heap[0] << endl;
            if (sum >= 20171109)
            {
                sum %= 20171109;
            }
            // cout << max_heap[0] << endl;
        }
        cout << "#" << k + 1 << " " << sum << endl;
    }
}
void pushMax(int x)
{
    int pivot = Maxc;
    max_heap[Maxc++] = x;

    while (pivot > 0)
    {
        int ppivot = pivot;
        pivot = pivot - 1 >> 1;
        if (max_heap[pivot] < x)
        {
            max_heap[ppivot] = max_heap[pivot];
            max_heap[pivot] = x;
        }
        else
            return;
    }
}

void pushMin(int x)
{
    int pivot = Minc;
    min_heap[Minc++] = x;

    while (pivot > 0)
    {
        int ppivot = pivot;
        pivot = pivot - 1 >> 1;
        if (min_heap[pivot] > x)
        {
            min_heap[ppivot] = min_heap[pivot];
            min_heap[pivot] = x;
        }
        else
            return;
    }
}

int popMax()
{
    int data = max_heap[0];
    max_heap[0] = max_heap[--Maxc];

    int pivot = 0;
    while (true)
    {
        int ppivot = pivot;
        pivot = (pivot << 1) + 1;

        if (Maxc <= pivot)
            break;
        if (Maxc == pivot + 1)
        {
            if (max_heap[pivot] > max_heap[ppivot])
            {
                int tmp = max_heap[pivot];
                max_heap[pivot] = max_heap[ppivot];
                max_heap[ppivot] = tmp;
            }
            else
                break;
        }
        else
        {
            if (max_heap[pivot] < max_heap[pivot + 1])
                pivot++;
            if (max_heap[pivot] > max_heap[ppivot])
            {
                int tmp = max_heap[pivot];
                max_heap[pivot] = max_heap[ppivot];
                max_heap[ppivot] = tmp;
            }
            else
                break;
        }
    }
    return data;
}

int popMin()
{
    int data = min_heap[0];
    min_heap[0] = min_heap[--Minc];

    int pivot = 0;
    while (true)
    {
        int ppivot = pivot;
        pivot = (pivot << 1) + 1;

        if (Minc <= pivot)
            break;
        if (Minc == pivot + 1)
        {
            if (min_heap[pivot] < min_heap[ppivot])
            {
                int tmp = min_heap[pivot];
                min_heap[pivot] = min_heap[ppivot];
                min_heap[ppivot] = tmp;
            }
            else
                break;
        }
        else
        {
            if (min_heap[pivot] > min_heap[pivot + 1])
                pivot++;
            if (min_heap[pivot] < min_heap[ppivot])
            {
                int tmp = min_heap[pivot];
                min_heap[pivot] = min_heap[ppivot];
                min_heap[ppivot] = tmp;
            }
            else
                break;
        }
    }
    return data;
}