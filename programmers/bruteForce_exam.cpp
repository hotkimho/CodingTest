#include <string>
#include <vector>

using namespace std;
int one[5] = {1, 2, 3, 4, 5};
int two[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int three[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int arr[3] = {0,};
    int max = -1;

    for (int i = 0; i < answers.size(); i++) {
        if (one[i % 5] == answers[i])
            arr[0]++;
        if (two[i % 8] == answers[i])
            arr[1]++;
        if (three[i % 10] == answers[i])
            arr[2]++;
    }
    for (int i = 0; i < 3; i++)
        if (arr[i] > max)
            max = arr[i];
    for (int i = 0; i < 3; i++) {
        if (arr[i] == max)
            answer.push_back(i + 1);
    }
    return answer;
}