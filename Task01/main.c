#include <stdio.h>
#include <string.h>
#define MAX_PATIENTS 100
typedef struct {int day,month,year;} Date;
typedef struct {int systolic,diastolic;} BloodPressure;
typedef struct {char name[50],phone[16];int age;BloodPressure bp;Date visit;} Patient;
static int addPatient(Patient *p,const Patient *src){if(!p||!src)return 0;*p=*src;return 1;}
int main(void){Patient patients[MAX_PATIENTS]={0};Patient p={"Anitha","9876543210",42,{120,80},{19,11,2026}};if(!addPatient(&patients[0],&p))return 1;printf("%s age %d BP %d/%d phone %s visit %02d/%02d/%04d\n",patients[0].name,patients[0].age,patients[0].bp.systolic,patients[0].bp.diastolic,patients[0].phone,patients[0].visit.day,patients[0].visit.month,patients[0].visit.year);return 0;}
