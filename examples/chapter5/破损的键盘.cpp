#include<cstdio>
#include<cstring>

using namespace std;

const int maxn=100000+5;

int next[maxn];
int cur,last;
char s[maxn];

int main(void){
	while(scanf("%s",s+1)==1){
		int len=strlen(s+1);
		cur=0;
		last=0; // cur在光标的左边 
		next[0]=0;
		
		for(int i=1;i<=len;i++){
			char ch=s[i];
			if(ch=='['){  //起始点 
				cur=0;    
			}
			else if(ch==']'){
				cur=last;
			}
			else{
				next[i]=next[cur];
				next[cur]=i;
				if(cur==last) last=i;
				cur=i;
			}
		}
		for(int i=next[0];i!=0;i=next[i]){
			printf("%c",s[i]);
		}
		printf("\n");
	}
}
