#include<iostream>
#include<cstring>
#define maxn 100005
using namespace std;
int a[maxn];
int main(){
	int T,n;
	memset(a,0,sizeof(a));
	for(int m=1;m<maxn;m++){
		int x=m,y=m;
		while(x>0){
			y+=x%10;
			x/=10;
		}
		if(a[y]==0)a[y]=m;
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		cout<<a[n]<<endl;
	}
}
