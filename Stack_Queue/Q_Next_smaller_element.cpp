/*
Approach - Similar to next greater element
If stack empty we push -1
else, since we need smaller elements we remove greater and equal elements from stack

Note: We used vector directly instead of making unordered_map and then creating vector because of duplicate elements
since unordered_map cannot store different values for same key
*/

#include <bits/stdc++.h>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> v;
    stack<int> st;

    int size = arr.size();
    for (int i = size - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            v.push_back(-1);
            st.push(arr[i]);
        }
        else
        {
            while (!st.empty() && st.top() >= arr[i])
                st.pop();

            v.push_back((st.empty()) ? -1 : st.top());
            st.push(arr[i]);
        }
    }

    reverse(v.begin(), v.end());
    return v;
}