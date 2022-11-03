## Decorator Pattern

### 개념

* 기존 코드를 변경하지 않고, 부가 기능을 추가하는 패턴이다.
* 상속으로 해결하려 했을 때 생기는 문제?
* 상속을 사용하면 컴파일 타임에 추가하려는 서비스(객체)가 정해진다.
* 하나의 기능을 파생해 여러 부가 기능들이 생기고, 이들을 조합해야 하는 상황일 때 상속을 사용한다면 다중 상속, 코드의 복잡성이 늘어날 수 있다.
* 구성 요소
  * ![image](https://user-images.githubusercontent.com/5865308/193433377-d6436a18-3710-4750-b4a8-812fd990b8fd.png)
      * Client
    * Component (Interface)
    * ConcreteComponent
    * Decorator (Wrappee : Component)
    * ConcreteDecorator1, ConcreteDecorator2, ...
* 장점
    * 구현하고자 하는 기능들을 기존 구조를 변경하지 않고도 조합하여 사용할 수 있다.
    * Decorator를 동적으로 사용할 수 있다. 컴파일 시간에 결정되지 않고, 런타임에서 조합하여 사용할 수 있다.
* 단점
    * 기능을 조합하는 코드가 복잡해 질 수 있다.
* 관련 SOLID 원칙
    * ConcreteDecorator들은 각자의 일만 하면 되므로 '단일 책임 원칙'을 지킬 수 있다.
    * 기존 클래스들의 코드가 변경되지 않으면서 ConcreteComponent기능을 확장할 수 있기 때문에 'Open-Close 원칙'을 지킬 수 있다.
    * Client는 인터페이스를 사용하여 구체적인 기능을 사용할 수 있으므로 'Dependency Inversion 원칙'을 지킬 수 있다. (인터페이스를 사용해 의존성 역전)

### 예제 코드 작성

Item은 기본적으로 스피드가 2배가 되는데,    
데코레이터 패턴을 사용해 공격력이 10% 증가하고, 방어력이 20% 증가하는 Item으로 기능을 추가해 본다. (실제 게임 캐릭터의 Status를 바꾼 것 까지는 구현하지 않고, 출력하기만 했다.)

1. Item 인터페이스와 이를 구현한 DefaultItem. 스피드를 2배 증가시켜 준다.   
* Item : Component
* DefaultItem : ConcreteComponent

```c++
class Item
{
public:
    virtual void DoubleSpeed() = 0;
};
class DefaultItem : public Item
{
public:
    void DoubleSpeed() override
    {
        std::cout << "double speed!!!" << std::endl;
    }
};
```

2. Item에 부가기능을 추가하기 위한 Decorator 최상위 클래스. Wrapper함수로써 Item인터페이스의 메서드를 호출한다.

```c++
class DecorateItem : public Item
{
public:
    explicit DecorateItem(Item *item) : item_(item) {}
    void DoubleSpeed() override
    {
        item_->DoubleSpeed();
    }

private:
    Item *item_;
};
```

3. Decorator를 상속받은 부가 기능들. 공격력을 10% 증가시켜 주고, 방어력을 20%증가시켜준다.

```c++
class UpgradeDamageDecorateItem : public DecorateItem
{
public:
    explicit UpgradeDamageDecorateItem(Item *item)
    : DecorateItem(item) {}
    void DoubleSpeed() override
    {
        DecorateItem::DoubleSpeed();
        UpgradeDamage();
    }

    static void UpgradeDamage()
    {
        std::cout << "upgrade 10% damage!!!" << std::endl;
    }
};
class UpgradeDefenseDecorateItem : public DecorateItem
{
public:
    explicit UpgradeDefenseDecorateItem(Item *item)
    : DecorateItem(item) {}
    void DoubleSpeed() override
    {
        DecorateItem::DoubleSpeed();
        UpgradeDefense();
    }

    static void UpgradeDefense()
    {
        std::cout << "upgrade 20% defense!!!" << std::endl;
    }
};
```

4. 이 Item을 사용하는 Goblin 캐릭터.

```c++
class Goblin
{
public:
    explicit Goblin(Item *item)
    : item_(item){}

    void SetStatusWithItem()
    {
        item_->DoubleSpeed();
    }
private:
    Item *item_;
};
```

5. Client

```c++
int main()
{
    std::cout << "=== Default ===" << std::endl;
    Item *item = new DefaultItem();
    Goblin *goblin = new Goblin(item);
    goblin->SetStatusWithItem();

    std::cout << "=== Default + Upgrade Damage ===" << std::endl;
    item = new UpgradeDamageDecorateItem(item);
    goblin = new Goblin(item);
    goblin->SetStatusWithItem();

    std::cout << "=== Default + Upgrade Damage + Upgrade Defense ===" << std::endl;
    item = new UpgradeDefenseDecorateItem(item);
    goblin = new Goblin(item);
    goblin->SetStatusWithItem();
    return 0;
}
```

6. 출력 결과

```text
=== Default ===
double speed!!!
=== Default + Upgrade Damage ===
double speed!!!
upgrade 10% damage!!!
=== Default + Upgrade Damage + Upgrade Defense ===
double speed!!!
upgrade 10% damage!!!
upgrade 20% defense!!!

```
