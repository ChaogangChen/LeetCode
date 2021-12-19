/*
LeetCode 最小栈
https://leetcode-cn.com/problems/min-stack/
*/
# include <iostream>
# include <stack>
# include <algorithm>
using namespace std;

class MinStack {
public:
    stack<int> stk;
    stack<int>  min_stk;
    MinStack() {
        min_stk.push(INT_MAX);
    }
    
    void push(int val) {
        stk.push(val);
        min_stk.push(min(min_stk.top(),val));
    }
    
    void pop() {
        stk.pop();
        min_stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */