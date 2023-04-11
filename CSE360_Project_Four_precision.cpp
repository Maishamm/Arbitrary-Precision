#include <bits/stdc++.h>
using namespace std;
#define Fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long int

bool Digit(char ch);
bool Operator(char ch);
int precision(char ch);
void Add();
void Substract();
void Multiply();
void Divide();
void Calculator(char ch);
void Fix_Operation(string number);
void postfix();
void infix();
void init();
stack<ll>Stack;
string str;

void Calculator(char ch)
{
    if (ch=='+')
        Add();
    else if (ch=='-')
        Substract();
    else if (ch=='*')
        Multiply();
    else if (ch=='/')
        Divide();
}

bool Digit(char ch)
{
    if(ch>='0' && ch<='9')
        return true;
    return false;
}

bool Operator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
        return true;
    return false;
}

int precision(char ch)
{
    if(ch=='*' || ch=='/')
        return 2;
    else if(ch=='+' || ch=='-')
        return 1;
    else
        return -1;
}

void Add()
{
    ll operand1,operand2,operation;
    operand2=Stack.top();
    Stack.pop();
    operand1=Stack.top();
    Stack.pop();
    operation=operand1+operand2;
    Stack.push(operation);
}

void Substract()
{
    ll operand1,operand2,operation;
    operand2=Stack.top();
    Stack.pop();
    operand1=Stack.top();
    Stack.pop();
    operation=operand1-operand2;
    Stack.push(operation);
}

void Multiply()
{
    ll operand1,operand2,operation;
    operand2=Stack.top();
    Stack.pop();
    operand1=Stack.top();
    Stack.pop();
    operation=operand1*operand2;
    Stack.push(operation);
}

void Divide()
{
    ll operand1,operand2,operation;
    operand2=Stack.top();
    Stack.pop();
    if (operand2)
    {
        operand1=Stack.top();
        Stack.pop();
        operation=operand1/operand2;
        Stack.push(operation);
    }
    else
    {
            init();
                cout << "\n\tWrong equation!!!\n\n\tInput Correctly Again!\n\n";
    }
}

void Fix_Operation(string number)
{
    int l= number.length();
    for(int i=0; i<l; i++)
    {
        if(number[i]==' ')
            continue;

        if(Operator(number[i]))
            Calculator(number[i]);

        else if(Digit(number[i]))
        {
            ll opp=0;
            while(i<l && Digit(number[i]))
            {
                opp=(opp*10)+(number[i]-'0');
                i++;
            }
            i--;
            Stack.push(opp);
        }
    }
             if(!Stack.empty())
             {
        cout << "\n\tResult: " << Stack.top() << endl << endl;
    }
}

void postfix()
{
    printf("\nEnter Postfix Expression: ");
    cin.ignore();
    getline(cin,str);
    Fix_Operation(str);
}

void infix()
{
    stack<char> st;
    string ns;

    printf("\nEnter Infix Expression: ");
    cin.ignore();
    getline(cin,str);

    st.push('N');
    int l=str.length();
    for(int i=0; i<l; i++)
    {
        if(Digit(str[i]))
            ns+=str[i];

        else if (str[i]==' ')
            ns+=' ';

        else if(str[i]=='(')
            st.push('(');

        else if(str[i]==')')
        {
            while(st.top()!='N' && st.top()!='(')
            {
                ns+=st.top();
                st.pop();
            }
            if(st.top()=='(')
                st.pop();
        }
        else
        {
            while(st.top() !='N' && precision(str[i]) <= precision( st.top() ) )
            {
                ns+=st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while(st.top()!='N')
    {
        ns+=st.top();
        st.pop();
    }
Fix_Operation(ns);
}

void init()
{
    while (!Stack.empty())
        Stack.pop();
}

int main()
{
    int choice;
    char ch;
       cout<< "\n \t\t\t\t Arbitrary Precision Four Function Calculator \n\n\t\t\t\t----------------------Menu----------------------\n\n\t[Please maintain a space while entering integers]";
    while(1)
    {
        init();
        cout<< "\n\n\t1. Infix Input\n"
               << "\t2. Postfix Input\n"
               << "\t3. Exit\n\n"
               << "\tEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
                case 1:  infix();
                             break;
                case 2:  postfix();
                             break;
                case 3:  exit(0);

                default:  cout << "\n\n\tWrong Choice.\n\n";
        }
    }
}

//  (44 + 2) / 2 * 3 - 4
// 44 2 + 2 / 3 * 4-
