#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;

int rg;
int rgb;

char board[101][101];
int vis[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n;


void bfs(int i, int j) {
    queue<pair<int, int> > q;
    vis[i][j] = 1;
    q.push({i, j});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int t = 0; t < 4; t++) {
            int nx = dx[t] + cur.first;
            int ny = dy[t] + cur.second;

            if (nx < 0 || nx >= n || ny < 0 || ny >=n)
                continue;
            if (board[i][j] != board[nx][ny])
                continue;
            if (vis[nx][ny])
                continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}
int	main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j])
                continue;
            bfs(i, j);
            rgb++;
        }
    }
    
    for (int i = 0; i < n; i++)
        fill(vis[i], vis[i] + n, 0);

    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n ;j++) {
            if (board[i][j] == 'R') {
                board[i][j] = 'G';
            }
        }   
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j])
                continue;
            bfs(i, j);
            rg++;
        }
    }

    cout << rgb << " " << rg;
   return 0;
}