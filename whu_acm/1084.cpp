//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include<stdio.h>
#include<string.h>

/*
 * 使用后缀数组排序，然后找最长无重叠的
 *	细节上要考虑的很多
 */


/*
 
 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <cstdlib>
 #include <algorithm>

 #define N 50050

 using namespace std;

 int r[N],wa[N],wc[N],wv[N],sa[N],wb[N],height[N],rank[N];
 int n;

 inline bool cmp(int *r,int a,int b,int l)
 {
 return r[a]==r[b]&&r[a+l]==r[b+l];
 }

 inline void da(int *r,int *sa,int n,int m)
 {
 int i,j,p,*x=wa,*y=wb,*t;
 for(i=0;i<m;i++) wc[i]=0;
 for(i=0;i<n;i++) wc[x[i]=r[i]]++;
 for(i=1;i<m;i++) wc[i]+=wc[i-1];
 for(i=n-1;i>=0;i--) sa[--wc[x[i]]]=i;
 for(j=1,p=1;p<n;j<<=1,m=p)
 {
 for(i=n-j,p=0;i<n;i++) y[p++]=i;
 for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
 for(i=0;i<n;i++) wv[i]=x[y[i]];
 for(i=0;i<m;i++) wc[i]=0;
 for(i=0;i<n;i++) wc[wv[i]]++;
 for(i=1;i<m;i++) wc[i]+=wc[i-1];
 for(i=n-1;i>=0;i--) sa[--wc[wv[i]]]=y[i];
 for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
 x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
 }
 }

 inline void getheight(int *r,int *sa,int n)
 {
 int i,j,k=0;
 for(i=1;i<=n;i++) rank[sa[i]]=i;
 for(i=0;i<n;height[rank[i++]]=k)
 for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
 }

 inline bool check(int x)
 {
 int mx=sa[1],mn=sa[1];
 for(int i=2;i<n;i++)
 {
 if(height[i]<x) mx=mn=sa[i];
 else
 {
 mx=max(mx,sa[i]);
 mn=min(mn,sa[i]);
 if(mx-mn>=x) return true;
 }
 }
 return false;
 }

 inline void getans()
 {
 int l=4,r=(n>>1)+1,mid,res;
 while(l<=r)
 {
 mid=(l+r)>>1;
 if(check(mid)) res=mid,l=mid+1;
 else r=mid-1;
 }
 if(res<4) puts("0");
 else printf("%d\n",res+1);
 }

 inline void go()
 {
 n--;
 for(int i=0;i<=n;i++) scanf("%d",&r[i]);
 if(n<10) {puts("0");return;}
 for(int i=0;i<n;i++) r[i]=r[i]-r[i+1]+90;
 r[n]=0;
 da(r,sa,n+1,200);
 getheight(r,sa,n);
 getans();
 }

 int main()
 {
 while(scanf("%d",&n),n) go();
 return 0;
 }
 */
#endif