#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<cstring>
using namespace std;

const int maxa=26;
int vis[maxa][maxa];
int g[maxa][maxa];	
int in[maxa];       //����� 
int out[maxa];		//������ 
int N;
string buffer;

void eulerpath(int u){
	for(int v=0;v<maxa;v++){
		if(g[u][v]&&!vis[u][v]){
			vis[u][v]=1;
			eulerpath(v);
		}
	}
}
bool has_eulerpath(){
	//�ж��Ƿ���ŷ����·
	 
	int count=0;	//����� 
	int start=-1;	//��� 
	
	for(int i=0;i<maxa;i++){					
		if(in[i]!=out[i]){
			count++;
			if(count<=2&&out[i]-in[i]==1) start=i; //�������ʱȷ����� 
			else if(count>2) return false;	//�����������ͷ���ʧ�� 
		}
		else if(in[i]>0&&start==-1){
			start=i;			//���������ʱȷ�����			
		}
	}
	
	memset(vis,0,sizeof(vis));
	
	eulerpath(start);  //dfs���ͼ����ͨ�� 
	
	for(int u=0;u<maxa;u++)
		for(int v=0;v<maxa;v++){
			if(g[u][v]&&!vis[u][v]){	//��������޷����ʵı߾ͷ���ʧ�� 
				return false;
			}
		}
		
	return true;	
}

bool has_eulercircle(){
	//�ж��Ƿ���ŷ����·
	
	int start=-1;	//��� 
	
	 
	for(int i=0;i<maxa;i++){					
		if(in[i]!=out[i]){
			return false;      //�����ͷ���ʧ�� 
		}
		else if(in[i]>0&&start==-1){
			start=i;			//ȷ��һ����� 
		}
	}
	
	memset(vis,0,sizeof(vis));
	
	eulerpath(start);  //dfs���ͼ����ͨ�� 
	
	for(int u=0;u<maxa;u++)
		for(int v=0;v<maxa;v++){
			if(g[u][v]&&!vis[u][v]){	//��������޷����ʵı߾ͷ���ʧ�� 
				return false;
			}
		}
		
	return true;	

} 

int main(void){
	int T;
	cin>>T;
	while(T--){
		memset(g,0,sizeof(g));
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		cin>>N;
		for(int i=0;i<N;i++){
			cin>>buffer;
			int u=buffer.at(0)-'a';
			int v=buffer.at(buffer.length()-1)-'a';
			g[u][v]++;
			in[v]++;
			out[u]++;
		}

		/*if(has_eulerpath()){
			cout<<"Ordering is possible."<<endl;
		}
		else{
			cout<<"The door cannot be opened."<<endl;
		}*/
		
		if(has_eulercircle()){
			cout<<"Is a euler circle"<<endl;
		}
		else{
			cout<<"Not a euler circle"<<endl;
		}
	}	
} 
