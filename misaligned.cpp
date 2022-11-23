#include "misaligned.h"
#include "misaligned_test.h"

#define UTEST

using namespace std;

string indexToColorPair(int majorColorIndex, int minorColorIndex){
    string indexSeparator = separator;
    int indexInt = majorColorIndex*5+minorColorIndex+1;
    if(indexInt <= MAXSINGLENUMBER)
        indexSeparator = " " + indexSeparator;
    return to_string(indexInt) + \
                     indexSeparator + majorColor[majorColorIndex] + \
                     string(separator) + minorColor[minorColorIndex]; 
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

    #ifdef UTEST
    colorMap_test();
    #endif

    return 0;
}