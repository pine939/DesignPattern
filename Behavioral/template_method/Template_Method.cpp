//
// Created by kangdasol on 22. 10. 9.
//

#include <iostream>
#include <memory>



class Schedule
{
public:
    void DailySchedule()
    {
        EatBreakfast();
        GotoOffice();
        GotoHome();
        EnjoyHobby();
        EatDinner();
    }
private:
    void EatBreakfast() {
        std::cout << "eat breakfast" << std::endl;
    }
    virtual void GotoOffice() = 0;
    virtual void GotoHome() = 0;
    void EnjoyHobby() {
        std::cout << "enjoy kumdo" << std::endl;
    }
    void EatDinner() {
        std::cout << "eat dinner" << std::endl;
    }
};



class SolSchedule : public Schedule
{
private:
    void GotoOffice() override {
        std::cout << "go to work: Jamsil --> Pangyo" << std::endl;
    }
    void GotoHome() override {
        std::cout << "go to home: Pangyo --> Jamsil" << std::endl;
    }
};



class JinSchedule : public Schedule
{
private:
    void GotoOffice() override {
        std::cout << "go to work: Jamsil --> KangNam" << std::endl;
    }
    void GotoHome() override {
        std::cout << "go to home: KangNam --> Jamsil" << std::endl;
    }
};
int main()
{
    std::cout << "==== Sol's Schedule ====" << std::endl;
    std::unique_ptr<Schedule> schedule = std::make_unique<SolSchedule>();
    schedule->DailySchedule();



   std::cout << "==== Jin's Schedule ====" << std::endl;
    schedule = std::make_unique<JinSchedule>();
    schedule->DailySchedule();
    return 0;
}
