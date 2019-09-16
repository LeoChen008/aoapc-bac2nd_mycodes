#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

const int maxn=200+10;

int jobs[maxn];
int n,pos;
int head,tail;

bool ishightest(int val){
	for(int i=head;i<tail;i++){
		if(jobs[i]>val){
			return false;
		}
	}
	
	return true;
}
int main(void){
	int T;
	cin>>T;
	while(T--){
		memset(jobs,0,sizeof(jobs));
		head=0,tail=0;
		cin>>n;
		cin>>pos;
		
		
		for(int i=0;i<n;i++){
			int job;
			cin>>job;
			jobs[i]=job;
		}
		tail=n;
		
		int ans=0;
		while(head<=pos){
			if(ishightest(jobs[head])){
				ans++;
				head++;
			}
			else{
				int temp=jobs[head];
				
				if(head==pos){
					pos=tail;
				}
				jobs[tail++]=temp;
				head++;
			}
		}
		
		printf("%d\n",ans);
	}
} 
