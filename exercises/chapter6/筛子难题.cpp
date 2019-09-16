#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int maxn=10+5;
const int dirr[]={-1,0,1,0};
const int dirc[]={0,1,0,-1};
typedef pair<int,int> p;

int map[maxn][maxn];
int vis[maxn][maxn][maxn][maxn];   
int rotate_to_right[maxn][maxn];   //记录筛子向右转的顶部点数 
int R,C;
int br,bc,btop,bface;
vector<p> ans;


struct State{
	int r,c;
	int top,face;
	int pre;
	State(int r=0,int c=0,int top=0,int face=0,int pre=-1):r(r),c(c),top(top),face(face),pre(pre){}
}q[maxn*maxn*maxn];

bool inside(int x,int y){
	return x>=1&&x<=R&&y>=1&&y<=C;
}

void rotate(int &top,int &face,int dir){
	if(dir==0){
		int temp=top;
		top=face;
		face=7-temp;
	}
	else if(dir==1){
		top=rotate_to_right[top][face];
	}
	else if(dir==2){
		int temp=face;
		face=top;
		top=7-temp;
	}
	else if(dir==3){
		top=7-rotate_to_right[top][face];
	}
}
void putpre(int index){
	if(index==-1) return;
	putpre(q[index].pre);
	ans.push_back(make_pair(q[index].r,q[index].c));
}

int main(void){
	rotate_to_right[1][2]=4;
	rotate_to_right[1][3]=2;
	rotate_to_right[1][4]=5;
	rotate_to_right[1][5]=3;
	
	rotate_to_right[2][1]=3;
	rotate_to_right[2][3]=6;
	rotate_to_right[2][4]=1;
    rotate_to_right[2][6]=4;
	
	rotate_to_right[3][1]=5;
	rotate_to_right[3][2]=1;
	rotate_to_right[3][5]=6;
	rotate_to_right[3][6]=2;
	
	rotate_to_right[4][1]=2;
	rotate_to_right[4][2]=6;
	rotate_to_right[4][5]=1;
	rotate_to_right[4][6]=5;
	
	rotate_to_right[5][1]=4;
	rotate_to_right[5][3]=1;
	rotate_to_right[5][4]=6;
	rotate_to_right[5][6]=3;
	
	rotate_to_right[6][2]=3;
	rotate_to_right[6][3]=5;
	rotate_to_right[6][4]=2;
	rotate_to_right[6][5]=4;
	string s;
	while(cin>>s&&s!="END"){
		cin>>R>>C>>br>>bc>>btop>>bface;
		for(int i=1;i<=R;i++){
			for(int j=1;j<=C;j++){
				cin>>map[i][j];
			}
		}
		
		memset(vis,0,sizeof(vis));
		memset(q,0,sizeof(q)); 
		ans.clear();
		bool flag=false;
		
		int head=0;
		int tail=0;
		
		q[tail++]=State(br,bc,btop,bface,-1);
		
		while(head<tail){
			State now=q[head++];
			vis[now.r][now.c][now.top][now.face]=1;
			
			for(int i=0;i<4;i++){
				int rr=now.r+dirr[i];
				int cc=now.c+dirc[i];
				int ttop=now.top;
				int fface=now.face;
				
				
				if(!inside(rr,cc)||(map[rr][cc]!=-1&&map[rr][cc]!=now.top)) continue;
				
				if(rr==br&&cc==bc){
					putpre(head-1);
					ans.push_back(make_pair(rr,cc));
					flag=true;
					break;
				}
				rotate(ttop,fface,i);
				if(!vis[rr][cc][ttop][fface]) q[tail++]=State(rr,cc,ttop,fface,head-1);
			
			}
			if(flag)break;
		}
		
		if(flag){
			cout<<s;
			for(int i=0;i<ans.size();i++){
				if(i%9==0) printf("\n  ");
				printf("(%d,%d)%c",ans[i].first,ans[i].second,i==ans.size()-1?'\n':',');
			}
		}
		else{
			cout<<s<<endl;
			printf("  No Solution Possible\n");
		}
		
	}	
} 
