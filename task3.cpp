#include "Heap2.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    Heap heap;
    for (int i = 0; i < n; i ++) {
        int w;
        cin >> w;
        heap.push(-w);
    }
    while (n > 1) {
        int y = -heap.pop();
        int x = -heap.pop();
        n -= 2;
        if (y != x) {
            heap.push(-(y - x));
            n ++;
        }
    }
    if (n == 0) {
        cout << 0;
    } else {
        cout << -heap.pop();
    }
}
