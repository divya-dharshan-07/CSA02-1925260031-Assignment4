#include <stdio.h>
#include <string.h>
struct date{int day,month,year;};
struct address{char name[30],city[20];int pincode;};
struct parcel{int id;float weight;struct address from,to;struct date booked;int express;float charge;};
static void print_parcel(const struct parcel *p){printf("%d %.1f kg %s-%d %02d/%02d/%04d\n",p->id,p->weight,p->to.city,p->to.pincode,p->booked.day,p->booked.month,p->booked.year);}
static void sort_by_weight(struct parcel p[],int n){for(int i=0;i<n-1;++i){int m=i;for(int j=i+1;j<n;++j)if(p[j].weight<p[m].weight)m=j;if(m!=i){struct parcel t=p[i];p[i]=p[m];p[m]=t;}}}
int main(void){struct parcel p[3]={{501,4.5f,{"A","Salem",636001},{"X","Madurai",625001},{12,10,2026},0,80},{502,1.2f,{"B","Trichy",620001},{"Y","Chennai",600077},{12,10,2026},1,120},{503,2.8f,{"C","Erode",638001},{"Z","Coimbatore",641001},{13,10,2026},0,90}};sort_by_weight(p,3);for(int i=0;i<3;++i)print_parcel(&p[i]);printf("receiver PIN via dot: %d\n",p[2].to.pincode);struct parcel *q=&p[2];printf("via arrow: %d\n",q->to.pincode);return 0;}
