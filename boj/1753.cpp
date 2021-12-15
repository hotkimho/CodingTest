#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 987654321
using namespace std;

vector<pair<int, int> > g[20002];
int dij[20002];

void dijkstra(int start) {
    dij[start] = 0;
    priority_queue<pair<int, int> > q;
    q.push(make_pair(0, start));


    while (!q.empty()) {
        int w = -q.top().first;
        int v = q.top().second;
        q.pop();

        //if (dij[v] < w) continue;
        //인접한 노드 수 만큼 반복
        for (int i = 0; i < g[v].size(); i++) {
            //인접한 노드의 V, W를 가져옴
            int next_v = g[v][i].first;
            int next_w = g[v][i].second + w;

            //해당 노드로 가는 경로보다 현재의 위치에서 가는게 더 작으면 바꿔!!
            if (dij[next_v] > next_w) {
                dij[next_v] = next_w;
                //최단 경로를 발견할 때만 푸쉬, 가지치기같은 느낌
                q.push(make_pair(-next_w, next_v));
            }
        }
    }
}


int main() {
    int vIdx, eIdx, V, V2, W;
    int start;
    scanf("%d %d", &vIdx, &eIdx);
    scanf("%d", &start);

    for (int i=0; i< eIdx; i++) {
        scanf("%d %d %d", &V, &V2, &W);
        g[V].push_back(make_pair(V2, W));
    }

    for (int i = 0; i <= vIdx; i++)
        dij[i] = MAX;
    dijkstra(start);
    for (int i = 1; i <= vIdx; i++) {
        if (dij[i] == MAX)
            printf("INF\n");
        else
            printf("%d\n", dij[i]);

    }
}