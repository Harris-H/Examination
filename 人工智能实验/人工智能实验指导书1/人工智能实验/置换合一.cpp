/**
样例:
P(x) P(y)  成立
P(f(g(x))) P(f(y)) 存在多层嵌套
P(f(x)) P(x)  不成立
P(x,y...)  P(x,y...)  多个变量
定义结构体P{
   动态字符串数组
   vector<string>
}p[2]
1 输入: Input(){
   输入第一个P(...)
   字符串处理保存到结构体中: CreateP(字符串,结构体){
    遇到,要分离
    保存到P中
   }
   输入第二个P(...)
   CreateP()
}
结构体E{
   vector<string> Xk  保存Xk
   vector<string> Tk  保存Tk
}e
2 找mgu: FindMgu(){
    初始化: Init(){
       E设为空置换
       W即对应两个结构体
    }
    循环{
       找不一致集: FindDistinctSet(){
          找p[0]和p[1]第一个不同的字符串
          注意嵌套
       }
       判断xk是否出现在tk中，注意长度短的是xk,长度长的是tk
       类似于字符串匹配: KMP(){
       }
       如果在则退出无解
       否则{
          计算下一个置换集: GetNextE(){
             原来的置换集*{tk/xk}
             以置换集中某个元素为例
             a/b tk/xk
             先找xk是否出现在a中，如果是，用tk替换a中xk的位置
             否则不管
             如果出现b/b的情况，删除
             对所有元素操作之后，如果出现 a/xk 则tk/xk要删掉
          }
          计算下一个W: GetNextW(){
             原来的W集(即p[0],p[1])*{tk/xk}
             以W集中某个元素为例
             a tk/xk
             先找xk是否出现在a中，如果是，用tk代替a中xk的位置
             否则不管
          }
       }
    }
}
**/
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
struct P{
    vector<string> elem;
}p[2];
struct E{
    vector<string> Tk;
    vector<string> Xk;
}e;
void init();  //初始化
bool Input(); //输入
void CreateP(string& S,struct P& t); //对字符串处理
bool FindMgu();  //找mgu
bool CheckSame(); //判断W集是否合一
int FindDistinctSet(); //找不一致集
int KMP(string s1,string s2); //字符串匹配
void GetNextE(string x,string t); //得到下一个E集
void GetNextW(string x,string t); //得到下一个W集

void Init(){
    p[0].elem.clear();
    p[1].elem.clear();
    e.Tk.clear();
    e.Xk.clear();
}
bool Input(){
    string S;
    cin>>S;
    if(S=="#") return false;
    CreateP(S,p[0]);
    cin>>S;
    CreateP(S,p[1]);
    return true;
}
void CreateP(string& S,struct P& t){
    int len=S.size();
    S=S.substr(2,len-=3);
    int f=0,r;
    for(r=0;r<len;r++){
        if(S[r]==','){
            t.elem.push_back(S.substr(f,r-f));
            f=r+1;
        }
    }
    t.elem.push_back(S.substr(f,r-f));
}
int FindDistinctSet(){			//找到两个集合第一个不同的元素位置 
    int Size=p[0].elem.size();
    for(int i=0;i<Size;i++)
        if(p[0].elem[i]!=p[1].elem[i]) return i;
    return -1;
}
int KMP(string s1,string s2){			//在s2中到第一个匹配s1的起始位置 
    int len1=s1.size();
    int len2=s2.size();
    if(len1>len2) return -1;
    for(int i=0;i<=len2-len1;i++){
        bool ok=true;
        for(int j=0;j<len1;j++){
            if(s1[j]!=s2[i+j]){ ok=false; break; }
        }
        if(ok) return i;
    }
    return -1;
}
bool FindMgu(){
    cout<<"推导过程如下"<<endl;
    cout<<"==============================================="<<endl;
    while(true){
        int pos=FindDistinctSet();
        if(pos==-1) return true;
        string x=p[0].elem[pos],t=p[1].elem[pos];
        while(x[0]==t[0]){	//找到最里层的不匹配的位置 
            x=x.substr(2,x.size()-3); // 这里减3　就是减去左边的f(  和右边的 ) 
            t=t.substr(2,t.size()-3);
        }
        if((int)t.size()==1&&t[0]>='u'&&t[0]<='z'){
            string temp=t;
            t=x;
            x=temp;
        }
        if((int)x.size()!=1||x[0]<'u'||x[0]>'z') return false;
        int index=KMP(x,t);
        if(index!=-1) return false;
        else{
            GetNextE(x,t);
            GetNextW(x,t);
        }
        cout<<"==============================================="<<endl;
    }
    return true;
}
void Sub(string& t,string& x,string& a){
    int k=KMP(x,a);
    if(k==-1) return;
    string temp=a.substr(0,k);
    temp+=t;
    int sx=x.size();
    temp+=a.substr(k+sx);
    a=temp;
}
void GetNextE(string x,string t){
    int Size=e.Tk.size();
    for(int i=0;i<Size;i++){
        Sub(t,x,e.Tk[i]);
    }
    e.Tk.push_back(t);
    e.Xk.push_back(x);
    cout<<"e={";
    for(int i=0;i<Size+1;i++){
        cout<<e.Tk[i]<<"/"<<e.Xk[i];
        if(i!=Size) cout<<",";
    }

    cout<<"}"<<endl;
}
void GetNextW(string x,string t){
    int Size=p[0].elem.size();
    for(int i=0;i<Size;i++){
        Sub(t,x,p[0].elem[i]);
        Sub(t,x,p[1].elem[i]);
    }
    cout<<"W={";
    cout<<"P(";
    for(int i=0;i<Size;i++){
        cout<<p[0].elem[i];
        if(i!=Size-1) cout<<",";
    }
    cout<<") , ";
    cout<<"P(";
    for(int i=0;i<Size;i++){
        cout<<p[1].elem[i];
        if(i!=Size-1) cout<<",";
    }
    cout<<")";
    cout<<"}"<<endl;

}
int main(){
    while(true){
    Init();
    if(!Input()) break;
    bool ok=FindMgu();
    cout<<"最终结果为:"<<endl;
    if(ok){
        cout<<"mgu={";
        for(int i=0;i<e.Tk.size();i++){
            cout<<e.Tk[i]<<'/'<<e.Xk[i];
            if(i!=(int)e.Tk.size()-1) cout<<",";
        }
        cout<<"}"<<endl;
    }
    else{
        cout<<"No find mgu"<<endl;
    }
    }
    return 0;
}
/*
P(x,y,z)
Q(f(a),f(x),g(x))
P(a,v,f(g(y)))
P(z,f(a),f(u))
P(f(y),y,x)
P(x,f(a),f(b))
*/
