#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int is_visited[300000];
vector<pair<int, int> > g[300000];
int dij[300001];

int start;


void dijkstra(int start) {
    dij[start] = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(start, 0));
    
    while(!q.empty()) {
        int v = q.front().first;
        int w = q.front().second;
        q.pop();

        if (dij[v] < )
    }
}


int main() {
    int vIdx, eIdx, V, V2, W;

    cin >> vIdx >> eIdx;
    scanf("%d", &start);
    
    for (int i=0; i< eIdx; i++) {
        cin >> V >> V2 >> W;

        g[V].push_back(make_pair(V2, W)); 
        g[V2].push_back(make_pair(V, W));
    }
    
    for (int i=0; i<= 300000; i++)
        dij[i] = 10000000;
    dijkstra(start);

}