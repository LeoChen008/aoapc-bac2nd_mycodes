#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn=10;

int n;
int kcase=0;
int a[maxn]; 

bool issorted(){
	for(int i=1;i<n;i++){
		if(a[i]<a[i-1]) return false;
	}
	return true;
}
int h(){
	int cnt=0;
	for(int i=1;i<n;i++){
		if(a[i-1]+1!=a[i])cnt++;
	}
	if(a[0]!=1) cnt++;
	return cnt;
}
bool dfs(int d,int maxd){
	if(3*d+h()>3*maxd) return false;
	if(issorted()) return true;
	
	int t[maxn];
	int v[maxn];  //可以进行粘贴的位置 
	memcpy(t,a,sizeof(a));
	
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int cnt=0;
			for(int k=0;k<n;k++){
				if(k<i||k>j) v[cnt++]=a[k];  //将剪切外的自然段记录 
			}
			
			for(int p=0;p<=cnt;p++){   //尝试所有剪切粘贴的可能性 
				int cnt2=0;
				for(int q=0;q<p;q++)  a[cnt2++]=v[q]; 
				for(int q=i;q<=j;q++) a[cnt2++]=t[q];
				for(int q=p;q<cnt;q++)a[cnt2++]=v[q];
				
				if(dfs(d+1,maxd)) return true;
				memcpy(a,t,sizeof(a));
			}
			
		
		}
	}
	return false;
}
int main(void){
	while(cin>>n&&n){
		getchar();
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		
		int maxd;
		
		if(issorted()) maxd=0; 
		else
		for(maxd=1;maxd<n;maxd++){
			if(dfs(0,maxd)) break;
		}
		
		printf("Case %d: %d\n",++kcase,maxd);
	}
}
