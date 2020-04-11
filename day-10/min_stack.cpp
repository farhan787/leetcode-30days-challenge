// Problem link: https://leetcode.com/problems/min-stack

#include <iostream>
#include <stack>
using namespace std;

// Time complexity = O(1) for getMin() method
// Space complexity = O(n); where n = size of stack

class MinStack {
   private:
    stack<int> stk;
    stack<int> minStk;

   public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        stk.push(x);

        if (minStk.empty() || x <= minStk.top()) {
            minStk.push(x);
        }
    }

    void pop() {
        if (stk.empty()) {
            return;
        }

        if (!minStk.empty() && minStk.top() == stk.top()) {
            minStk.pop();
        }

        stk.pop();
    }

    int top() const {
        return stk.top();
    }

    int getMin() const {
        return minStk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
}
