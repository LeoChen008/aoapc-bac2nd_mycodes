#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctype.h>
#include<string>
#include<sstream>
#include<map>
#include<vector>

using namespace std;

const int maxn=100+10;
const int maxm=1500+10;

int n,m,iindex=0;
int docstart[maxn];          //记录 每个文档的开始行序号 

string docs[maxm];       //记录具体文档的内容 

struct Exist{
	bool ifexist[maxm];
	Exist(){
		memset(ifexist,0,sizeof(ifexist)); 
	}
};

map<string,Exist> inverttable; 
 

void construct_inverttable(string str){
	string s;
	int len=str.length();
	
	for(int i=0;i<len;i++){
		if(isalpha(str[i])){
			str[i]=tolower(str[i]);
		}else{
			str[i]=' ';
		}
	}
	stringstream ss(str);
	while(ss>>s){
		inverttable[s].ifexist[iindex]=true;
	}
	
}
void searchtable(string query,bool *output){
	
	bool *p1,*p2;
	string word1,word2;
	
	if(query[0]=='N'){
		word1=query.substr(4);
		p1=inverttable[word1].ifexist;
		
		
		for(int i=0;i<n;i++){
			
			bool flag=true;
			
			for(int j=docstart[i];j<docstart[i+1];j++){
				
				if(p1[j]){
					flag=false;
					break;
				}
			}
			
			for(int j=docstart[i];j<docstart[i+1];j++){
				output[j]=flag;
			}
		}
	}
	else if(query.find("AND")!=string::npos){
		int p=query.find(" AND ");
		word1=query.substr(0,p);
		word2=query.substr(p+5);
		
		p1=inverttable[word1].ifexist;
		p2=inverttable[word2].ifexist;
		
		memset(output,0,sizeof(output));
		for(int i=0;i<n;i++){
			
			bool flag1=false,flag2=false;
			
			for(int j=docstart[i];j<docstart[i+1];j++){
				if(p1[j]){
					flag1=true;
					break;
				}
			}
			
			for(int j=docstart[i];j<docstart[i+1];j++){
				if(p2[j]){
					flag2=true;
					break;
				}
			}
			
			if(!flag1||!flag2) continue;
			
			for(int j=docstart[i];j<docstart[i+1];j++){
				output[j]=(p1[j]||p2[j]);
			}
		}
		
	}
	else if(query.find("OR")!=string::npos){
		int p=query.find(" OR ");
		word1=query.substr(0,p);
		word2=query.substr(p+4);
		
		p1=inverttable[word1].ifexist;
		p2=inverttable[word2].ifexist;
		
		for(int i=0;i<iindex;i++){
			output[i]=(p1[i]||p2[i]);
		}
		
	}
	else{
		p1=inverttable[query].ifexist;
		
		for(int i=0;i<iindex;i++){
			output[i]=p1[i];
		}
	}
	
}


int main(void){
	
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	cin>>n;
	getchar();
	string buffer;
	
	for(int i=0;i<n;i++){
		docstart[i]=iindex;
		while(getline(cin,buffer)){
			if(buffer=="**********") break;
			docs[iindex]=buffer;
			construct_inverttable(buffer);
			iindex++;
		}
	}
	
	docstart[n]=iindex;
	
	cin>>m;
	getchar();
	string query;			//搜索的问句 
	bool outputlines[maxm];    //记录应该输出的行 
	bool flag=false,flag2=false;
	//memset(outputlines,0,sizeof(outputlines));
	
	while(m--){
		getline(cin,query);
		memset(outputlines,0,sizeof(outputlines));
		
		searchtable(query,outputlines);
		flag=flag2=false;
		
		for(int i=0;i<n;i++){
			if(flag) flag2=true;
			flag=false;
			
			for(int j=docstart[i];j<docstart[i+1];j++){
				if(outputlines[j]){
					if(flag2) {
						cout<<"----------"<<endl;
						flag2=false;
					}
					
					cout<<docs[j]<<endl;
					flag=true;
				}
			}
			
		}
		if(!(flag||flag2)) cout<<"Sorry, I found nothing."<<endl;
		
		cout<<"=========="<<endl;
	}
	
	//fclose(stdin);
	//fclose(stdout);
}
