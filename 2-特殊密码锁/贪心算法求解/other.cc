#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s,t,fin;
int tmp=0,ans=1e9,n;
/*字符串中'1'与'0'的转换值得学习*/
inline void flip(int i){
    s[i-1]=s[i-1]=='1'?'0':'1';
    s[i]=s[i]=='1'?'0':'1';
    if(i+1<n) s[i+1]=s[i+1]=='1'?'0':'1';
}
int main(int argc, const char * argv[]) {
    cin>>s>>fin;t=s;
    n=s.size();
    //第一种情况：按钮不匹配按后面的按钮
    for(int i=1;i<n;i++)
        if(s[i-1]!=fin[i-1]){
            flip(i); tmp++;
        }
    if(s[n-1]==fin[n-1]) ans=tmp;
    //第二种情况：如果前两个按钮不匹配，按第一个按钮，其他按钮不匹配还是按后一个按钮
    tmp=1;
    s=t;
    //原作者没有加这个判断，加上判断代码更清晰一些。
    if(s[0]!=fin[0]||s[1]!=fin[1]){
        s[0]=s[0]=='1'?'0':'1';
    s[1]=s[1]=='1'?'0':'1';
    for(int i=1;i<n;i++)
        if(s[i-1]!=fin[i-1]){
            flip(i); tmp++;
        }
    }

    //按完以后如果最后一个按钮相同，则输出两种情况中的按的次数最少的情况。
    if(s[n-1]==fin[n-1]) ans=min(ans,tmp);
    //如果不同，则
    if(ans==1e9) cout<<"impossible";
    else cout<<ans;
    return 0;
}