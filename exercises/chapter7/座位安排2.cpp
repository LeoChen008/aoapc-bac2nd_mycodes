#include <cstdio>
#include <cstring>

int n, k;
char seat[25][25], ans[25][25];

bool dfs(int id, char ch){
    while(ans[id/n][id%n] != '.') id++;
    if(id == n * n) return true;
    int sr = id / n, sc = id % n, ec = n;
    for(int r = sr; r < n; r++){
        for(int c = sc; c < ec; c++){
            if(ans[r][c] != '.') { ec = c;  break; }
            int sum = (r - sr + 1) * (c - sc + 1);
            if(sum > 9) { ec = c;  break; }
            int digit = 99;
            bool valid = true;
            for(int t = sr; t <= r; t++){
                for(int i = sc; i <= c; i++){
                    if(seat[t][i] != '.'){
                        if(digit != 99){ valid = false;  break; }
                        digit = seat[t][i] - '0';
                    }
                }
                if(!valid) break;
            }
            if(!valid) { ec = c;  break; }
            if(digit < sum) { ec = c;  break; }
            if(digit > sum) continue;
            for(int t = sr; t <= r; t++){
                for(int i = sc; i <= c; i++) ans[t][i] = ch;
            }
            if(dfs(id + c - sc + 1, ch + 1)) return true;
            for(int t = sr; t <= r; t++){
                for(int i = sc; i <= c; i++) ans[t][i] = '.';
            }
        }
    }
    return false;
}

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout); 
    while(scanf("%d%d", &n, &k) && n){
        memset(ans, '.', sizeof(ans));
        for(int r = 0; r < n; r++) scanf("%s", seat[r]);
        dfs(0, 'A');
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++) printf("%c", ans[r][c]);
            printf("\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
