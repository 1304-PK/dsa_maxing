#include <bits/stdc++.h>
using namespace std;

/*
First approach - Save a pair of int in stack
first element will be the most recent element pushed
second element will keep track of minimum element till now
*/

stack<pair<int, int>> st;

void pushElement(int val){
    if (st.empty()) st.push({val, val});
    else st.push({val, min(val, st.top().second)});
}

int getMin(){
    return st.top().second;
}

/*
Top and pop will be as usual
TC - O(1)
SC - O(2N) - cause pair is being saved
*/

// -----------------------------------------------------------------------------------------

/*
Second approach(better) -

Get a variable mini and keep track of the min value
While pushing whenever a value smaller than mini appears, we update mini with that value and we push in stack (2*val - mini)

While popping whenever top is smaller than mini then we replace mini with (2*mini - top) and then pop

When giving top, we check if top is smaller than mini, if yes then we return mini else we return top

Reason for the mathematical formula is we have to preserve the previous min values

TC - O(1)
SC - O(N)
*/

stack<int> s;
int mini = INT_MAX;

void push(int val){
    if (s.empty()){
        mini = val;
        s.push(val);
    }
    else if (val<mini){
        s.push(2*val - mini);
        mini = val;
    }
    else s.push(val);
}

void pop(){
    if (s.empty()) return;

    int x = s.top();
    s.pop();

    if (x<mini){
        mini = (2*mini - x);
    }
}

int top(){
    if (s.top()<mini) return mini;
    else return s.top();
}

int getMin(){
    return mini;
}