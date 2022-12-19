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

회사 동료들과 채팅 할 수 있는 프로그램을 중재자 패턴을 사용해 구현해 보자.   


* mediator interface 
```c++
class Mediator
{
public:
  virtual void AddUser(class Colleauge user) = 0;
  virtual void DeleteUser(Colleauge user) = 0;
  virtual void SendMessage(string message, Colleage user) = 0;
}
```

* colleague interface 
```c++
class Colleage
{
public:
  Colleague(Mediator mediator, string name)
  : mediator_(mediator), name_(name) {}
  virtual void Send(string msg) = 0;
  virtual void Receive(string msg) = 0;
protected:
  Mediator mediator_;
  string name_;
}
```

* ConcreteMediator 
```c++
class ConcreteMediator : public Mediator
{

}
```
