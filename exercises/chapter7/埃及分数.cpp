#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=5+5;
const int maxm=1000+5;
#define LL long long

LL a,b,k;
LL temp[maxn];
LL ans[maxn];
bool first;
int limit[maxm];

inline LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}

void dfs(LL a,LL b,LL cur,LL maxd){
	if(cur==maxd){
		if(b%a==0&&b/a>temp[cur-1]&&(b/a>1000||!limit[b/a])){
			bool flag=false;
			temp[cur]=b/a;
			for(int i=cur;i>=1;i--){
				if(temp[i]<ans[i]){
					flag=true;
					break;
				}else if(temp[i]>ans[i]){
					break;
				}
			}
			
			if(!first||flag) memcpy(ans,temp,sizeof(temp));
			first=true;
			return;
			
		}
		
		return;		
	}
	 
	LL start=b/a;
	if(start<=temp[cur-1]) start=temp[cur-1]+1;
	LL end=(maxd-cur+1)*b/a;
	if(first&&end>ans[maxd]) end=ans[maxd]-1;
	
	for(LL i=start;i<=end;i++){
		if(i<=1000&&limit[i]) continue;
		temp[cur]=i;
		LL m=gcd(a*i-b,b*i);
		dfs((a*i-b)/m,b*i/m,cur+1,maxd);
	}
	return;
}
void solve(){
	LL maxd;
	bool flag=false;
	first=false;
	temp[0]=1; 
	for(maxd=2;maxd<10;maxd++){
		dfs(a,b,1,maxd);
		if(first){
			printf("1/%lld",ans[1]);
			for(LL i=2;i<=maxd;i++){
				printf("+1/%lld",ans[i]);
			}
			printf("\n");
			return;
		}
	}
}
int main(void){
	int T;
	int kcase=0;
	int index; 
	cin>>T;
	while(T--){
		cin>>a>>b>>k;
		memset(limit,0,sizeof(limit));
		for(int i=0;i<k;i++){
			cin>>index;
			limit[index]=1;
		}
		
		printf("Case %d: %lld/%lld=",++kcase,a,b);
		solve();
	} 
} 
