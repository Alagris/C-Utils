#include "timer.h"
#include <iostream>
#include <chrono>
namespace util_lib{
    using namespace std::chrono;
    
    high_resolution_clock::time_point startTime;
    
    void start(){
        startTime = high_resolution_clock::now();
    }
    double endTimeNano(){
        
        return duration_cast<nanoseconds>( high_resolution_clock::now() - startTime ).count();
    }
    double endTimeMilli(){
        
        return duration_cast<milliseconds>( high_resolution_clock::now() - startTime ).count();
    }
    double endTimeMicro(){
        
        return duration_cast<microseconds>( high_resolution_clock::now() - startTime ).count();
    }
}
