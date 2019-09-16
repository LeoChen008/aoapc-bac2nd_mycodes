#include<iostream>

using namespace std;


bool is_equal(int &w){
	int wl,wr,dl,dr;
	bool left=true,right=true;
	
	cin>>wl>>dl>>wr>>dr;
	
	if(!wl) left=is_equal(wl);
	if(!wr) right=is_equal(wr);
	
	w=wl+wr;
	
	if(left&&right&&(wl*dl==wr*dr)) return true;
	
	return false;
}
int main(void){
	int w;
	int n;
	cin>>n;
	while(n--){
		if(is_equal(w)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
		if(n) cout<<endl; 
	}
}
