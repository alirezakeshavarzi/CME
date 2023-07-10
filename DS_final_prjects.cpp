
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int n=6;
typedef struct stack {
    int top = -1;
    //string* s = new string[n / 2];
    string s[4];
};



int stack_empty(stack& st) {
    return (st.top == -1);
}

int stack_full(stack& st) {
    return (st.top == n / 2);
}

void push(stack& st, string val) {
    if (stack_full(st))
        cout << "Stack is full!" << endl;
    else
        st.s[++st.top] = val;
}

string pop(stack& st) {

    if (stack_empty(st))
        return "Stack is empty.";
    else
        return st.s[st.top--];
}


bool getnum(string I_want_to_push, string value_in_stack) {


    if (I_want_to_push[0] > value_in_stack[0]) {
        return true;
    }
    else {
        return false;
    }
}


void push_in_stack(stack &st, string & ans, string mark) {

   

    while (1) {

        if (st.top >= 0)
        {
           
            
            if ( getnum(mark, st.s[st.top]) ) {
                push(st, mark);
                break;
            }
            else {
                
                string temp = pop(st);
                ans += temp[1];
                
            }
        }
        else if (st.top == -1) {
            
            
            push(st, mark);
            break;
        }
    }
}

void Infix_to_postfix(string &ans, stack& st ,string str) { // 1 function
    
    for (int i = 0; i < n; i++) {
        

        if ( isdigit(str[i]) ) { 
            ans += str[i];
        }
        else {

            switch (str[i]) {

                case'(':

                    push(st, "(");

                    break;

                case ')':

                    while ( st.s[st.top] != "(" ) {
                        string temp3 = pop(st);
                        ans += temp3[1];
                    }
                    pop(st); // for pop '(' of stack.

                    break;
                case '-':
                    
                    push_in_stack(st, ans, "2-");
                    break;
                    
                case '+':
                    
                    push_in_stack(st, ans, "2+");
                    break;

                case '/':

                    push_in_stack(st, ans, "4/");
                    break;

                case '*':

                    push_in_stack(st, ans, "4*");
                    break;

                case '^':

                    push_in_stack(st, ans, "5^");

                    break;
            }

        }
    }


    while (!stack_empty(st)) {

        string temp2 = pop(st);
        ans += temp2[1];
    }

}

////////////////////////////////////////////// infix to prefix

string reverse(string s) {
    
    string temp = s;
    
    n = size(s);

    s = "";
    for (int i = n - 1; i >= 0; i--) {
        s += temp[i];
    }

    return s;

}

void Infix_to_prefix(string &ans, stack &st, string str) {

    n = size(str);

    for (int i = n-1; i >= 0; i-- ) {

        if (isdigit(str[i])) {
            ans += str[i];
        }
        else {

            switch (str[i]) {

            case'(':

                push(st, "(");

                break;

            case ')':

                while (st.s[st.top] != "(") {
                    string temp3 = pop(st);
                    ans += temp3[1];
                }
                pop(st); // for pop '(' of stack.

                break;
            case '-':

                push_in_stack(st, ans, "2-");
                break;

            case '+':

                push_in_stack(st, ans, "2+");
                break;

            case '/':

                push_in_stack(st, ans, "4/");
                break;

            case '*':

                push_in_stack(st, ans, "4*");
                break;

            case '^':

                push_in_stack(st, ans, "5^");

                break;
            }

        }
    }


    while (!stack_empty(st)) {

        string temp2 = pop(st);
        ans += temp2[1];
    }

    reverse(ans);

}

//////////////////////////////////////////////////// PREFIX TO INFIX

void accession_infix(stack &st, string val ){
    string temp2;
    temp2 = pop(st);
    temp2 += val;
    temp2 += pop(st);

    push(st, temp2);

}

void prefix_to_infix(string& ans, stack& st, string str) {

    n = size(str);

    for (int i = n - 1; i >= 0; i--) {

        if (isdigit(str[i])) {
            
            string temp = string(1, str[i]);

            push(st, temp);
        }
        else {
            switch (str[i]) {

                case '-':
                    accession_infix(st, "-");
                   
                    break;

                case '+':

                    accession_infix(st, "+");
                    break;

                case '/':

                    accession_infix(st, "/");
                    break;

                case '*':

                    accession_infix(st, "*");
                    break;

                case '^':

                    accession_infix(st, "^");

                    break;
            }
        }
    }

    ans = st.s[0];

}


void accession_postfix(stack& st, string val) {
    string temp2;
    temp2 = pop(st);
    temp2 += pop(st);
    temp2 += val;

    push(st, temp2);

}

void prefix_to_postfix(string& ans, stack& st, string str) {

    n = size(str);

    for (int i = n - 1; i >= 0; i--) {

        if (isdigit(str[i])) {

            string temp = string(1, str[i]);

            push(st, temp);
        }
        else {
            switch (str[i]) {

            case '-':
                accession_postfix(st, "-");

                break;

            case '+':

                accession_postfix(st, "+");
                break;

            case '/':

                accession_postfix(st, "/");
                break;

            case '*':

                accession_postfix(st, "*");
                break;

            case '^':

                accession_postfix(st, "^");

                break;
            }
        }
    }

    ans = st.s[0];

    
}


