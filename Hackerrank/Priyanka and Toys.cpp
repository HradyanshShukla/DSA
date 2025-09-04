#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int N; scanf("%d", &N);
    priority_queue<int, vector<int>, greater<int> > q;
    int s;
    for(int n = 0; n<N; n++){
        scanf("%d", &s);
        q.push(s);
    }
    int current = 0, count = 0;
    while(!q.empty()){
        current = q.top(); q.pop();
        while(q.top()<=current+4 && !q.empty()) q.pop();
        count++;
    }
    if(count>0) printf("%d\n", count);
    else printf("0\n");
    return 0;
}
