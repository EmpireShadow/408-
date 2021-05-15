//bubble
void bubblesort(int a[],int n){
    for(int i=n-1;i>0;i++){
        int flag=0;
        for(int j=0;j<i;j++)
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                flag=1;
            }
        if(flag==0) break;
    }
}

//insertion
void insertionsort(int a[],int n){
    for(int i=1;i<n;i++){
        int temp=a[i];
        for(int j=i;j>0&&temp<a[j-1];j--)
            a[j]=a[j-1];
        a[j]=temp;
    }
}

//shell
int Sedgewick[12] = {8929,3905,2161,929, 505, 209, 109, 41, 19, 5, 1, 0};
void shellsort(int a[],int n){
    int i,j;
    for(int i=0;Sedgewick[i]>=n;i++);
    for(int p=Sedgewick[i];p>0;p=Sedgewick[++i]){	//shell
        for(int start=p;start<n;start++){				//insertion
            int temp=a[start];
            for(j=start;j>=P&&a[j-p]>temp;j-=p)
                a[j]=a[j-p];
            a[j]=temp;
        }
    }
}

//select
void selectsort(int a[],int n){
    for(int i=0;i<n;i++){
        int temp=findmin(a,i,n-1);
        swap(a[i],a[temp]);
    }
}

int findmin(int a[],int l,int r){
    if(l==r) return r;
    int i,min=maxint;
    for(int j=l;i<=r;j++){
        if(min>a[j]){
            min=a[j];
            i=j;
        }
    }
    return i;
}

//heap
void Heapsort(int num){
	int i;
    //建立最大堆
    for(i=num/2-1;i>=0;i--)
        PercDown(i,num);
    for(i=num-1;i>0;i--){
        swap(0,i);
        PercDown(0,i);
    }
}
void PercDown(int p,int num){
    long int X=a[p];
    int parent,child;
    for(parent=p;(parent*2+1)<num;parent=child){
        child=parent*2+1;
        if(child!=num-1&&a[child]<a[child+1])
            child++;
        if(X>a[child]) break;
        else
            matrix[parent]=matrix[child];
    }
    matrix[parent]=X;
}

//merge0 递归
void msort(int l,int rightend){
    int mid;
    if(l<rightend){
        mid=(l+rightend)/2;
        msort(l,mid);
        msort(mid+1,rightend);
        merge(l,mid+1,rightend);
    }
}

void merge(int l,int r,int rightend){
    int leftend=r-1;
    int length=rightend-l+1;
    int temp=l;
    while(l<=leftend&&r<=rightend){
        if(a[l]<=a[r])	tempa[temp++]=a[l++];
        else	tempa[temp++]=a[r++];
    }
    while(l<=leftend) tempa[temp++]=a[l++];
    while(r<=rightend) tempa[temp++]=a[r++];
    for(int i=0;i<length;i++,rightend--)
        a[rightend]=tempa[rightend];
}
