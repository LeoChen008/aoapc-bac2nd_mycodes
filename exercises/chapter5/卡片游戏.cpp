#include<iostream>
#include<cstdio>
#include<cstring>
#include<deque>
#include<vector>

using namespace std;

int N;
vector<int> ans;
deque<int> deck;

int main(void){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	while(cin>>N&&N){
		deck.clear();
		ans.clear();

		for(int i=1;i<=N;i++){
			deck.push_back(i);
		}
		
		
		while(deck.size()>1){
			int rm=deck.front();deck.pop_front();
			ans.push_back(rm);
			
			int temp=deck.front();deck.pop_front();
			deck.push_back(temp);
		}
		
		printf("Discarded cards:");
		
		if(ans.size()>=1){
			for(int i=0;i<ans.size()-1;i++){
				printf(" %d,",ans[i]);
			}
			printf(" %d\n",ans[ans.size()-1]);
		}
		else{
			printf("\n");
		}
		printf("Remaining card: %d\n",deck.front());
	}
	
	//fclose(stdin);
	//fclose(stdout);
}
