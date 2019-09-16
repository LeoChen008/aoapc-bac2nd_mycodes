#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<deque> 
#include<set>
using namespace std;

const int maxn=52;
const int maxm=7;

vector< deque<int> > piles;

set< vector< deque<int> > > inloop;
int empty[maxm];
int count;
int res;

bool pickup(int a,int b,int c){
	int sum=a+b+c;
	if(sum==10||sum==20||sum==30){
		return true;
	}
	return false;
}

bool allempty(){	
	for(int i=0;i<maxm;i++){
		if(empty[i]==0)return false;
	}
	return true;
}


int main(void){
	
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int value;
	while(cin>>value&&value){
		memset(empty,0,sizeof(empty));
		piles.clear();
		inloop.clear();
		count=0;
		res=3;
		
		for(int i=1;i<=8;i++){
			piles.push_back(deque<int>());
		}
		piles[7].push_back(value);
		
		for(int i=1;i<=maxn-1;i++){
			cin>>value;
			piles[7].push_back(value);
		}
		
		for(int i=0;i<7;i++){
			piles[i].push_back(piles[7].front());
			piles[7].pop_front();
			count++;
		}
		
		
		int first1,first2,last1,last2,last3;
			
		deque<int> temp;
		
		
		for(int i=0;i<piles.size()-1;i=(i+1)%maxm){
			
			if(empty[i]) continue;
			
			if(piles[7].empty()){
				res=2;
				break;
			}
			
			int card=piles[7].front();piles[7].pop_front();
			piles[i].push_back(card);
			temp=piles[i];
			count++;
		
			while(1){
				
				if(temp.size()>=3){
					first1=temp[0];
					first2=temp[1];
					last3=temp[temp.size()-3];
					last2=temp[temp.size()-2];
					last1=temp[temp.size()-1];
						
					if(pickup(first1,last1,last2)){
						temp.pop_front();
						temp.pop_back();
						temp.pop_back();
						
						piles[7].push_back(first1);
						piles[7].push_back(last2);
						piles[7].push_back(last1);
					}
					else if(pickup(first1,first2,last1)){
						temp.pop_front();
						temp.pop_front();
						temp.pop_back();
						
						piles[7].push_back(first1);
						piles[7].push_back(first2);
						piles[7].push_back(last1);
						
					}else if(pickup(last1,last2,last3)){
						temp.pop_back();
						temp.pop_back();
						temp.pop_back();
						
						piles[7].push_back(last3);
						piles[7].push_back(last2);
						piles[7].push_back(last1);
					}else{
						break;
					}
				}
				else{
					break;
				}
			}
				
			piles[i]=temp;
				
			if(piles[i].empty()){
				empty[i]=1;
				if(allempty()){
					res=1;
					break;
				}
			}
			
			if(inloop.find(piles)!=inloop.end()){
				break;
			}
			inloop.insert(piles);
			
			
		}
		if(res==1){
			printf("Win : %d\n",count);
		}else if(res==2){
			printf("Loss: %d\n",count);
		}else{
			printf("Draw: %d\n",count);
		}
	}
	
	fclose(stdin);
	fclose(stdout);
} 
