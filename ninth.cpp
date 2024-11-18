#include<iostream>
#include<cstring>
#include<cctype>
#include<cmath>
using namespace std;
#define MAX 100

//stack functions for characters for operators

int top=-1;
char charStack[MAX];

void pushChar(char c){
    if(top>=MAX-1){
        cout<<"Stack overflow"<<endl;
        return;
    }
    charStack[++top]=c;

}

char popChar(){
    if(top==-1){
        cout<<"Stack underflow"<<endl;
        return -1;
    }
    return charStack[top--];

}

char peekChar(){
    if(top==-1){
        return -1;
    }
    return charStack[top];
}

bool isEmptyChar(){
    return top==-1;
}

//Stack functions for integers for operands
int topInt=-1;
int intStack[MAX];

void pushInt(int value){
    if(topInt>=MAX-1){
        cout<<"Stack overflow"<<endl;
        return;
    }
    intStack[++topInt]=value;
}

int popInt(){
    if(topInt==-1){
        cout<<"Stack underflow"<<endl;
        return -1;
    }
    return intStack[topInt--];

}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char op){
    if(op=='+' || op=='-') return 1;
    if(op=='*' || op=='/') return 2;
    if(op=='^') return 3;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]){
    int k=0;
    int len=strlen(infix);
    for(int i=0;i<len; i++){
        char ch=infix[i];

        if(isdigit(ch)){
            postfix[k++]=ch;
        }else if(ch=='('){
            pushChar(ch);
        }else if(ch==')'){
            while(!isEmptyChar() && peekChar()!= '('){
                postfix[k++]=popChar();

            }
            popChar();
        }
        else if(isOperator(ch)){
            while(!isEmptyChar() && precedence(peekChar()) >= precedence(ch)){
                postfix[k++]=popChar();
            }
            pushChar(ch);
        }
    }
    while (!isEmptyChar())
    {
        postfix[k++]=popChar();
    }
    postfix[k]='\0';
}


int evaluatePostfix(char postfix[]){
    int dre=strlen(postfix);
    for(int i=0; i<dre; i++){
        char ch=postfix[i];
        if(isdigit(ch)){
            pushInt(ch-'0');
        }else{
            int val2=popInt();
            int val1=popInt();
            switch(ch){
                case '+':pushInt(val1+val2); break;
                case '-':pushInt(val1-val2); break;
                case '*':pushInt(val1*val2); break;
                case '/':pushInt(val1/val2); break;
                case '^':pushInt(pow(val1,val2)); break;
            }
        }
    }
    return popInt();
}

int main(){
    char infix[MAX];
    char postfix[MAX];

    cout<<"Enter the infix expression: ";
    cin>>infix;

    infixToPostfix(infix,postfix);
    cout<<"Postfix Expression: "<<postfix<<endl;

    int result=evaluatePostfix(postfix);
    cout<<"Result of postfix evaluation: "<<result<<endl;

    return 0;
}