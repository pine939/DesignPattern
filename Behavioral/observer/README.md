## Observer Pattern

### 개념

* 다수의 객체가 특정 객체 상태 변화를 감지하고, 알림을 받는 패턴이다. publish(발행) - subscribe(구독) 패턴이라고도 할 수 있다.
* publisher(발행자)는 다수의 subscribers(구독자들)을 알고 있어야 하며, 이들에게 notify 해야 한다.

### 예제 코드 작성

인기 아이돌 P는 Instagram, VLive, Twitter를 업데이트 할 때 마다 자신이 관리하는 개인 팬카페 회원들에게 알림을 보내려고 한다. 

우선 엄청나게 간단하게 Publisher, Subscriber 객체에 대한 책임을 아래와 같이 생각해 본다.
![image](https://user-images.githubusercontent.com/5865308/209095040-c2f21adc-4bf0-4977-87ab-bcaf8ded921b.png)   
코드로 빠르게 구현해 보면 다음과 같다.
```c++
class Subscriber
{
public:
    void GetNotifyFromPublisher(std::string msg);
};

class Publisher
{
public:
    void NotifyToSubscribers();
protected:
    std::list<Subscriber> subscribers_;
};
```
   
Publisher는 자신의 상태를 업데이트 해야 하는 책임도 있다.
![image](https://user-images.githubusercontent.com/5865308/209096521-92e696f7-22f0-4b82-b7b5-3123cbad0697.png)   
코드에 빠르게 반영했다.
```c++
class Subscriber
{
public:
    void GetNotifyFromPublisher(std::string msg);
};

class Publisher
{
public:
    void NotifyToSubscribers();
    void UpdateState();
protected:
    std::list<Subscriber> subscribers_;
};
```
