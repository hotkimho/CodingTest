#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stdio.h>
#include <utility>
using namespace std;

int board[501][501];
int vis[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int artCount = 0;
int result;
int n, m;

void art(int i, int j) {
    int countOfArt = 0;
    queue<pair<int, int> > que;
    que.push(make_pair(i, j));
    vis[i][j] = 1;
    
    while (!que.empty()) {
        pair<int, int> cur = que.front();
        //cout << cur.first << " " << cur.second <<endl;
        que.pop();
        countOfArt++;
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (vis[nx][ny] || board[nx][ny] == 0)
                continue;
            vis[nx][ny] = 1;
            que.push(make_pair(nx,ny));
        }
    }
    if (result < countOfArt)
        result = countOfArt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	freopen("input.txt", "r", stdin);
    
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0 || vis[i][j])
                continue;
            else {
                art(i, j);
                artCount++;
            }
        }
    }
    std::cout << artCount << "\n" << result;
}
