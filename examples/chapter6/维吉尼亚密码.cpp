#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;

const int maxn=100;

int plaintext[maxn];
int cipher[maxn];
int key[maxn];
char key_buffer[maxn];
char plaintext_buffer[maxn];
char cipher_text[maxn];

int lenk;
int lent;
void generatekey(){
	srand((unsigned int)time(NULL));
	lenk=lent;
	
	int i;
	for(i=0;i<lenk;i++){
		key[i]=rand()%26;
	}
}

void encrypt(){
	cout<<"please input the plaintext:\n";
	gets(plaintext_buffer);
	lent=strlen(plaintext_buffer);
	
	int i,j=0;
	for(i=0;i<lent;i++){
		if(plaintext_buffer[i]!=' ')
		plaintext[j++]=plaintext_buffer[i]<'a'?plaintext_buffer[i]-'A':plaintext_buffer[i]-'a';
	}
	lent=j;
	
	
	cout<<"Please input the key(or press 1 to generate a random key):\n";
	gets(key_buffer);
	lenk=strlen(key_buffer);
	
	if(lenk==1&&key_buffer[0]-'1'==0){
		generatekey();
		cout<<"The key is:\n";
		for(i=0;i<lenk;i++){
			printf("%c",key[i]+'a');
		}
		printf("\n");
	}
	else{
		for(i=0;i<lenk;i++){
			key[i]=key_buffer[i]-'a';
		}
	}
	
	
	j=0;
	for(i=0;i<lent;i++){
		cipher[i]=(plaintext[i]+key[(j++)%lenk])%26;
	}
	
	for(i=0;i<lent;i++){
		cipher_text[i]=cipher[i]+'A';
	}
	
	cout<<"The cipher of plaintext is:\n";
	for(i=0;i<lent;i++) printf("%c",cipher_text[i]);
	printf("\n");
}

void decrypt(){
	cout<<"Please input the cipher:\n";
	gets(cipher_text);
	cout<<"Please input the key:\n";
	gets(key_buffer);
	lenk=strlen(key_buffer);
	lent=strlen(cipher_text);
	
	int i;
	
	for(i=0;i<lenk;i++){
		key[i]=key_buffer[i]-'a';
	} 
	
	for(i=0;i<lent;i++){
		cipher[i]=cipher_text[i]-'A';
	}
	
	int j=0;
	for(i=0;i<lent;i++){
		plaintext[i]=(cipher[i]-key[(j++)%lenk]+26)%26;
	}
	
	cout<<"The plain text is:\n";
	for(i=0;i<lent;i++){
		printf("%c",plaintext[i]+'a'); 
	}
	printf("\n");
}
int main(void){
	while(1){
		string choose;
		cout<<"Would you like to encrypt or decrypt?(1 for encrypt and 2 for decrypt)\n";
		if(getline(cin,choose)&&choose.length()==1){
			if(choose[0]=='1') encrypt();
			else if(choose[0]=='2') decrypt();
			else continue;
		}else{
			continue;
		}
	}
} 
