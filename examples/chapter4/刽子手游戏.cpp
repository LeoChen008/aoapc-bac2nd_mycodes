#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 105
using namespace std;
char ans[maxn];
char guess[maxn];
int main(){
	int r;
	while(scanf("%d",&r)==1&&r!=-1){
		scanf("%s",ans);
		scanf("%s",guess);
		printf("Round %d\n",r);
		int alen=strlen(ans);
		int glen=strlen(guess);
		int chance=7;
		int left=alen;
		bool win=false,lose=false;
		for(int i=0;i<glen;i++){
			bool flag=false;
			for(int j=0;j<alen;j++){
				if(ans[j]==guess[i]){
					left--;
					ans[j]=' ';
					flag=true;
				}
			}
			if(!flag){
				chance--;
			}
			if(!chance){
				lose=true;
			}
			if(!left){
				win=true;
			}
			if(win||lose)break;
		} 
		if(win){
			cout<<"You win."<<endl;
		}
		else if(lose){
			cout<<"You lose."<<endl;
		}
		else{
			cout<<"You chickened out."<<endl;
		}
	}
} 
