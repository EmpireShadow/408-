#define Maxsize 10

//顺序栈
typedef struct{
  int data[Maxsize];
  int top;
}sstack;

//顺序栈初始化
void Initsstack(sstack &s){
  s.top=-1;
}

//顺序栈pop
bool pop(sstack &s,int &x){
  if(s.top==-1) return false;
  x=s.data[s.top--];
  return true;
  
//顺序栈push
bool push(sstack &s,int x){
  if(s.top==Maxsize-1) return false;
  s.data[++s.top]=x;
  return true;
  
//顺序栈取栈顶
bool topsstack(sstack s,int &x){
  if(s.top==-1) return false;
  x=s.data[s.top];
  return true;
}
  
  
//链式栈
  typedef struct stackNode{
    int data;
    stackNode *next;
  }stackNode,*stacklist;
  
  //链式栈初始化
  void Initstack(stacklist &s){
    s=(stacklist)malloc(sizeof(stackNode));
    s->next=NULL;
  }
  
  //链式栈判断栈空
  bool stackempty(stacklist s){
    if(s->next==NULL) return true;
    else return false;
  }
  
  //链式栈入栈
  bool push(stacklist &s,int a){
    stackNode* p=(stacklist)malloc(sizeof(stackNode));
    if(p==NULL) return false;
    p->data=a;
    p->next=s->next;
    s->next=p;
    return true;
  }
  
 //链式栈出栈
  bool pop(stacklist &s,int &x){
    stacklist p=s->next;
    if(p==NULL) return false;
    x=p->data;
    s->next=p->next;
    free(p);
    return true;
  }
  
  //链式栈取栈顶
  bool top(stacklilst s,int &x){
    if(s->next==NULL) return false;
    x=s->next->data;
    return true;
  }
    
