#include <iostream>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    int retVal = 0;
    retVal = (celcius < 140)? 200 : 500;   
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return retVal;
}

int networkAlert(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    int retVal = 0;
    retVal = (celcius < 300)? 200 : 500;
    return retVal;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    #ifdef UTEST
    int returnCode = networkAlert(celcius);
    #else
    int returnCode = networkAlertStub(celcius);
    #endif
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    assert(alertFailureCount == 2);
    #define UTEST
    alertInCelcius(303.6);
    assert(alertFailureCount == 3);
    #undef UTEST
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
