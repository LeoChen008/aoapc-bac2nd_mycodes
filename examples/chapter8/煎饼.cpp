#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm> 
using namespace std;

const int maxn = 30+5;
int stack[maxn];
int temp[maxn];
int len;

void flip(int n){
	int j=0;
	for(int i=len-n;j<i;i--){
		swap(stack[j],stack[i]);
		j++;
	}
	printf("%d ",n);
}

void print(){
	for(int i=0;i<len-1;i++) printf("%d ",stack[i]);
	printf("%d\n",stack[len-1]);
}
int main(void){
	
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int cake;
	while(cin>>cake){
		len=0;
		stack[len++]=cake;
		
		while(cin.get()!='\n'&&cin>>cake){
			stack[len++]=cake;
		}
		
		/*
		* 复制栈中的序列，并排序 
		*/
		memcpy(temp,stack,len*sizeof(int));
		sort(temp,temp+len); 
		
		print();
		
		int max_i=len-1;
		for(int i=len-1;i>=0;i--){
			max_i=i;
			while(temp[i]!=stack[max_i])max_i--;
			if(max_i==i) continue;
			if(max_i>0)flip(len-max_i);
			flip(len-i);
		}
		printf("0\n");
	}
	
	//fclose(stdin);
	//fclose(stdout);	
} 
