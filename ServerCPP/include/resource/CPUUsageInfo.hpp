#pragma once

#include <string>

// CPU 사용량에 대한 정보를 저장할 class

class CPUUsageInfo {
public:
    explicit CPUUsageInfo();
    virtual ~CPUUsageInfo();

public: // getter setter
    void setUsage(const int usage);
    void setUser(const int user);
    void setNice(const int nice);
    void setSystem(const int system);
    void setIdle(const int idle);

    int getUsage() const;
    int getUser() const;
    int getNice() const;
    int getSystem() const;
    int getIdle() const;

private:
    int cpuUsage;
    
    int user;
    int nice;
    int system;
    int idle;
};