## Mediator Pattern

### 개념

![image](https://user-images.githubusercontent.com/5865308/194076912-0d82514b-3a4d-4cbf-acfa-d0d53d66f635.png)

* 여러 객체들이 소통하는 방법을 캡슐화한 패턴이다.
* 여러 객체들 간의 의존성을 최소화 한다. 즉, UML에서 핵심은 colleagueA와 colleagueB가 서로 통신하지 않는다는 점이다. ConcreteMediator는 이 둘을 참조하고 있으며, 이들을 추상화한 클래스인 Colleague는 Mediator(중재자, Interface)만을 사용함으로써 여러 객체들(colleagueA, colleagueB) 간의 의존성을 최소화 할 수 있다.
* Mediator(중재자)란 모든 Colleague들의 요청을 받아들여 처리하는 역할을 한다. (이 곳으로 의존성을 몰아 넣는다는 개념)

* [옵저버, 퍼사드 패턴과 차이점](https://brownbears.tistory.com/568)
  * 퍼사드 패턴 : 1 통신을 위해 인터페이스를 설계하고 제공한다는 점에서 두 패턴은 동일하지만, 퍼사드 패턴은 단방향 통신만 가능하지만 중재자 패턴은 양방향 통신을 지원한다.
  * 옵저버 패턴 : 옵저버 패턴은 1개의 publisher에 대해 N개의 subscriber가 존재하고, observer가 pulling이나 push 방식을 통해 관리하지만 중재자 패턴은 M개의 publisher와 N개의 subscriber 사이에서 1개의 mediator클래스를 통해 통신을 하는 방식이다. 

### 예제 코드 작성

동료들과 채팅 할 수 있는 프로그램을 중재자 패턴을 사용해 구현해 보자.   

#### 책임 주도 설계
책임 주도 설계를 기반으로 생각해 본 객체들 간의 관계는 간단히 다음과 같다.
![image](https://user-images.githubusercontent.com/5865308/208861821-0b612a9a-f0ec-44aa-bc30-53fec5ccff55.png)
* 그림 설명
  * M 객체는 A와 B에게 메시지를 직접 전송한다. 
  * A, B는 서로 통신하지 않으며 M 객체를 통해서만 통신을 한다. (M객체에게 메시지를 보내고, 받는다. 단, 자신이 보낸 메시지는 수신하지 않는다.)
  * A, B는 각자 수신한 메시지를 출력한다. 
* Mediator의 책임
  * User를 추가한다.
  * User를 삭제한다.
  * 보낸 User를 제외한 모든 User들에게 메시지를 송신한다.
* Colleague의 책임
  * Mediator를 캡슐화 한다.
  * 자신의 이름을 알고 있다.
  * Mediator로 메시지를 보낸다.
  * 수신한 메시지를 출력한다.

#### 구현 
```c++
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <memory>
#include <algorithm>

class Mediator
{
public:
    virtual void SendMessage(std::string msg, std::shared_ptr<class Colleague> user) = 0;
    virtual void AddUser(std::shared_ptr<Colleague> user) = 0;
    virtual void DeleteUser(std::shared_ptr<Colleague> user) = 0;
};

class Colleague
{
public:
    explicit Colleague(std::shared_ptr<Mediator> mediator, std::string name)
    : mediator_(std::move(mediator)), name_(std::move(name)) {}
    virtual void Send(std::string msg) = 0;
    virtual void Receive(std::string msg) = 0;
protected:
    std::shared_ptr<Mediator> mediator_;
    std::string name_;
};

class ConcreteMediator : public Mediator
{
public:
    void SendMessage(std::string msg, std::shared_ptr<class Colleague> user) override
    {
        for (auto &item : user_)
        {
            if (user != item)
            {
                item->Receive(msg);
            }
        }
    }
    void AddUser(std::shared_ptr<Colleague> user) override
    {
        user_.push_back(std::move(user));
    }
    void DeleteUser(std::shared_ptr<Colleague> user) override
    {
    }
private:
    std::vector<std::shared_ptr<Colleague>> user_;
};

class ConcreteColleague : public Colleague, public std::enable_shared_from_this<ConcreteColleague>
{
public:
    explicit ConcreteColleague(std::shared_ptr<Mediator> mediator, std::string name)
    : Colleague(std::move(mediator), std::move(name)) {}
    void Send(std::string msg) override
    {
        mediator_->SendMessage(msg, shared_from_this());
    }
    void Receive(std::string msg) override
    {
        std::cout << "'" << name_ << "' Received Msg: " << msg << std::endl;
    }
};

int main()
{
    std::shared_ptr<Mediator> mediator = std::make_shared<ConcreteMediator>();
    std::shared_ptr<Colleague> user1 = std::make_shared<ConcreteColleague>(mediator, "kang");
    std::shared_ptr<Colleague> user2 = std::make_shared<ConcreteColleague>(mediator, "kim");
    std::shared_ptr<Colleague> user3 = std::make_shared<ConcreteColleague>(mediator, "kwon");
    mediator->AddUser(user1);
    mediator->AddUser(user2);
    mediator->AddUser(user3);



   user1->Send("hello");
    
    return 0;
}
```

#### 결과 

```text
'kim' Received Msg: hello
'kwon' Received Msg: hello
```
