/*
* Created by LeoChen008
*/
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxd = 6+2;
const int maxs = 64+5;
const int maxb = 100+5;

char datas[maxd][maxs*maxb];
int check_bit;

inline void translate(int disk,int size,int blocks,char *ans){
	char hex;
	int n=0;
	int cnt=0;
	for(int i=0;i<size*blocks;i+=size){
		for(int j=0;j<disk;++j){
			if((i/size)%disk==j) continue; 
			
			for(int m=i;m<i+size;++m){
				n=n<<1;
				n+=datas[j][m]-'0';
				cnt++;
				if(cnt==4){
					hex=n>=10?n-10+'A':n+'0';
					*ans=hex;
					ans++;
					n=0;cnt=0;
				}
			}
		}
	}
	if(cnt){
		n=n<<(4-cnt);
		hex=n>=10?n-10+'A':n+'0';
		*ans=hex;
		ans++;
	}
}
bool solve(int disk,int len){

	int pos=-1;
	int check=0;
	char chr;
	
	for(int i=0;i<len;++i){
		check=0;
		pos=-1;
		
		for(int j=0;j<disk;++j){
			chr=datas[j][i];
			
			if(chr=='x'){
				if(pos!=-1) return false;
				
				pos=j;
			}
			else if(chr=='1'){
				check=!check;	
			}
		}
		
		if(pos==-1&&check!=check_bit) return false;
		if(pos!=-1){
			datas[pos][i]=check_bit==check?'0':'1';
		} 
		
	}//for i	
	return true;
}
int main(void){
	int kcase=0;
	int s,d,b;
	char ans[maxs*maxb*maxd];
	string check;
	while(cin>>d&&d){
		cin>>s>>b;
		
		cin>>check;
		if(check=="E") check_bit=0;
		else if(check=="O") check_bit=1;
		
		memset(datas,0,sizeof(datas));
		memset(ans,0,sizeof(ans));
				
		for(int i=0;i<d;++i){
			scanf("%s",datas[i]);
		}
		
		
		if(solve(d,s*b)){
			translate(d,s,b,ans);
			printf("Disk set %d is valid, contents are: %s\n",++kcase,ans);
		}else {
			printf("Disk set %d is invalid.\n",++kcase);
		}
	} 
} 
