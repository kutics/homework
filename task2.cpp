#include "Stack.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    Stack stack, s;
    for (int i = 0; i < n; i ++) {
        double x;
        cin >> x;
        stack.push(x);
    }
    while (!stack.isEmpty()) {
        double a = stack.top();
        s.pop();
        while (!s.isEmpty() && s.top() > a) {
            stack.push(s.top());
            s.pop();
        }
        s.push(a);
    }
    while (!s.isEmpty()) {
        stack.push(s.top());
        s.pop();
    }
    while (!stack.isEmpty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
}
