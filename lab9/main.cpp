#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ReplaceMyString{
    public:
    ReplaceMyString(){}
    void replaceString(string a, string b){
        ifstream in("main.cpp");
        ofstream out("rmain.cpp");
        int i, j, alen = a.length(), blen = b.length();
        char c;
        
        do{
            in.get(c);
            if (in.eof()) break;
            if (c == a[0]){
                for (i=1; i<a.length(); i++){
                    in>>c;
                    if (c != a[i]) break;
                    if (i == a.length()-1){
                        for (j=0; j<b.length(); j++)
                            out << b[j];
                    }
                }
            }else 
                out<<c;
        }while(!in.eof());
        
        in.close();
        out.close();
    }
};

int main(){
    ReplaceMyString my;
    my.replaceString("IU", "IU is best");
    return 0;
}
