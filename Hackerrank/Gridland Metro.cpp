#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct gg{
int c,l,r;
};
bool cmp(gg a, gg b){
return (a.c<b.c || ( (a.c==b.c) && ( (a.l<b.l) || ( (a.l==b.l) && (a.r,b.r) ) ) ) );
}
long long gt,n,m;
int k,l,r;
gg a[1001];
int main() {
cin>>n>>m>>k;
for (int i=1;i<=k;i++)
cin>>a[i].c>>a[i].l>>a[i].r;
sort(a+1,a+1+k,cmp);
gt=n*m;
l=a[1].l;
r=a[1].r;
k++;
a[k].c=n+1;
for (int i=2;i<=k;i++)
if (a[i].c==a[i-1].c){
if (a[i].l>r){
gt=gt-(r-l+1);
l=a[i].l;
}
r=max(r,a[i].r);
}else{
gt=gt-(r-l+1);
l=a[i].l;
r=a[i].r;
}
cout<<gt;
return 0;
}
