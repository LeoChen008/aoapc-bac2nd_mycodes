#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<set> 
#include<map>
using namespace std;


struct Order{
	string cmd;
	int price;
	int size;	
	int id;
}; 

map<int,set<int> > buyorders;
map<int,set<int> > sellorders;
map<int,int> buysum;
map<int,int> sellsum;
vector<Order> cmds;
int kcase=0;

void solve(int flag){
	while(!buyorders.empty()&&!sellorders.empty()){
		
		int bidprice=buysum.rbegin()->first;
		int askprice=sellsum.begin()->first;
		
		if(bidprice>=askprice){
			set<int>::iterator iter1=buyorders[bidprice].begin();
			set<int>::iterator iter2=sellorders[askprice].begin();
			int minsize=min(cmds[*iter1].size,cmds[*iter2].size);
			cmds[*iter1].size-=minsize;
			cmds[*iter2].size-=minsize;
			buysum[bidprice]-=minsize;
			sellsum[askprice]-=minsize;
			
			
			cout<<"TRADE "<<minsize<<" "<<(flag?bidprice:askprice)<<endl;
			if(cmds[*iter1].size==0){
				buyorders[bidprice].erase(*iter1);
			}
			if(cmds[*iter2].size==0){
				sellorders[askprice].erase(*iter2);
			}
			if(buyorders[bidprice].empty()){
				buyorders.erase(bidprice);
			}
			if(sellorders[askprice].empty()){
				sellorders.erase(askprice);
			}
			if(buysum[bidprice]==0){
				buysum.erase(bidprice);
			}
			if(sellsum[askprice]==0){
				sellsum.erase(askprice);
			} 
		}else{
			return;
		}
	}
}
void print_quote(){
	cout<<"QUOTE ";
	if(buysum.empty()){
		cout<<"0 0 - ";
	}else{
		cout<<buysum.rbegin()->second<<" "<<buysum.rbegin()->first<<" - ";
	}
	
	if(sellsum.empty()){
		cout<<"0 99999"<<endl;
	}else{
		cout<<sellsum.begin()->second<<" "<<sellsum.begin()->first<<endl;
	} 
}
void init(){
	buyorders.clear();
	sellorders.clear();
	buysum.clear();
	sellsum.clear();
	cmds.clear();
}
int main(void){
	int T;
	while(cin>>T){
		
		init();
		
		if(kcase++) cout<<endl;
		
		for(int i=0;i<T;i++){
			Order order;
		  	cin>>order.cmd;
		  	
			if(order.cmd=="BUY"){
				cin>>order.size;
				cin>>order.price;
				
				buyorders[order.price].insert(i);
				buysum[order.price]+=order.size;
				cmds.push_back(order);
				
				solve(0);
			}
			else if(order.cmd=="SELL"){
				cin>>order.size;
				cin>>order.price;
				
				sellorders[order.price].insert(i);
				sellsum[order.price]+=order.size;
				cmds.push_back(order);
				
				solve(1);
			}
			else{
				//CANCLE 命令的处理模块 
				
				int id,price,size;
				cin>>id;
				order.id=id--;
				cmds.push_back(order);
				
				price=cmds[id].price;
				size=cmds[id].size;
				
				if(cmds[id].cmd=="BUY"){					
					buysum[price]-=size;
					buyorders[price].erase(id);
					
					if(buysum[price]==0){
						buysum.erase(price);
					}
					if(buyorders[price].empty()){
						buyorders.erase(price);
					}
					
					cmds[id].size=0;
				}
				else if(cmds[id].cmd=="SELL"){
					sellsum[price]-=size;
					sellorders[price].erase(id);
					
					if(sellsum[price]==0){
						sellsum.erase(price);
					}
					if(sellorders[price].empty()){
						sellorders.erase(price);
					}
					
					cmds[id].size=0;
				}
			}
			
			print_quote();
		}
		
	}
	
}
