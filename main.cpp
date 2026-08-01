#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream file("input");
    if (!file.is_open()){
        cout << "Error" << endl;
    }
    char ch;
    char prev;
    int count = 1;
    file.get(prev);
    ofstream outFile("output");
    while(file.get(ch)){
       if (ch == prev){
           count++;
       }
       else{
           outFile << count << prev;
           prev = ch;
           count = 1;
       }
    }
    outFile << count << prev;
    outFile.close();
    file.close();
    ifstream checkfile("output");
    while (checkfile.get(ch)){
        cout << ch;
    }
    //
}
