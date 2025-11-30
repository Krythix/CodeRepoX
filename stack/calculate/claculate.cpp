#include <iostream>
#include <stack>
#include <map>
#include <string>
using namespace std;

map<char, int> priority={{'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}};

int cal(int a, char b, int c) {
    switch(b) {
        case '*': return a*c;
        case '/': return a / c;
        case '+': return a+c;
        case '-': return a-c;
        default:  throw "e";
    }
}

string Infix2Postfix(const char str[]) {
    stack<char> signs;
    string result;
    for(int i=0; str[i]!='\0'; ) {
        if(isblank(str[i])) {
            i++;
            continue;
        }
        if(isdigit(str[i])) {
            while(str[i] != '\0' && isdigit(str[i])) {
                result += str[i++];
            }
            result += ' ';
        } else {
            char sign = str[i++];
            if(sign == '(') {
                signs.push(sign);
            } else if(sign == ')') {
                while(signs.top()!='(') {
                    char b = signs.top();signs.pop();
                    result += b;
                    result += ' ';
                }
                signs.pop();
            } else {
                while(!signs.empty() && priority[signs.top()] >= priority[sign]) {
                    result += signs.top(); signs.pop();
                    result += ' ';
                }
                signs.push(sign);
            }
        }
    }
    while(!signs.empty()) {
        result += signs.top(); signs.pop();
        result += ' ';
    }
    return result;
}

int calPostfix(const char str[]) {
    stack<int> nums;
    for(int i=0; str[i] != '\0';) {
        if(isblank(str[i])) {
            i++;
            continue;
        }
        if(isdigit(str[i])) {
            int num=0;
            while(str[i] != '\0' && isdigit(str[i])) {
                num = num*10 + str[i] - '0';
                i++;
            }
            nums.push(num);
        } else {
            char sign = str[i++];
            int a = nums.top(); nums.pop();
            int b = nums.top(); nums.pop();
            int num = cal(b, sign, a);
            nums.push(num);
        }
    }
    return nums.top();
}

int main() {
    string infix;
    cin >> infix;
    string postfix = Infix2Postfix(infix.c_str());
    cout << infix << " = " << postfix << " = " << calPostfix(postfix.c_str()) << endl;
    return 0;
}