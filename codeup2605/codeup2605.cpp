#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<algorithm>
#include<queue>

using namespace std;

int n, A[101][101], dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 }, cnt = 0, ans;

typedef struct Candy
{
    int a, b;
} candy;
bool safe(int a, int b)
{
    return (a >= 0 && a < n) && (b >= 0 && b < n);
}
void bfs(int a, int b, int c)
{
    queue<candy> Q;

    Q.push({ a,b });

    A[a][b] = c;
    cnt++;

    while (!Q.empty())
    {
        candy spcd = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            if (safe(spcd.a + dx[i], spcd.b + dy[i]) && A[spcd.a + dx[i]][spcd.b + dy[i]] == c - 5)
            {
                A[spcd.a + dx[i]][spcd.b + dy[i]] = c;
                cnt++;
                Q.push({ spcd.a + dx[i],spcd.b + dy[i] });
            }

        }
    }
    //printf("%d\n",cnt);
}
void solve()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] >= 1 && A[i][j] <= 5) {
                bfs(i, j, A[i][j] + 5);
                if (cnt >= 3) ans++;
                cnt = 0;
            }
        }
    }
}
void input()
{
    n = 7;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
}
void output()
{
    printf("%d", ans);
}
int main()
{
    input();
    solve();
    output();
    return 0;
}

