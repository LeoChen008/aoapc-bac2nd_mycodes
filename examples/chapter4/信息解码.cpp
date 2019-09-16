#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int code[8][1<<8];
int readchar(){
	while(1){
		int ch=getchar();
		if(ch!='\n'&&ch!='\r')return ch;
	}
}
int readheader(){
	memset(code,0,sizeof(code));
	code[1][0]=readchar();
	for(int len=2;len<=7;len++){
		for(int i=0;i<(1<<len)-1;i++){
			int ch=getchar();
			if(ch==EOF)return 0;
			if(ch=='\n'||ch=='\r')return 1;
			code[len][i]=ch;
		}
	}
	return 1;
}
int readint(int len){
	int v=0;
	while(len--){
		v=v*2+readchar()-'0';
	}
	return v;
}
void printcode(){
	for(int len=1;len<=7;len++){
		for(int i=0;i<(1<<len)-1;i++){
			if(code[len][i]==0)return;
			printf("code[%d][%d]=%c\n",len,i,code[len][i]);
		}
	}
}
int main(){
	while(readheader()){
		//printcode();
		while(1){
			int len=readint(3);
			if(len==0)break;
			//printf("len=%d\n",len);
			while(1){
				int value=readint(len);
				//printf("val=%d\n",value);
				if(value==(1<<len)-1)break;
				putchar(code[len][value]);
			}
		}
		printf("\n");
	}
}
