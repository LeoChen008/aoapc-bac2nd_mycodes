#include<iostream>
#include<string>
#include<cstring>
using namespace std;

const int maxn=(1<<10)+10;
const int len=32;

char s[maxn];
int buf[len][len];
int black;
void build(const char *s,int &index,int r,int c,int w ){
	char ch=s[index++];
	if(ch=='p'){
		build(s,index,r,c+w/2,w/2);
		build(s,index,r,c,w/2);
		build(s,index,r+w/2,c,w/2);
		build(s,index,r+w/2,c+w/2,w/2);
	}
	else if(ch=='f'){
		for(int i=r;i<r+w;i++){
			for(int j=c;j<c+w;j++){
				if(buf[i][j]==0){
					buf[i][j]=1;
					black++;
				}
			}
		}
	}
}
int main(void){
	int n;
	cin>>n;
	while(n--){
		memset(buf,0,sizeof(buf));
		black=0;
		for(int i=0;i<2;i++){
			scanf("%s",s);
			int index=0;
			build(s,index,0,0,len);
		}
		cout<<"There are "<<black<<" black pixels."<<endl;
	}
}
