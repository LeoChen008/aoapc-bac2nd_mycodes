#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn=80+5;

int n,L;
int res[maxn];
int cnt;
int count;

bool dfs(int cur){
	if(cnt++==n){
		for(int i=0;i<cur;i++){
			if(i&&i%64==0) printf("\n");
			else if(i&&i%4==0) printf(" ");
			printf("%c",res[i]+'A');
			
		}
		
		printf("\n");
		
		count=cur;
		return true;
	}
	
	for(int i=0;i<L;i++){
		res[cur]=i;
		bool flag=true;
		
		for(int j=1;2*j<=cur+1;j++){
			
			bool equal=true;
			
			for(int k=0;k<j;k++){
				if(res[cur-k]!=res[cur-k-j]){
					equal=false;
					break;
				}
			}
			
			if(equal){
				flag=false;
				break;
			}
		}
		
		if(flag){
			if(dfs(cur+1)) return true;
		}
	}
	
	return false;
}

int main(void){ 
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(cin>>n>>L&&n){
		cnt=0;
		count=0;
		dfs(0);
		printf("%d\n",count);
	}	
	//fclose(stdin);
	//fclose(stdout);
}
