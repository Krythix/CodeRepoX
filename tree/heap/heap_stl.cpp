#include <queue>
#include <iostream>
using namespace std;

int main() {
    // 小根堆
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(1);
    q.push(2);
    cout << q.top() << endl;
    return 0;
}