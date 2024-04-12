#include<iostream>
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
string reverse(char a[]){
    char* start=a;
    char* end=&a[str_len(a)-1];
    while(start <= end){
        int c=*start;
        *start = *end;
        *end=c;
        start++;
        end--;
    }
return a;
}

//Xoa ki tu
void delete_char(char a[], char c){
    char *read=a;
    char *write=a;
    while(*read != '\0'){
        if(*read != c){
            *write = *read;
            write++;
        }
        read++;
    }
    *write='\0';
}

int main(){
char s[]="abcabc";
delete_char(s,'a');
cout<<s;

}
