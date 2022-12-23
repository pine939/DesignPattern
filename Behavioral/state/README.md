## State Pattern

### 개념

객체가 상태에 따라 다른 행동을 할 때, 상태를 체크하여 그에 따른 행동을 하는 것이 아니라   
***상태를 객체화 하여 알아서 행동하도록 위임***하는 디자인 패턴이다.
   
strategy 패턴과 state패턴의 차이는?
* strategy 패턴은 상속을 대체하여 사용자가 쉽게 알고리즘 전략을 바꿀 수 있도록 한다. 
* state 패턴은 if문을 대체하여 한 객체가 동일한 동작을 상태에 따라 다르게 수행할 경우 사용한다.   




상태와 행동.   
객체의 행동이 상태에 따라 변해야 할 때 사용한다.   
상태를 객체화 하여 Context가 가지고 있다.   
Context는 자신의 상태를 스스로 체크할 수 있다.

### 예제 코드 작성

자신의 상태를 자율적으로 관리하는 똑똑한 엘리베이터를 설계해 본다.   

기존의 엘리베이터는 상태가 추가될 수록 if문이 늘어나고 가장 큰 문제인 클래스의 메서드를 수정하게 된다.   
```c++
class NonElevator
{
public:
    explicit NonElevator(std::string state)
    : state_(std::move(state)) {}

   void PressUpButton()
    {
        if (state_ == "up") {
            std::cout << "do nothing" << std::endl;
        } else {
            std::cout << "go up" << std::endl;
            state_ = "up";
        }
    }

   void PressDownButton()
    {
        if (state_ == "down") {
            std::cout << "do nothing" << std::endl;
        } else {
            std::cout << "go down" << std::endl;
            state_ = "down";
        }
    }

   void PressStopButton()
    {
        if (state_ == "stop") {
            std::cout << "do nothing" << std::endl;
        } else {
            std::cout << "stop" << std::endl;
            state_ = "stop";
        }
    }
private:
    std::string state_;
};

int main()
{
    NonElevator nonElevator("stop");
    nonElevator.PressDownButton();
    nonElevator.PressUpButton();
    nonElevator.PressUpButton();
    nonElevator.PressStopButton();
    return 0;
}
```
```text
go down
go up
do nothing
stop
```

이 엘리베이터의 상태를 객체화 해 본다. 각 객체는 singleton으로 생성된다.
```c++
class ElevatorState
{
public:
    virtual void PressUpButton() = 0;
    virtual void PressDownButton() = 0;
    virtual void PressStopButton() = 0;
};

class UpState : public ElevatorState
{
public:
    static ElevatorState *GetInstance()
    {
        std::call_once(_once, []() {
           upState.reset(new UpState());
        });
        return upState.get();
    }
    void PressUpButton() override
    {
        std::cout << "already up state. do nothing." << std::endl;
    }
    void PressDownButton() override
    {
        std::cout << "go down" << std::endl;
    }
    void PressStopButton() override
    {
        std::cout << "stop" << std::endl;
    }
private:
    static std::unique_ptr<ElevatorState> upState;
    static std::once_flag _once;
    UpState() = default;
};

class DownState : public ElevatorState
{
public:
    static ElevatorState * GetInstance()
    {
        std::call_once(_once, []() {
            downState.reset(new DownState());
        });
        return downState.get();
    }
    void PressUpButton() override
    {
        std::cout << "go up." << std::endl;
    }
    void PressDownButton() override
    {
        std::cout << "already down state. do nothing." << std::endl;
    }
    void PressStopButton() override
    {
        std::cout << "stop" << std::endl;
    }
private:
    static std::unique_ptr<ElevatorState> downState;
    static std::once_flag _once;
    DownState() = default;
};

class StopState : public ElevatorState
{
public:
    static ElevatorState* GetInstance()
    {
        std::call_once(_once, [](){
            stopState.reset(new StopState());
        });
        return stopState.get();
    }
    void PressUpButton() override
    {
        std::cout << "go up" << std::endl;
    }
    void PressDownButton() override
    {
        std::cout << "go down" << std::endl;
    }
    void PressStopButton() override
    {
        std::cout << "already stop state. do nothing." << std::endl;
    }
private:
    static std::unique_ptr<ElevatorState> stopState;
    static std::once_flag _once;
    StopState() = default;
};

std::unique_ptr<ElevatorState> UpState::upState = nullptr;
std::unique_ptr<ElevatorState> DownState::downState = nullptr;
std::unique_ptr<ElevatorState> StopState::stopState = nullptr;
std::once_flag UpState::_once;
std::once_flag DownState::_once;
std::once_flag StopState::_once;
```
   
똑똑한 엘리베이터.   
```c++
class SmartElevator
{
public:
    SmartElevator()
    {
        SetState(StopState::GetInstance());
    }
    void SetState(ElevatorState *state)
    {
        state_ = state;
    }
    void PressUpButton()
    {
        state_->PressUpButton();
        SetState(UpState::GetInstance());
    }
    void PressDownButton()
    {
        state_->PressDownButton();
        SetState(DownState::GetInstance());
    }
    void PressStopButton()
    {
        state_->PressStopButton();
        SetState(StopState::GetInstance());
    }
private:
    ElevatorState *state_;
};
```
   
client와 실행 결과는 다음과 같다.
```c++
int main()
{
    SmartElevator smartElevator;
    smartElevator.PressDownButton();
    smartElevator.PressDownButton();
    smartElevator.PressUpButton();
    smartElevator.PressStopButton();
    return 0;
}
```
```text
go down
already down state. do nothing.
go up.
stop
```
