#include <bits/stdc++.h>

using namespace std;

int rg;
int rgb;

int board[101][101];
int vis[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n;


void bfs(int i, int j) {
    queue<pair<int, int> > q;

    vis[i][j] = 1;
    q.push(make_pair(i, j));

    while (!q.empty()) {

    }

}
int	main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;



    return 0;
}