#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

const int N = 100000; /* max number of vertices - adjust */
int n, m; /* number of vertices, number of edges */

set< pair<int, int> > edges;
vector<int> adj[N];
int order[N], cnt[N], pos[N];

void mcs(int v = 0)
{   set< pair<int, int> > s;
    int k = 0;

    memset(pos, ~0, sizeof(pos));

    s.insert(make_pair(0, v));
    while(s.empty() == false)
    {   pair<int, int> p = *s.begin();
        s.erase(s.begin());

        int x = p.second;
        pos[x] = k;
        order[k++] = x;

        for(int i = 0; i < adj[x].size(); i++)
        {   int y = adj[x][i];
            if(pos[y] != -1) continue;

            if(cnt[y]) s.erase(make_pair(cnt[y], y));
            s.insert(make_pair(--cnt[y], y));
        }
    }
}

bool perfect(void)
{   for(int j = n - 1; j >= 0; j--)
    {   int last_pred = -1;
        for(int i = 0; i < adj[j].size(); i++)
        {   int y = adj[j][i];
            if(pos[y] >= pos[order[j]]) continue;
            if(pos[y] > last_pred) last_pred = pos[y];
        }
        for(int i = 0; i < adj[j].size(); i++)
        {   int y = adj[j][i];
            if(pos[y] >= pos[order[j]] || pos[y] == last_pred) continue;
            if(edges.count(make_pair(order[last_pred], y)) == 0)
                return false;
        }
    }
    return true;
}

int main(void)
{   scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {   int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
        edges.insert(make_pair(x, y));
        edges.insert(make_pair(y, x));
    }

    mcs();
    if(perfect()) puts("CHORDAL");
    else puts("NOT CHORDAL");

    return 0;
}
