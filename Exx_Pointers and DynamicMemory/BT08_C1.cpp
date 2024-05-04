#include<bits/stdc++.h>
using namespace std;

//Lay do dai xau
int str_len(char* a){
    int count =0;
    while(*a != '\0'){
        count++;
        a++;
    }
return count;
}

//Dao xau
char* reverse(const char a[]){
    char* p = new char[strlen(a)];
    int n=strlen(a);
    int j=0;
    for(int i=n-1; i>=0; i--){
    p[j]=a[i];
        j++;
    }
    p[j]='\0';
    return p;
}

//Xoa ki tu
char* delete_char(const char a[], const char c){
    char* p = new char[strlen(a)];
    int j=0;
    while(*a != '\0'){
        if(*a != c){
            *(p+j)=*a;
            j++;
        }
    a++;
    }
    *(p+j)='\0';
return p;
}

int main(){
char s[]="abcabc";
cout<<delete_char(s,'b');

}