void postfix_to_infix(string& ans, stack& st, string str) {
    n = size(str);

    for (int i =0; i < n; i++) {

        if (isdigit(str[i])) {

            string temp = string(1, str[i]);

            push(st, temp);
        }
        else {
            switch (str[i]) {

            case '-':
                accession_infix(st, "-");

                break;

            case '+':

                accession_infix(st, "+");
                break;

            case '/':

                accession_infix(st, "/");
                break;

            case '*':

                accession_infix(st, "*");
                break;

            case '^':

                accession_infix(st, "^");

                break;
            }
        }
    }

    ans = reverse(st.s[0]);
    

}


void accession_prefix(stack& st, string val) {
    string temp2, temp3;
    temp3 = pop(st);

    temp2 = val;
    temp2 += pop(st);
    temp2 += temp3;

    push(st, temp2);

}

void postfix_to_prefix(string& ans, stack& st, string str) {

    n = size(str);

    for (int i = 0; i < n; i++) {

        if (isdigit(str[i])) {

            string temp = string(1, str[i]);

            push(st, temp);
        }
        else {
            switch (str[i]) {

            case '-':
                accession_prefix(st, "-");

                break;

            case '+':

                accession_prefix(st, "+");
                break;

            case '/':

                accession_prefix(st, "/");
                break;

            case '*':

                accession_prefix(st, "*");
                break;

            case '^':

                accession_prefix(st, "^");

                break;
            }
        }
    }

    ans = st.s[0];

}



void postfix_eval(string& ans, stack& st, string str) {

    string c;
    int a=0, b=0;
    n = size(str);

    for (int i = 0; i < n; i++) {
        
        if (isdigit(str[i])) {

            string temp = string(1, str[i]);

            push(st, temp);
        }
        else {
            switch (str[i]) {

            case '-':
            {
                a = stoi(pop(st));
                b = stoi(pop(st));

                c = to_string(a - b);

                push(st, c);

                
            }
            break;

            case '+':
            {


                a = stoi(pop(st));
                b = stoi(pop(st));
               
                c = to_string(a + b);

                push(st, c);
            }
            break;

            case '/':
            {



                a = stoi(pop(st));
                b = stoi(pop(st));

                if (b == 0) {
                    cout << "Integer division by zero." << endl << endl;
                    break;
                }

                c = to_string(a / b);

                push(st, c);
            }
            break;

            case '*':
            {


                a = stoi(pop(st));
                b = stoi(pop(st));

                c = to_string(a * b);

                push(st, c);
            }
            break;

            case '^':
            {


                a = stoi(pop(st));
                b = stoi(pop(st));

                c = to_string(pow(a,b));

                push(st, c);
            }
            break;
            }

        }
    }

    ans = st.s[0];

}

bool is_operator(char c) {

    switch(c){

    case '+':
        return true;
        break;
    case '-':
        return true;
        break;
    case '/':
        return true;
        break;
    case '*':
        return true;
        break;
    case '^':
        return true;
        break;
        
    }

    return false;
}



string Expression_validation(string str) {

    n = size(str);


    if (is_operator(str[0])) {
        return "prefix";
    }
    else if (is_operator(str[n - 1])) {
        return "postfix";
    }
    else {
        /*bool t = false;
        for (int i = 1; i < n - 1; i+=1) {

            if (is_operator(str[i]) && isdigit(str[i - 1]) && isdigit(str[i + 1])) {
                t = true;
            }
            else {
                t = false;
                break;
            }

        }

        if (t) {
            return "infix";
        }
        else {
            return "nothing";
        }*/

        bool c = false;

        if (isdigit(str[0]) && isdigit(str[n - 1])) {
            for (int i = 1; i < n - 2; i++) {
                if (is_operator(str[i])) {

                    if ( is_operator(str[i - 1]) || is_operator(str[i + 1]) ) {
                        c = false;
                        break;
                    }
                    else {
                        c = true;
                        break;
                    }
                   
                }


            }
        }

        if (c) {
            return "infix";
        }
        else {
            return "nothing!...";
        }
    }

    

    

}

void prefix_eval(string& ans, stack& st, string str) {

    string c;
    int a = 0, b = 0;
    n = size(str);

    for (int i = n-1; i >= 0; i--) {

        if (isdigit(str[i])) {

            string temp = string(1, str[i]);

            push(st, temp);
        }
        else {
            switch (str[i]) {

            case '-':
            {
                a = stoi(pop(st));
                b = stoi(pop(st));

                c = to_string(a - b);

                push(st, c);


            }
            break;

            case '+':
            {


                a = stoi(pop(st));
                b = stoi(pop(st));

                c = to_string(a + b);

                push(st, c);
            }
            break;

            case '/':
            {



                a = stoi(pop(st));
                b = stoi(pop(st));

                if (b == 0) {
                    cout << "Integer division by zero."<<endl<<endl;
                    break;
                }
                c = to_string(a / b);

                push(st, c);
            }
            break;

            case '*':
            {


                a = stoi(pop(st));
                b = stoi(pop(st));

                c = to_string(a * b);

                push(st, c);
            }
            break;

            case '^':
            {


                a = stoi(pop(st));
                b = stoi(pop(st));

                c = to_string(pow(a, b));

                push(st, c);
            }
            break;
            }

        }
    }

    ans = st.s[0];

}

int main()
{
    string s = "11+22*33";

    n = size(s);

    string ans;
    stack st;


   
    //prefix_eval(ans, st, s);
    ans = Expression_validation(s);
   
   
    cout <<"s : "<< s << endl;
    cout << "eval : " << ans << endl;


    return 0;
}
