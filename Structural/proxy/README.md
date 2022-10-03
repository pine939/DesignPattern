## Proxy Pattern

### 개념

![image](https://user-images.githubusercontent.com/5865308/193548724-6bc839cb-dde1-48b0-b6d6-90630bc2afb3.png)

* 특정 객체에 대해 접근을 제어하거나 기능을 추가할 수 있는 패턴이다.
* Proxy에서는 본인의 인터페이스 타입을 참조한다.
* 장점
    * 기존의 코드는 변경하지 않고, 새로운 기능을 추가할 수 있다. (Open Closed)
    * 기존 코드가 해야 할 일만 유지할 수 있다. (단일 책임원칙)
* 단점
    * 코드가 복잡해진다.

### 예제 코드 작성

게임에 접속하는 프로그램에 Proxy Pattern을 사용해 게임 로딩 시간을 측정하는 프로그램을 추가해 본다.

1. 게임 서비스를 제공하는 GameService 인터페이스 클래스를 작성한다.

```c++
class GameService {
public:
    virtual void GameStart() = 0;
};
```

2. GameService를 상속받는 실제적인 구현체 ConcreteGameService 클래스를 작성한다. 캡슐화 하려는 대상은 이 클래스이다.

```c++
class ConcreteGameService : public GameService {
public:
    void GameStart() override;
};

void ConcreteGameService::GameStart() {
    std::cout << "welcome! we start this game." << std::endl;
}
```

3. Proxy역할을 하는 GameServiceProxy 클래스를 작성한다. 이 클래스는 게임 로딩 시간을 측정하는 기능과 위에 작성된 ConcreteGameService객체를 생성하여 메서드들을 호출함으로써 기능을 확장한다.

```c++
class GameServiceProxy : public GameService {
public:
    void GameStart() override;
};

void GameServiceProxy::GameStart() {
    auto start = std::chrono::system_clock::now();
    GameService *gameService1 = new ConcreteGameService();
    gameService1->GameStart();
    for (int i = 0; i < 10000000; i++) {}
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "loading time : " << elapsed_seconds.count() << std::endl;
}
```

4. Client에서는 ConcreteGameService를 알지 못해도, Proxy를 통해 기존 기능+추가된 기능을 사용할 수 있다.

```c++
int main() {
    GameService *service = new GameServiceProxy();
    service->GameStart();
    return 0;
}
```

5. Result

```text
welcome! we start this game.
loading time : 0.0252378
```