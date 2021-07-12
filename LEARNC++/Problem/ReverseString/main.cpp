#include <bits/stdc++.h>
using namespace std;

string rString(string str)
{
    string c= "";
    int s = str.length();
    char ch[str.length()];
    strcpy(ch,str.c_str()); // copy string to char
    char *cStart = ch;
    char *cEnd  = ch + s-1;
    while(s > 0 ){
        c = c + *cEnd;
        *cEnd--;
        s--;
    }
    return c;
}

int main()
{
    int slno = 0;
    int t = 3;
    while(t>0){
        string str;
        cin>>str;
    // string str = "Hello World! Welcome to Coding world";
        str = rString(str);
        cout<<slno<<"."<<str<<endl;
        slno++;
        t--;
    }
    return 0;
}
