/**
����:
P(x) P(y)  ����
P(f(g(x))) P(f(y)) ���ڶ��Ƕ��
P(f(x)) P(x)  ������
P(x,y...)  P(x,y...)  �������
����ṹ��P{
   ��̬�ַ�������
   vector<string>
}p[2]
1 ����: Input(){
   �����һ��P(...)
   �ַ��������浽�ṹ����: CreateP(�ַ���,�ṹ��){
    ����,Ҫ����
    ���浽P��
   }
   ����ڶ���P(...)
   CreateP()
}
�ṹ��E{
   vector<string> Xk  ����Xk
   vector<string> Tk  ����Tk
}e
2 ��mgu: FindMgu(){
    ��ʼ��: Init(){
       E��Ϊ���û�
       W����Ӧ�����ṹ��
    }
    ѭ��{
       �Ҳ�һ�¼�: FindDistinctSet(){
          ��p[0]��p[1]��һ����ͬ���ַ���
          ע��Ƕ��
       }
       �ж�xk�Ƿ������tk�У�ע�ⳤ�ȶ̵���xk,���ȳ�����tk
       �������ַ���ƥ��: KMP(){
       }
       ��������˳��޽�
       ����{
          ������һ���û���: GetNextE(){
             ԭ�����û���*{tk/xk}
             ���û�����ĳ��Ԫ��Ϊ��
             a/b tk/xk
             ����xk�Ƿ������a�У�����ǣ���tk�滻a��xk��λ��
             ���򲻹�
             �������b/b�������ɾ��
             ������Ԫ�ز���֮��������� a/xk ��tk/xkҪɾ��
          }
          ������һ��W: GetNextW(){
             ԭ����W��(��p[0],p[1])*{tk/xk}
             ��W����ĳ��Ԫ��Ϊ��
             a tk/xk
             ����xk�Ƿ������a�У�����ǣ���tk����a��xk��λ��
             ���򲻹�
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
void init();  //��ʼ��
bool Input(); //����
void CreateP(string& S,struct P& t); //���ַ�������
bool FindMgu();  //��mgu
bool CheckSame(); //�ж�W���Ƿ��һ
int FindDistinctSet(); //�Ҳ�һ�¼�
int KMP(string s1,string s2); //�ַ���ƥ��
void GetNextE(string x,string t); //�õ���һ��E��
void GetNextW(string x,string t); //�õ���һ��W��

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
int FindDistinctSet(){			//�ҵ��������ϵ�һ����ͬ��Ԫ��λ�� 
    int Size=p[0].elem.size();
    for(int i=0;i<Size;i++)
        if(p[0].elem[i]!=p[1].elem[i]) return i;
    return -1;
}
int KMP(string s1,string s2){			//��s2�е���һ��ƥ��s1����ʼλ�� 
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
    cout<<"�Ƶ���������"<<endl;
    cout<<"==============================================="<<endl;
    while(true){
        int pos=FindDistinctSet();
        if(pos==-1) return true;
        string x=p[0].elem[pos],t=p[1].elem[pos];
        while(x[0]==t[0]){	//�ҵ������Ĳ�ƥ���λ�� 
            x=x.substr(2,x.size()-3); // �����3�����Ǽ�ȥ��ߵ�f(  ���ұߵ� ) 
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
    cout<<"���ս��Ϊ:"<<endl;
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
