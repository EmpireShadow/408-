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
