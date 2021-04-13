//顺序循环队列
#define Maxsize 10
typedef struct{
  int data[Maxsize];
  int front,rear;
}queue;

//顺序队列初始化
void Initqueue(queue &q){
  q.front=q.rear=0;
}

//判断队空
bool queueempty(queue q){
  if(q.front==q.rear) return true;
  else return false;
}

//入队
bool enqueue(queue &q,int x){
  if((q.rear+1)%Maxsize==q.front) return false;
  q.data[q.rear]=x;
  q.rear=(q.rear+1)%Maxsize;
  return true;
}

//出队
bool dequeue(queue &q,int &x){
  if(queueempty(q)) return false;
  x=q.data[q.front];
  q.front=(q.front+1)%Maxsize;
  return true;
}


//队列的链式实现
typedef struct LNode{
  int data;
  struct LNode *next;
}LNode;

typedef struct{
  LNode *front,*rear;
}Linkqueue;
  
//初始化 
//有头结点
void Initqueue(Linkqueue &q){
  q.rear=q.front=(Linkqueue*)malloc(sizeofqueue);
  q.front->next=NULL;
}
//无头结点
void Initqueue(Linkqueue &q){
  q.rear=NULL;
  q.front=NULL;
}

//入队 在队尾
//有头结点
bool enqueue(Linkqueue &q,int x){
  LNode* s=(LNode*)malloc(sizeof(LNode));
  if(s==NULL) return false;
  s->data=x;
  s->next=NULL;
  q.rear->next=s;
  q.rear=s;
  return true;
}
//无头结点
void enqueue(Linkqueue &q,int x){
  LNode* s=(LNode*)malloc(sizeof(LNode));
  s->data=x;
  s->next=NULL;
  if(q.front==NULL){
    q.front=s;
    q.rear=s;
  }
  else{
    q.rear->next=s;
    q.rear=s;
  }
}


//出队 在队头
//有头结点
bool dequeue(Linkqueue &q,int &x){
  if(q.rear==q.front) return false;
  LNode* s=q.front->next;
  x=s->data;
  q.front->next=s->next;
  if(q.rear==p) q.rear=q.front;
  free(s);
  return true;
}
//无头结点
bool dequeue(Linkqueue &q,int &x){
  if(q.front==NULL) return false;
  LNode* s=q.front;
  q.front=s->next;
  if(q.rear==s){
    q.rear=NULL;
    q.front=NULL;
  }
  free(s);
  return true;
  
