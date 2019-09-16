#include<cstdio>

const int maxn=100000+10;

int left[maxn],right[maxn];
int n,m;

void linked(int L,int R){
	right[L]=R;
	left[R]=L;
}
void swap(int L,int R){
	int ll=left[L],rr=right[R];
	linked(ll,R);
	linked(R,L);
	linked(L,rr);
}
 
int main(void){
	int kcase=0;
	while(scanf("%d%d",&n,&m)==2){
		int op,x,y,flag=0;
		for(int i=1;i<=n;i++){
			left[i]=i-1;
			right[i]=(i+1)%(n+1);
		}
		right[0]=1;
		left[0]=n;
		
		for(int i=0;i<m;i++){
			scanf("%d",&op);
			if(op==4){
				flag=!flag;
			}
			else{
				scanf("%d%d",&x,&y);
			    if(op!=3&&flag) op=3-op;
				else if(op==1&&x==left[y]) continue;
				else if(op==2&&x==right[y]) continue;
				
				int lx=left[x],rx=right[x],ly=left[y],ry=right[y];
				if(op==1){
					linked(lx,rx);
					linked(ly,x);
					linked(x,y);
				}
				else if(op==2){
					linked(lx,rx);
					linked(y,x);
					linked(x,ry);
				}
				else if(op==3){
					if(right[x]==y){
						swap(x,y);
					}
					else if(right[y]==x){
						swap(y,x);
					}
					else{
					    linked(lx,y);
					    linked(y,rx);
					    linked(ly,x);
					    linked(x,ry);
				   } 
				}
			}
		}
		int j=0;
		long long sum=0;
		for(int i=1;i<=n;i++){
			j=right[j];
			if(i%2==1){
				sum+=j;
			}
		}
		if(flag&&n%2==0){
			sum=(long long)n*(n+1)/2-sum;
		} 
		printf("Case %d: %lld\n",++kcase,sum);
	}
} 
