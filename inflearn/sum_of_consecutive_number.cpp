#include <iostream>
#include <vector>
using namespace std;
/*
메모용
15인 경우
N개의 숫자가 연속되는지 검사하는 법 아래는 2개
1.앞 N(2)개(1, 2)를 15에서 뺀다. -> 12
2.뺀 수가 N(2)개로 나누어 떨어지면 성립
3.뺀 수를 N(2)로 나눈 몫을 구한다. -> 6
4.몫을 각 N개의 수(1, 2)에 더한다. ->
5.1 + 6 = 7, 2 + 6 = 8 -> 15
성립!
*/
int main() {    
    int N, c = 0;

    cin >> N;
    
    for (int i = 1; i < N / 2 + 1; i++) {
        int sum = i;
        for (int j = i + 1; j <= N / 2 + 1; j++) {
            sum += j;
            if (sum > N)
                break;
            else if (sum == N) {
                for (int k = i; k <= j; k++)
                    cout << k << " + ";
                cout<< "= " << sum<<endl;
                c++;
                break;
            }
        }
    }
    cout<<c;
}