#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>

using namespace std;

#define gettime printf("\nTime : %0.3lf\n",clock()*1.0/CLOCKS_PER_SEC);
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repp(i,a,b) for(int i=a;i>=b;i--)
#define Set(x,a) memset(x,a,sizeof(x));

#define vs vector<string>
#define vi vector<int>
#define ll long long
#define ff first
#define ss second

struct comp {
       bool operator() (int a,int b) {
            return a>b;
       }
};

int n; // total node
vi data[100]; // Data node dan edge
bool visit[100] = {}; // check note is visited

int dfs(int node, int level) {
    printf("Visit %d\n", node);
    visit[node] = true;
    level++;
    int maxLevel = level;
    int m = data[node].size();
    for (int i = 0; i < m; i++) {
        if (visit[data[node][i]] == false) {
            maxLevel = max(maxLevel, dfs(data[node][i], level));
        }
    }
    return maxLevel;
}

// O(n) = V+E

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(false);
    n = 8;
    data[1].PB(2);
    data[1].PB(3);
    data[1].PB(4);
    data[2].PB(5);
    data[2].PB(6);
    data[4].PB(7);
    data[7].PB(8);
    printf("Max Level : %d", dfs(1, 0));
    return 0;
}
