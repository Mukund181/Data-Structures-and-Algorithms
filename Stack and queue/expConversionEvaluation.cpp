#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

int prec(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else {
        return -1;
    }
}
void infixtopostfix(char s[]){
    char postfix[1000];
    char stack[1000];
    int stacktop=-1;
    int postindex =0;
    int len = strlen(s);
    for(int i=0;i<len;i++){
        char c = s[i];
        if(c=='('){
            stacktop++;
            stack[stacktop]=c;
        }
        else if((c>='a' && c<='z') ||(c>='A' && c<='Z') || (c>='0' && c<='9')){
            postfix[postindex]=c;
            postindex++;
        }
        else if(c==')'){
            while(stacktop>=0 && stack[stacktop]!='('){
                postfix[postindex]=stack[stacktop];
                postindex++;
                stacktop--;
            }
            stacktop--;
        }
        else {
            while(stacktop>=0 && (prec(s[i])<=prec(stack[stacktop]))){
                postfix[postindex]=stack[stacktop];
                postindex++;
                stacktop--;
            }
            stacktop++;
            stack[stacktop]=c;
        }
    }
    while(stacktop>=0){
        postfix[postindex]=stack[stacktop];
        postindex++;
        stacktop--;
    }
    postfix[postindex]='\0';
    cout<<"\nPostfix = "<<postfix;
}
void reverse_string(char s[]){
    int len = strlen(s);
    for(int i=0;i<len/2;i++){
        swap(s[i],s[len-i-1]);
    }
}
void infixtoprefix(char s[]){
    reverse_string(s);
    char postfix[1000];
    char stack[1000];
    int stacktop=-1;
    int postindex =0;
    int len = strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]=='('){
            s[i]=')';
        }
        else if(s[i]==')'){
            s[i]='(';
        }
    }
    for(int i=0;i<len;i++){
        char c = s[i];
        if(c=='('){
            stacktop++;
            stack[stacktop]=c;
        }
        else if((c>='a' && c<='z') ||(c>='A' && c<='Z') || (c>='0' && c<='9')){
            postfix[postindex]=c;
            postindex++;
        }
        else if(c==')'){
            while(stacktop>=0 && stack[stacktop]!='('){
                postfix[postindex]=stack[stacktop];
                postindex++;
                stacktop--;
            }
            stacktop--;
        }
        else {
            while(stacktop>=0 && (prec(s[i])<=prec(stack[stacktop]))){
                postfix[postindex]=stack[stacktop];
                postindex++;
                stacktop--;
            }
            stacktop++;
            stack[stacktop]=c;
        }
    }
    while(stacktop>=0){
        postfix[postindex]=stack[stacktop];
        postindex++;
        stacktop--;
    }
    postfix[postindex]='\0';
    reverse_string(postfix);
    cout<<"\nPrefix : "<<postfix;

}
int stack[100];
int top=-1;
void push(int val){
    stack[++top]=val;
}
int pop(){
    if(top>-1) return stack[top--];
}
int isoperand(char c){
    return isdigit(c);
}
int postfix_evaluation(char s[]){
    int n = strlen(s);
    for(int i=0;i<n;i++){
        char c = s[i];
        if(isoperand(c)){
            push(c-'0');
        }
        else {
            int a = stack[top];
            pop();
            int b= stack[top];
            pop();
            switch(c){
                case '^' : push(a^b); break;
                case '*' : push(a*b); break;
                case '+' : push(a+b); break;
                case '-' : push(a-b); break;
                case '/' : push(a/b); break;
            }
        }
    }
    return stack[top];
}
int prefixevaluation(char s[]){
        int n = strlen(s);
      for(int i=n-1;i>=0;i--){
        char c = s[i];
        if(isoperand(c)){
            push(c-'0');
        }
        else {
            int a = stack[top];
            pop();
            int b= stack[top];
            pop();
            switch(c){
                case '^' : push(a^b); break;
                case '*' : push(a*b); break;
                case '+' : push(a+b); break;
                case '-' : push(a-b); break;
                case '/' : push(a/b); break;
            }
        }
    }
    return stack[top];
}
int main(){
    char s[]="(5+3)*2"; // infix exp 
    infixtopostfix(s);
    infixtoprefix(s);
    char p[]="53+2*";
    int res = postfix_evaluation(p);
    cout<<"\nPostfix evaluation : "<<res;
    char q[]="*+532";
    int res2 = prefixevaluation(q);
    cout<<"\nPrefix evaluation : "<<res2;
}
