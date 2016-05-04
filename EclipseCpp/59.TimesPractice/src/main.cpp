// Fig. 9.3: main.cpp
// Program to test class Time.
// NOTE: This file must be compiled with Time.cpp.
#include <iostream>
using std::cout;
using std::endl;

#include "Time.h" // include definition of class Time from Time.h
#include <ctime>
#include <iomanip>

int main()
{
   Time t; // instantiate object t of class Time

   // output Time object t's initial values
   cout << "The initial universal time is ";
   t.printUniversal(); // 00:00:00
   cout << "\nThe initial standard time is ";
   t.printStandard(); // 12:00:00 AM

   t.setTime( 13, 27, 6 ); // change time

   // output Time object t's new values
   cout << "\n\nUniversal time after setTime is ";
   t.printUniversal(); // 13:27:06
   cout << "\nStandard time after setTime is ";
   t.printStandard(); // 1:27:06 PM

   t.setTime( 99, 99, 99 ); // attempt invalid settings

   // output t's values after specifying invalid values
   cout << "\n\nAfter attempting invalid settings:"
      << "\nUniversal time: ";
   t.printUniversal(); // 00:00:00
   cout << "\nStandard time: ";
   t.printStandard(); // 12:00:00 AM
   cout << endl;

     time_t currentTime;
     struct tm *localTime;

     time( &currentTime );                   // Get the current time
     localTime = localtime( &currentTime );  // Convert the current time to the local time

     int Hour   = localTime->tm_hour;
     int Min    = localTime->tm_min;
     int Sec    = localTime->tm_sec;

     cout << "Current Time: " << Hour << ":"  << Min << ":" << Sec << endl;

     Time t2;

     t2.setTime( Hour, Min, Sec);

     cout << "\n\nUniversal time after setTime is ";
     t2.printUniversal();
     cout << "\nStandard time after setTime is ";
     t2.printStandard();




     return 0;
} // end main
