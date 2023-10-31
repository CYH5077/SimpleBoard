#pragma once

#include <string>

// CPU 사용량에 대한 정보를 저장할 class

class CPUUsageInfo {
public:
    explicit CPUUsageInfo();
    virtual ~CPUUsageInfo();

public: // getter setter
    void setUsage(int usage);
    void setUser(int user);
    void setNice(int nice);
    void setSystem(int system);
    void setIdle(int idle);

    int getUsage();
    int getUser();
    int getNice();
    int getSystem();
    int getIdle();

private:
    int cpuUsage;
    
    int user;
    int nice;
    int system;
    int idle;
};