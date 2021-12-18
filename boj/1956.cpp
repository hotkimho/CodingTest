#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int INF = 1000000000;
int g[410][410];
int V, E;


void floydWarshall() {
    //처음은 거쳐가는 노드
    for (int p = 1; p <= V; p++) {
        //시작 노드
        for(int i = 1; i <= V; i++) {
            //도착 노드
            for(int j = 1; j <= V; j++) {
                if (i == j) continue;
                if (g[i][j] > g[i][p] + g[p][j])
                    g[i][j] = g[i][p] + g[p][j];
            }
        }
    }
}

int main() {
    int startV, endV, weight;

    cin >> V >> E;

    for (int i = 1; i <= V; i++) 
        for (int j = 1; j<= V; j++) 
            if (i != j)
                g[i][j] = INF;

    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &startV, &endV, &weight);
        //중복된 위치에 더 큰 weight가 올 수도 있음
        g[startV][endV] = min(g[startV][endV], weight);
    }

    floydWarshall();
    int min = INF;
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (g[i][j] == INF || i == j) continue;
            if (g[i][j] + g[j][i] < min)
                //min = g[i][j] + g[j][i];
        }
    }
    if (min != INF)
        cout<<min;
    else
        cout<<-1;
}