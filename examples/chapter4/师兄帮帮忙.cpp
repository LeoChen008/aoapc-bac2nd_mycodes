#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#define maxn 1000
using namespace std;
struct Student{
	string name,sid;
	int cid;
	int chn;
	int math;
	int eng;
	int pro;
}stu[100];
int num=0;
void menu(){
	printf("Welcome to Student Performance Management System (SPMS).\n");
	cout<<endl;
	cout<<"1 - Add"<<endl;
	cout<<"2 - Remove"<<endl;
	cout<<"3 - Query"<<endl;
	cout<<"4 - Show ranking"<<endl;
	cout<<"5 - Show Statistic"<<endl;
	cout<<"0 - Exit"<<endl;
} 
void dq(int mode){
	if(mode){
		//
	}
	else{
		//
	}
}
void show_statics(){
	//
}
void add(){
	while(1){ 
		 char s[10]; 
	     cout<<"Please enter the SID, CID, name and four scores. Enter 0 to finish."<<endl;
	     scanf("%s",s); 
	     if(strlen(s)==1)break;
	     stu[num].sid=s;
	     scanf("%d",&stu[num].cid);
	     scanf("%s",&stu[num].name);
	     scanf("%d%d%d%d",&stu[num].chn,&stu[num].math,&stu[num].eng,&stu[num].pro);
		 num++;  
	}
}
int main(){
	while(1){
		int choice;
		menu();
		scanf("%d",&choice);
		if(choice==0)break;
		switch(choice){
			case 1:add();break;
			//case 2:dq(0);break;
			//case 3:dq(1);break;
			case 4:printf("Showing the ranklist hurts students¡¯ self-esteem. Don¡¯t do that.\n");
			break;
			//case 5:show_statics();break;
		}
	}
} 
