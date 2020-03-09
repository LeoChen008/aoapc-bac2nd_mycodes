/*
* Created by LeoChen008
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1e6+5;
struct Node{
	int pre,next;
	int cover;
}nodes[maxn];
int n,p;
int kcase = 0;
int floor[maxn];
int vis[maxn];
inline
void del_node(int index)
{
	vis[index] = 1;
	nodes[nodes[index].pre].next = nodes[index].next;
	nodes[nodes[index].next].pre = nodes[index].pre;
}
int main(void)
{
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> p;
		
		memset(floor, 0, sizeof(floor));
		for (int i=0; i<n; ++i) {
			nodes[i].pre = (i-1+n)%n;
			nodes[i].next = (i+1)%n;
			vis[i] = 0;
		}
		
		int u,v;
		for (int i=0; i<p; ++i) {
			cin >> u >> v;
			nodes[u].cover = v;
			nodes[v].cover = u;
			floor[u] = 1; floor[v] = -1;
		}
		
		getchar();
		
		for (int i=0; i<n; ++i) if (!floor[i]) del_node(i);
		
		int cnt = 2*p;
		int head = 0;
		int x,y;
		int coverx, covery;
		bool flag = false;
		while (cnt) {
			flag = false;
			while (vis[head]) head++;
			for (int i=nodes[head].next; i!=head && !flag; i = nodes[i].next) {
				x = i; y = nodes[i].next;
				coverx = nodes[x].cover;
				covery = nodes[y].cover;
				
				if (floor[x] == floor[y] && (nodes[coverx].next == covery || 
					nodes[covery].next == coverx)) 
				{
					del_node(x); del_node(y);
					del_node(coverx); del_node(covery);
					cnt -= 4; 
					flag = true;
				}
				else if (y == coverx){
					del_node(x); del_node(y);
					cnt -= 2;
					flag = true;
				}
			}
			
			if(!flag) break;
		}
		
		if (cnt) printf("Case #%d: NO\n", ++kcase);
		else printf("Case #%d: YES\n", ++kcase); 
 	} 
	return 0;
}
