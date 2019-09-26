#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
using namespace std;

const int maxn=5000+5;

int ans1[maxn],ans2[maxn];
int n; 

struct Section{
	int left,right;
	int id;
}x[maxn],y[maxn];

bool cmp(Section a,Section b){
	return a.right==b.right?a.left<b.left:a.right<b.right;
}
int solve(Section *sect,int *ans,int len){
	
	sort(sect,sect+len,cmp);
	fill(ans,ans+len,-1);
	
	bool flag=false;
	for(int i=1;i<=len;i++){
		flag=false;
		for(int j=0;j<len;j++){
			if(ans[sect[j].id]<0&&sect[j].left<=i&&sect[j].right>=i){
				ans[sect[j].id]=i;
				flag=true;break;
			}
		}
		if(!flag) return 0;
	}
	return 1;
}
int main(void){
	bool flag=false;
	while(cin>>n&&n){
		for(int i=0;i<n;i++){
			cin>>x[i].left>>y[i].left>>x[i].right>>y[i].right;
			x[i].id=y[i].id=i;
		}
		
		
		if(solve(x,ans1,n)&&solve(y,ans2,n)){
			for(int i=0;i<n;i++) printf("%d %d\n",ans1[i],ans2[i]);
		}
		else{
			printf("IMPOSSIBLE\n");
		}
	}
} 
