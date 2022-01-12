#include "mbed.h"
#include "max32625pico.h"
// main() runs in its own thread in the OS


/*
*   NOTE! As of January 2022, This example only works on MBED OS version 5.14.2.
*   The source of the issue could not be traced. This is ment to be a simple "Get Started" example of the library.
*   Also, AIN0(VDDIOH) and AIN2(1-Wire) pins will be active. It is highly recommanded to read MAX32625PICO documentation for a detailed explanation
*   of the process.
*/

//Some example pins
DigitalOut pin0_4(P0_4);
DigitalOut pin4_4(P4_4);  // we will change the voltage level to 3.3 for the OutPut of this pin.

// A class instance with following parameters are needed to make this work proparely.
MAX32625PICO pegasus(MAX32625PICO::IOH_DIP_OUT, MAX32625PICO::VIO_1V8, MAX32625PICO::VIO_1V8);

int main()
{
    pegasus.vddioh(P4_4, MAX32625PICO::VIO_IOH);

    pin4_4 = 1; // it should be now 3.3V
    pin0_4 = 1; // it should be Normal 1.8V
}


// If you wish to change the voltage level of all the pins (the ones that can be programmed), use the following code example
/**
*@code start
*
*MAX32625PICO pegasus(MAX32625PICO::IOH_DIP_OUT, MAX32625PICO::VIO_IOH, MAX32625PICO::VIO_1V8);
*
*int main()
*{
*    pegasus.init(MAX32625PICO::VIO_IOH, MAX32625PICO::VIO_1V8);
*
*    // All pins should now output and operate @3.3V logic level
*}
*@endcode
*/