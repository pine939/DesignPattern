## Template Method Pattern

### 개념

![image](https://user-images.githubusercontent.com/5865308/194741423-a200ac70-6bcb-4106-bd46-a36c75c55056.png)

* 알고리즘 구조를 서브 클래스가 확장할 수 있도록(구체적으로 구현할 수 있도록) 템플릿으로 제공하는 패턴이다.
* 상속을 사용한다.
* 코드의 중복을 줄일 수 있다.
* Abstract Class에는 반드시 템플릿 역할을 하는 TemplateMethod()가 있어야 한다.
* 루틴이 정해져 있고, 세부적인 내용이 달라질 때 사용합니다.

### 예제 코드 작성

Sol과 Jin은 영혼의 단짝이다. 이 둘은 하루 일과가 매우 비슷한데, 이를 템플릿 메서드를 사용해 구현해 보려고 한다. 
* 하루 일과 
  * 아침을 먹는다.
  * 출근 한다.
  * 퇴근 한다.
  * 여가 시간을 보낸다.
  * 저녁을 먹는다.
* 특이점
  * Sol과 Jin은 잠실에 거주하며, 각각 재직하는 회사는 판교와 강남에 있다.

1. Template Method가 정의된 Abstract Class이다. Daily Schedule는 Sol과 Jin의 하루 일과를 템플릿으로 정의한 메서드이다.
```c++
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
```

2. Concrete Class
```c++
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
```

3. client Code, Result
```c++
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
```
```text
==== Sol's Schedule ====
eat breakfast
go to work: Jamsil --> Pangyo
go to home: Pangyo --> Jamsil
enjoy kumdo
eat dinner
==== Jin's Schedule ====
eat breakfast
go to work: Jamsil --> KangNam
go to home: KangNam --> Jamsil
enjoy kumdo
eat dinner
```
---

## Template Callback Pattern

### 개념

![image](https://user-images.githubusercontent.com/5865308/194742196-3e2a3153-95ca-48cc-88b6-8abb79632cb4.png)

* 콜백으로 상속 대신 위임을 사용하는 템플릿 패턴
