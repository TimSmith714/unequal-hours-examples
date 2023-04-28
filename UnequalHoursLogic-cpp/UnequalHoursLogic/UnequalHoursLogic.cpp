// UnequalHoursLogic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime> 
#include <chrono>
#include <cstdint>


int main()
{

    using namespace std::chrono;
    using namespace std;

    std::cout << "Hello World!\n";

    // 12 hours * 60 min * 60 seconds
    const int unequalDayLength = 43200;
    
    // Create timepoint for 6 am Sunrise
    std::tm tm = {  /* .tm_sec = */ 0,
        /* .tm_min = */ 0,
        /* .tm_hour = */ 6,
        /* .tm_mday = */ 26,
        /* .tm_mon = */ 4,
        /* .tm_year = 2023-1900 */ 123
    };
    tm.tm_isdst = -1; // Use DST value from local time zone
    auto unequalSunRisePoint = std::chrono::system_clock::from_time_t(std::mktime(&tm));

    auto unequalSunRiseSeconds = std::chrono::time_point_cast<std::chrono::seconds>(unequalSunRisePoint);
    

    std::cout << "Unequal Sunrise Point: ";
    //std::cout << unequalSunRisePoint;
    
    // Remember to update these when debugging
    // https://api.openweathermap.org/data/2.5/weather
    int sunrise = 1682484157;
    int sunset = 1682536428;


    // Get the current time
    
    std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();


    // Create SunRisePoint
    std::chrono::system_clock::time_point sunrisePoint{ std::chrono::seconds{sunrise} };

    // Try getting the hour and minute
    auto sunriseTime = system_clock::to_time_t(sunrisePoint);
   
    
    /*auto local_tm = *localtime(&sunriseTime);
    std::cout << local_tm.tm_hour;
    std::cout << ":";
    std::cout << local_tm.tm_min; */



    
    // Create SunRisePoint
    std::chrono::system_clock::time_point sunsetPoint{ std::chrono::seconds{sunset} };

    // Work out how much day has happened
    auto dayElapsed = std::chrono::duration_cast<std::chrono::seconds>(currentTime - sunrisePoint);

    // Get day length
    auto dayLength = std::chrono::duration_cast<std::chrono::seconds>(sunsetPoint - sunrisePoint);

    float dayElapsedPc = static_cast<float>(dayElapsed.count()) / static_cast<float>(dayLength.count());
    
    std::cout << "Day length (seconds): ";
    std::cout << dayLength.count();
    std::cout << "\n";
    std::cout << "day elapsed (seconds): ";
    std::cout << dayElapsed.count(); 
    std::cout << "\n";
    std::cout << "day elapsed (%): ";
    std::cout << dayElapsedPc;
    
    /* Testing results
    On 2023-04-26
        Day length (seconds): 52271
        day elapsed (seconds): 13052
        day elapsed (%): 0.249699

    
    */


    
    // Then apply this to the standard Unequal day
    // unequalDayLength is 12 hours in seconds
    //int unequalDayLength = 12 * 60 * 60;
    // Number of seconds elapsed so far
    ///float unequalDayElapsed = unequalDayLength * dayElapsed;
    // Now give the time from 6am (half a day lenfth) and  adding those seconds
    //int currentUnequalTime = (unequalDayLength / 2) + unequalDayElapsed;



}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
