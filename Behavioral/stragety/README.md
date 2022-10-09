## Strategy Pattern

### 개념

![image](https://user-images.githubusercontent.com/5865308/194740514-809965b0-11ce-4f87-9686-308ab3001bc0.png)

* 여러 알고리즘을 캡슐화하고, 상호 교환이 가능하게 만드는 패턴이다.
* Context : 로직을 수행하는 클래스
* Strategy(Interface) : 상황에 따라 달라지는 전략
* ConcreteStrategy : 상황에 따라 달라지는 전략의 구현체
* Client : Strategy를 선택하여 Context를 만들 때 넣어 준다. (생성자 or Operation)
* 장점
    * 새로운 전략을 추가해도 기존의 전략을 수정하지 않는다.
    * 상속 대신 위임을 사용할 수 있다.
    * 런타임에 전략을 변경할 수 있다.
* 단점
    * 클라이언트 코드가 구체적인 전략을 알고 있어야 한다.


### 예제 코드 작성

'무궁화 꽃이 피었습니다' 게임에서 속도를 조절하는 부분을 Strategy 패턴을 사용해 구현해 보자.

```c++
// Speed (Interface)
class Speed {
public:
    virtual void BlueLight() = 0;
    virtual void RedLight() = 0;
};

// Context
class BlueLightRedLight {
public:
    explicit BlueLightRedLight(Speed *speed1) : speed(speed1) {}
    void BlueLight() {
        speed->BlueLight();
    }

    void RedLight() {
        speed->RedLight();
    }

private:
    Speed *speed;
};

// Concrete Strategy
class Normal : public Speed {
public:
    virtual void BlueLight() {
        std::cout << "무궁화     꽃     이" << std::endl;
    }

    virtual void RedLight() {
        std::cout << "피었   습 니  다" << std::endl;
    }
};

class Faster : public Speed {
public:
    virtual void BlueLight() {
        std::cout << "무궁화꽃이" << std::endl;
    }

    virtual void RedLight() {
        std::cout << "피었습니다" << std::endl;
    }
};

// Client
int main() {
    BlueLightRedLight *game = new BlueLightRedLight(new Normal());
    game->BlueLight();
    game->RedLight();

    BlueLightRedLight *game2 = new BlueLightRedLight(new Faster());
    game2->BlueLight();
    game2->RedLight();
    return 0;
}
```