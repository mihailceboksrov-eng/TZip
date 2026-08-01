#include <iostream>
#include <fstream>
using namespace std;

void compressed(string inputPath, string outPath) {
    ifstream inFile(inputPath);
    ofstream outFile(outPath);

    if (!inFile.is_open()){
    	cout << "Error! Failed open file." << endl;
    }
    char ch;
    char prev;
    int count = 1;
    inFile.get(prev);
    while(inFile.get(ch)){
    	if (ch == prev){
	    count++;
	}
	else {
	    outFile << prev << count;
	    prev = ch;
	    count = 1;
	}
    }
    outFile << prev << count;
    outFile.close();
    inFile.close();
}

void decompressed(string inputPath, string outputPath){
    ifstream inFile(inputPath);
    ofstream outFile(outputPath);
    if (!inFile.is_open()) {
    	cout << "Error! Failed decompressed" << endl;
    }
    inFile >> noskipws;
    int count;
    char ch;

    while(inFile >> ch >> count) {
    	for(int i = 0; i < count; i++){
            outFile << ch;
	}

    }
    inFile.close();
    outFile.close();
}

int main(){
    compressed("input", "output"); 
    decompressed("output", "decompressed");
}
