//括号匹配
#define Maxsize 10
typedef struct{
  char data[Maxsize];
  int top;
}sstack;

bool bracketcheck(char str[],int length){
  sstack s;
  Initstack(s);
  for(int i=0;i<length;i++){
    if(str[i]=='('||str[i]=='['||str[i]=='{')
      push(s,str[i]);
    else{
      if(stackempty(s)) return false;
      char q;
      pop(s,q);
      if(str[i]==')'&&q!='(') return false;
      if(str[i]==']'&&q!='[') return false;
      if(str[i]=='}'&&q!='{') return false;
    }
  return stackempty(s);
}