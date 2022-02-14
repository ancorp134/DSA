#include <bits/stdc++.h>
using namespace std;

class Heap
{
    vector<int> v;
    bool minHeap;

    bool compare(int a, int b)
    {
        if (minHeap)
            return a < b;
        else // it is max heap
            return a > b;
    }

    void heapify(int idx)
    {
        int left = 2 * idx;
        int right = 2 * idx + 1;

        int min_idx = idx;
        int last = v.size() - 1;

        // after this min_idx will be the index of the smallest element of the three elements
        if (left <= last && compare(v[left], v[min_idx]))
            min_idx = left;
        if (right <= last && compare(v[right], v[min_idx]))
            min_idx = right;

        // if the value of min_idx is not the same as the value of idx, then swap them
        if (min_idx != idx) // this will act as base case too
        {
            swap(v[idx], v[min_idx]);
            heapify(min_idx);
        }
    }

public:
    Heap(int default_size = 10, bool type = true)
    {
        // this means vector will not expand until 10 elements are added
        v.reserve(default_size);
        // this is to block the 0th index as In heap we start from 1st index
        v.push_back(-1);
        // if true than minHeap and if false than maxHeap
        minHeap = true;
    }
    void push(int d)
    {
        v.push_back(d);
        int idx = v.size() - 1;
        int parent_idx = idx / 2;

        // keep pushing to the top till you reach a root node or stop the midway because current element is already greater than parent
        while (idx > 1 && compare(v[idx], v[parent_idx]))
        {
            swap(v[idx], v[parent_idx]);
            idx = parent_idx;
            parent_idx = parent_idx / 2;
        }
    }

    // returns the top most element of the heap
    int top()
    {
        return v[1];
    }
    void pop()
    {
        int last_idx = v.size() - 1;
        swap(v[1], v[last_idx]);
        v.pop_back();
        // we are passing the index that we want to heapify
        heapify(1);
    }
    //if heap is empty it will return size 1 as we had block the 0th index
    bool isEmpty()
    {
        return v.size() == 1;
    }
};

int main()
{
    // give some initial size,type
//for maxheap Heap h(10,false);
    Heap h;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        h.push(d);
    }

    //remove all elements from the heap one by one
    while(!h.isEmpty())
    {
        cout << h.top() << " ";
        h.pop();
    }
    return 0;
}