#include <stdio.h>
#include <stdlib.h>
//顺序表
#define Maxsize 100
typedef struct{
  Elemtype data[Maxsize];
  int length;
}sqlist;

//动态顺序表
#define Initsize 20
typedef struct{
  Elemtype *data;
  int maxsize;
  int length;
}sqlist;

//动态顺序表创建
void Initlist(sqlist &l){
    l.data=(Elemtype*)malloc(Initsize*sizeof(Elemtype));
    l.maxsize=Initsize;
    l.length=0;
}

//增加动态数组的长度
void Increasesize(sqlist &l,int len){
    Elemtype *s=l.data;
    l.data=(Elemtype*）malloc((len+l.maxsize)*sizeof(Elemtype));
    for(int i=0;i<l.length;i++)
        l.data[i]=s[i];
    l.maxsize=l.maxsize+len;
    free(s);
}

//初始化顺序表
void Initlist(sqlist &l){
    l.length=0;
}

//按值查找
int research(sqlist l,int e){
    for(int i=0;i<l.length;i++){
        if(l.data[i]==e) return i+1;
    }
    else return -1;
}

//插入
bool InsertElem(sqlist &l,int i,int e){
    if(i<1||i>l.length+1) return false;
    if(l.length>=Maxsize) return false;
    for(int j=l.length;j>=i;j--)
        l.data[j]=l.data[j-1];
    l.data[i-1]=e;
    l.length++;
    return true;
}

//删除
bool Deletelist(sqlist &l,int i,int &e){
    if(i<1||i>l.length) return false;
    e=l.data[i-1];
    for(int j=i-1;j<l.length-1;j++)
        l.data[j]=l.data[j+1];
    l.length--;
    return true;
}
