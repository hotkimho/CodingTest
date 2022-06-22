#include <iostream>
#include <deque>
using namespace std;

int findIndex(deque<int> deq, int target)
{
    for (int i = 0; i < deq.size(); i++) 
        if (deq[i] == target)
            return i;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    int result = 0;
    int arr[51];
    deque<int> deq;
    
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
        deq.push_back(i+1);
    
    for (int i = 0; i < m; i++) {
        int count = 0;

        while (1) {
            unsigned target = arr[i];
            int findIdx = findIndex(deq, target);
           
            if (deq.front() == target) {
                deq.pop_front();
                break;
            }
            if (deq.size() - findIdx < findIdx ) {
                int value = deq.back();
                deq.pop_back();
                deq.push_front(value);
            }
            else {
                int value = deq.front();
                deq.pop_front();
                deq.push_back(value);
            }
            count++;
        }
        result += count;
    }
    cout << result;
}
