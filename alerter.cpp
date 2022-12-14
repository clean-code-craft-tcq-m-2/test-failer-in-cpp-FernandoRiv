#include <iostream>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    // Return 200 for ok
    // Return 500 for not-ok
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    if(celcius > 200.0){
        return 500;
    }
    else{
        return 200;
    }
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}

int main() {
    alertInCelcius(303.6); // OK
    assert(alertFailureCount == 0);
    alertInCelcius(392);   // 200°C, OK
    assert(alertFailureCount == 0);
    alertInCelcius(393);   // slightly more than 200°C, NOK
    assert(alertFailureCount == 1);
    alertInCelcius(400.5); // NOK
    assert(alertFailureCount == 2);
    std::cout << "All is well!\n";
    return 0;
}
