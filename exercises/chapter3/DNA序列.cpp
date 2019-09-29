#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1050
using namespace std;
char dna[maxn][maxn];
int hamming(char c){
	int i=0;
	switch(c){
		case 'A':i=0;break;
		case 'T':i=1;break;
		case 'C':i=2;break;
		case 'G':i=3;break;
		default:break;
	}
	return i;
}
char helper(int i){
	char ch;
	switch(i){
		case 0:ch='A';break;
		case 1:ch='T';break;
		case 2:ch='C';break;
		case 3:ch='G';break;
		default:break;
	}
	return ch;
}
char the_biggest(int *atcg){
	int max=-50;
	char ch;
	for(int i=0;i<4;i++){
		if(atcg[i]>max){
			max=atcg[i];
			ch=helper(i);
		}
		else if(max==atcg[i]){
			if(ch-'A'>helper(i)-'A'){
				ch=helper(i);
			}
		}
	}
	return ch;
}
int main(){
	int T,n,m,count;
	cin>>T; 
	while(T--){
		cin>>m>>n;
		count=0;
		getchar();
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				scanf("%c",&dna[i][j]);
			}
			getchar();
		}
		for(int j=0;j<n;j++){
			char ch;
			int atcg[4];
			memset(atcg,0,sizeof(atcg));
			for(int i=0;i<m;i++){
				switch(dna[i][j]){
					case 'T':atcg[1]+=1;break;
					case 'A':atcg[0]+=1;break;
					case 'C':atcg[2]+=1;break;
					case 'G':atcg[3]+=1;break;
					default:break;
				}
			}
			ch=the_biggest(atcg);
			printf("%c",ch);
			count+=m-atcg[hamming(ch)];
		}
		cout<<endl;
		cout<<count<<endl;
	}
} 
