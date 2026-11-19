#include <stdio.h>
#include <string.h>
#define MAX_ITEMS 20
enum item_kind{PACKAGED,COOKED,COMBO};
typedef struct{int d,m,y;} Date;
typedef struct{int hour,minute;} Clock;
typedef struct{enum item_kind kind;int id;char name[30];float price;int stock;union{Date expiry;Clock prepared;int component_ids[3];}detail;int component_count;float revenue;} Item;
static int sell(Item *x,int qty){if(!x||qty<=0||qty>x->stock)return 0;x->stock-=qty;x->revenue+=x->price*qty;return 1;}
static void expiry_warning(const Item a[],int n){for(int i=0;i<n;++i)if(a[i].kind==PACKAGED&&a[i].detail.expiry.y==2026&&a[i].detail.expiry.m==11&&a[i].detail.expiry.d<=21)printf("Expiry warning: %s\n",a[i].name);}
static void sort_revenue(Item a[],int n){for(int i=1;i<n;++i){Item v=a[i];int j=i-1;while(j>=0&&a[j].revenue<v.revenue){a[j+1]=a[j];--j;}a[j+1]=v;}}
int main(void){Item a[3]={{PACKAGED,1,"Milk",30,5,{.expiry={20,11,2026}},0,0},{COOKED,2,"Rice meal",60,10,{.prepared={11,30}},0,0},{COMBO,3,"Combo",80,3,{.component_ids={1,2,0}},2,0}};printf("normal sale: %s\n",sell(&a[0],2)?"accepted":"rejected");printf("oversell: %s\n",sell(&a[0],99)?"accepted":"rejected");sell(&a[1],3);expiry_warning(a,3);sort_revenue(a,3);puts("Revenue summary:");for(int i=0;i<3;++i)printf("%s Rs.%.2f stock=%d\n",a[i].name,a[i].revenue,a[i].stock);return 0;}
