#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxd=20;

int tree[1<<maxd];

void fast_way(){
	int D,I,n;
	while(cin>>n&&n!=-1){
		while(n--){
			cin>>D>>I;
			int k=1;
			for(int i=1;i<=D-1;i++){
				if(I%2==1){
					k=k*2;
					I=(I+1)/2;
				}
				else{
					k=k*2+1;
					I/=2;
				}
			}
			printf("%d\n",k);
		}
	}
	
}

int main(void){
	/*int n,D,I;
	while(cin>>n&&n!=-1){
		while(n--){
			cin>>D>>I; 
	        memset(tree,0,sizeof(tree));
		    int k;
		    int node=(1<<D)-1; 
		    for(int i=0;i<I;i++){
			    k=1;
			    while(true){
				    tree[k]=!tree[k];
				    k=tree[k]?2*k:2*k+1;
				    if(k>node) break;
			    }
		    }
		    printf("%d\n",k/2);
		}
	}*/
	fast_way();
	
} 
