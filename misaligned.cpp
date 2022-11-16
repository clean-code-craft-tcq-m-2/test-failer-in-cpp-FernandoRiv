#include <iostream>
#include <assert.h>

using namespace std;

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

string indexToColorPair(int majorColorIndex, int minorColorIndex){
    string separator = " | ";
    return to_string(majorColorIndex*5+minorColorIndex) + \
                            separator + majorColor[majorColorIndex] + \
                            separator + minorColor[minorColorIndex]; 
}

int printColorMap() {
    int i = 0, j = 0;
    for(; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cout << indexToColorPair(i, j) << endl; 
        }
    }
    return i * j;
}

int main() {
    printColorMap();
    
    int i = 0, j = 0;
    for(; i < 5; i++){
        for(; j < 5; j++){
            cout << "Assertion for major color: " << i << " minor color: " << j \
                 << " results in: " << endl;
            string result = indexToColorPair(i, j);
            assert(result.find(to_string((i*5+j)+1))!=string::npos);
            assert(result.find(majorColor[i])!=string::npos);
            assert(result.find(minorColor[j])!=string::npos);
            cout << "Success!" <<endl;
        }
    }
    
    cout << "All is well (maybe!)\n";
    return 0;
}