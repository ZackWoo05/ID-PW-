#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string>
#include <fstream>
#include <cstdlib>
#define FALSE 0
#define TRUE 1
using namespace std;

int n, message_length;

int GCD(long x, long y)      

{    return y == 0 ? x : GCD(y, x % y) ;  }

int Make_Public_Key(long e_pi)

{

   long e;

   do

   {

      e=rand()%100;  
      if ( (e<e_pi) && (GCD(e,e_pi)==1) ) return e;  

   }while(1);

}


int Make_Private_Key(int e, long e_pi)

{

   int d=0;

   while (((e*d)%e_pi)!=1) d++;      

   return d;  

}



int IsNotPrime(int n)      

{

   int  i, limit;

   if (!(n%2))  return (TRUE);  

   limit = (int)sqrt(n) + 1;  

   for (i = 3; i <= limit; i += 2)  
      if (!(n%i))  return (TRUE);

   return (FALSE);

}


long Make_Random_Prime_Number()

{

   int i;

   int Prime[2];

   time_t t;

   srand((unsigned int) time(&t));

   for (i=0; i<2; i++)        

   {

      do{

      Prime[i]=rand()%1000;      

      }while(IsNotPrime(Prime[i]) );    

   }

   n=Prime[0]*Prime[1];      

   printf("\nP=%d, Q=%d e_pi=%d n=%d \n", Prime[0], Prime[1], n);

   return (Prime[0]-1)*(Prime[1]-1);  

}


long mod(long n, long e, long m)

{

   long i, residue = 1;

   for(i=1; i<=e; i++)

   {

      residue *= n;  

      residue %= m;  

   }

   return residue;

}

void itoa(int num, char *str){
    int i=0;
    int radix = 10;  
    int deg=1;
    int cnt = 0;

    while(1){    
        if( (num/deg) > 0)
            cnt++;
        else
            break;
        deg *= radix;
    }
    deg /=radix;  
   
    for(i=0; i<cnt; i++)    {    
        *(str+i) = num/deg + '0';    
        num -= ((num/deg) * deg);      
        deg /=radix;    
    }
    *(str+i) = '\0';  
}

int atoia(char str){    
    cout<<str<<endl;
    int tot=0;
    while(str){    
        tot = tot*10 + str - '0';  
        str++;    
    }
    return tot;
}

int Make_Cyper_text(char *Plain_text, long *Cyper_text, int key)

{

  int i;

  message_length=strlen(Plain_text);

  for(i=0; i<message_length; i++)  

    Cyper_text[i]= (long)mod( Plain_text[i], key, n);  

  Cyper_text[i] = '\0';  



  printf("====================================================\n");

  printf(" 암호화된 데이터 = ");

  for ( i=0; i<message_length; i++)  

    printf(" %d ",Cyper_text[i]);  

  printf("\n");

  return 0;

}
 





int Make_Plain_text(long *Cyper_text, char *Plain_text, int key)

{

   int  i;

   for(i=0; i<message_length; i++)  

      Plain_text[i]= (char)mod(Cyper_text[i], key, n);  

   Plain_text[i] = '\0';  



   printf("receive message = ");

   for(i=0; i<message_length; i++)  

      printf(" %d ", Plain_text[i]);  

   printf("\n");  

   return 0;

}


int main() {
long send_msg[100];

   char recv_msg[100], buffer[100];

   int public_key, private_key;

   long e_pi;

   e_pi = Make_Random_Prime_Number();  

   public_key = Make_Public_Key (e_pi);  

   private_key = Make_Private_Key (public_key, e_pi);  
  ofstream key("key.txt");
  char key2[99];
  itoa(private_key,key2);
  key<<key2;
  key<<private_key;
  key.close();
   printf("e_pi=%d, n=%d, public_key=%d, private_key=%d\n\n", e_pi, n, public_key, private_key);
 
char id[20];
char undb[99999];
string db;
char sitename[20];
int a=0;
int p=0;
int n[999999];
while(int u=1){
a=0;
cout << "\n모드를 선택해주십시오. \n1:저장모드 (아이디, 비밀번호를 저장합니다.) \n2:보기모드 (저장한 아이디, 비밀번호를 확인합니다.)\n";
p++;
cin >> n[p];
if (n[p] == 1) {
cout << "사이트 주소, 아이디, 비밀번호를 입력해주십시오.";
cout<<"\n사이트 주소:";
cin>>sitename;
cout<<"\n아이디:";
cin>>id;

cout<<"\n비밀번호:";
cin>>buffer;

Make_Cyper_text(buffer, send_msg, public_key);
   
cout << " 비밀번호가 암호화되어 성공적으로 저장되었습니다.";
char buff[99];
char pw[9999];
for(int i=0;i<strlen(buffer);i++){
  itoa(send_msg[i],buff);
  strcat(pw,buff);
  if(i+1!=strlen(buffer)){
  strcat(pw," ");
}
}
strcat(sitename,"|");
strcat(undb,sitename);
strcat(id,"|");
strcat(undb,id);

strcat(undb,pw);
strcat(sitename,"\r\n");
ofstream db("db.txt");
    db<<undb;
   

db.close();
}
else if (n[p] ==2) {
cout << "사이트 주소를 입력해 주십시오."<<"\n사이트 주소:";
char entersitename[20];
cin>>entersitename;
ifstream db("db.txt");

string dater;
int i = 0;
char c;
while(db.get(c)){
  i++;  
  dater.append(1,c);
}
db.close();

int start=dater.find(entersitename,0);
int end=dater.find("\r\n",dater.find(entersitename,0));
int ret1=dater.find("|",dater.find(entersitename,0));
int ret2=dater.find("|",ret1+1);
cout<<"아이디:";
for(int i=ret1+1;i<ret2;i++){
cout<<dater[i];
}
cout<<"\n";
char key1[99];
ifstream key("key.txt");
key.getline(key1,sizeof(key));
string bpw;
long cpw[999];
int j=0;
int h=0;
while(j<end){
  if(dater[j]!=' '){
    bpw[h]=dater[j];
  }
  else if(dater[j]=' '){
    h++;
  }
  j++;
}
int k;
for(k=0;k<sizeof(bpw);k++){
  cpw[k]=atoll((const char *)bpw[k]);
}
char pw1[9999];
int ikey=atoia(key1[0]);
Make_Plain_text(cpw,pw1,ikey);
cout<<"비밀번호:";
cout<<pw1;
}
}
}
