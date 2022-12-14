#include <assert.h>
#include "misaligned.h"
#include "misaligned_test.h"

using namespace std;

extern string indexToColorPair(int, int);

void colorMap_test(){
    int i = 0, j = 0;
    for(; i < 5; i++){
        for(j = 0; j < 5; j++){
            cout << "Assertion for major color: " << i << " minor color: " << j \
                 << " results in: ";
            string result = indexToColorPair(i, j);
            assert(result.find(to_string((i*5+j)+1))!=string::npos);
            assert(result.find(majorColor[i])!=string::npos);
            assert(result.find(minorColor[j])!=string::npos);
            assert(int(result.size()) == FIXEDSTRINGSIZE);
            cout << "Success!" << endl;
        }
    }
}