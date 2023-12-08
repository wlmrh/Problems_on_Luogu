#include <bits/stdc++.h>
using namespace std;
int n,m,q;
set<int>::iterator it;
const int maxm = 50005;
const int maxn = 11111;
set<int> Q[11111];
struct edge{
    int u,v,cost;
    friend bool operator <(edge e1,edge e2){
        return e1.cost > e2.cost;
    }
}es[maxm];
int ans[maxm];
int parent[maxn];
int find(int x){
    return x == parent[x]?x:parent[x] = find(parent[x]);
}
int main(){
    memset(ans,-1,sizeof(ans));
    for(int i = 1;i < maxn;++i)
        parent[i] = i;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < m;++i)
        scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].cost);
    sort(es,es+m);
    scanf("%d",&q);
    for(int i = 0;i < q;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        Q[x].insert(i);
        Q[y].insert(i);
    }//Q[a]这个集合存储涉及到a点的货车编号
    for(int i = 0;i < m;++i){//按照道路载重量遍历每一条道路，维护并查集，在两个区间合并时，小区间的所有道路询问会被大区间继承
        int x = es[i].u,y = es[i].v,c = es[i].cost;
        int px = find(x),py = find(y);
        if(px == py) continue;//如果这两个点已经联通，那么已有更优道路，将此点跳过
        else{//x, y点并未联通
            if(Q[px].size() > Q[py].size())
                swap(px,py);
            vector<int> tmp;//tmp数组记录已解决货物编号？
            for(it = Q[px].begin();it != Q[px].end();++it){
                int id = *it;
                if(Q[py].count(id)){//判断x，y的祖先之间是否有货物需要运输
                    ans[id] = c;//如果有，将第id个货物的答案变为该条道路的载重量（因为之前二者并未联通）一定是最优答案
                    tmp.push_back(id);
                }
                Q[py].insert(id);//将px中含有的每一个货物编号赋给py
            }
            for(int i = 0;i < tmp.size();++i)
                Q[py].erase(tmp[i]);//消去已解决的道路
            parent[px] = py;//更改并查集的parent数组
        }
    }
    for(int i = 0;i < q;++i)//最后输出答案，可完成的线路均已被更新，剩余的未改变值，仍为-1的项就是无法完成的任务
        printf("%d\n",ans[i]);
}