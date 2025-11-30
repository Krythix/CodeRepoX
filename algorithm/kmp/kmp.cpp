#include <iostream>
#include <cstring>
using namespace std;

constexpr int N=100;
int nex[N];

void cal_next(const char p[]) {
    int i=0, j=-1, m=strlen(p);
    nex[0] = -1;
    while(i<m-1) {
        // ++i: nex[i]记录的是下标i之前的字符串的性质
        // ++j: 记录的是最长公共前后缀的长度
        if(j==-1 || p[i]==p[j]) nex[++i] = ++j;
        else j=nex[j];
    }
}

int kmp(const char s[], const char p[]) {
    int i=0, j=0, n=strlen(s), m=strlen(p);
    if(n<1 || m<1 || n<m) return -1;

    while(i<n && j<m) {
        // j==-1说明上一次p的第0个元素都没匹配到
        if(j==-1 || s[i]==p[j]) i++, j++;
        else j=nex[j];
    }
    return j==m?i-j:-1;
}

int main() {
    //--------x010012
    cal_next("aabbaac");
    int a = kmp("asdfaabbaabbaaccdad", "aabbaac");
    printf("%d\n", a);

    return 0;
}