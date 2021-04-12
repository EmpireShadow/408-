//单链表
typedef struct LNode{
    int data;
    LNode* next;
}Lnode,*Linklist;

//创建链表
//头插法
Linklist InsertHead(Linklist &L){
    L=(Linklist)malloc(sizeof(LNode));
    L->next=NULL;
    int x;
    LNode *s;
    cin>>x;
    while(x!=9999){
        s=(Linklist)malloc(sizeof(LNode));
        s->data=x;
        s->next =L->next;
        L->next=s;
        cin>>x;
    }
    return L;
}
//尾插法
Linklist InsertTail(Linklist &L){
    int x;
    Linklist s,p;
    L=(Linklist)malloc(sizeof(LNode));
    L->next=NULL;
    cin>>x;
    p=L;
    while(x!=9999){
        s=(Linklist)malloc(sizeof(LNode));
        s->data=x;
        p->next=s;
        p=s;
        cin>>x;
    }
    p->next=NULL;
    return L;
}


//查找
//按值查找
Lnode* Research_value(Linklist L,int e){
    LNode *s=L->next;
    while(s&&s->data!=e) s=s->next;
    return s;
}

//按位查找
Lnode* Research_position(Linklist L,int n){
    if(n==0) return L;
    if(n<1) return NULL;
    LNode* s=L->next;
    int i=1;
    while(s&&i<n){
        s=s->next;
        i++;
    }
    return s;
}

//删除节点
bool Delete(Linklist &L,int n){
    LNode* s=Research_position(L,n-1);
    if(s==NULL) return false;
    if(s->next==NULL) return false;
    LNode* p=s->next;
    s->next=p->next;
    free(p);
    return true;
}

//插入节点
bool Insert(Linklist &L,int n,int e){
    LNode* s=Research_position(L,n-1);
    if(s==NULL) return false;
    LNode* p=(Linklist)malloc(sizeof(LNode));
    p->data=e;
    p->next=s->next;
    s->next=p;
    return true;
}
