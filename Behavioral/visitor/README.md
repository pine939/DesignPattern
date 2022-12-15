## Visitor Pattern

### 개념

![image](https://user-images.githubusercontent.com/5865308/194742588-4745b2fd-58cc-4c49-97a2-fed846e89e45.png)

![image](https://user-images.githubusercontent.com/5865308/206937419-28a1197d-9e18-4266-ac5f-06fb7964e644.png)
* Visitor Pattern(방문자 패턴)은 알고리즘을 객체 구조에서 분리시키는 디자인 패턴이다. 
* 구조 
  * Visitor(Interface) : 알고리즘. 구조 클래스(Element)들의 메서드들을 호출하는(방문하는) 클래스이다. Element를 매개변수로 받는 visit이라는 메서드를 공용 메서드로 가진다. 
  * Element(Interface) : 변하지 않는 클래스.(본연의 기능만 가지고 있다.) Visitor를 매개변수로 받는 accept메서드를 공용 메서드로 가진다. 해당 메서드 내부에서는 v.visit(this)를 호출한다. 
  * ConcreteVisitor : Visitor 인터페이스를 구현한 클래스이다.
  * ConcreteElement : Element 인터페이스를 구현한 클래스이다. 
* 활용 상황 
  * 논리와 구조를 구분할 때 사용한다. 
  * 구조보다 논리가 자주 변경될 때 유리하다. 새로운 알고리즘을 기존 구조에 추가하기가 용이하기 때문이다.
* 장점과 단점 
  * 장점 
    * 작업 대상(Element)과 작업 항목(Visitor)을 분리할 수 있다. (자료구조의 독립성이 높아진다.)
  * 단점 
    * 작업 대상과 작업 항목의 결합도가 높아진다. 작업 대상을 추가할 경우, 이에 해당하는 작업 항목을 Visitor 클래스에 추가해야 한다. 즉, 확장성이 좋지 않다는 단점이 있다. 

### 예제 코드 작성

흑호랑이 해를 맞아, 비타민 음료 제조회사 'Vita'는 제품군 별로 다른 모양의 호랑이 라벨을 제작하려고 한다. 
제품군은 스틱, 병, 캔이 있으며 제조 공장의 컨베이어 벨트와 동작하는 로봇 팔은 각각 1개 뿐이다. 
이를 visitor 패턴을 사용해 구현해 보자. 

구현 해야 할 기능을 visitor 패턴에 맞게 분류해 보면,
* Element Class : Element (Interface)
* Concrete Element Class : VitaInStick, VitaInBottle, VitaInCan, ConveyorBelt
* Visitor Class : Visitor (Interface)
* Concrete Visitor Class : RobotArm 

로 나눌 수 있다.

1. 작업 대상을 추상화한 Element 인터페이스는 Visitor를 매개변수로 받는 Accept 메서드를 가지고 있다. 
```c++
class Element
{
public:
    virtual void Accept(shared_ptr<class Visitor> visitor) = 0;
};
```

2. Element를 상속받아 구현한 세 가지 제품군은 다음과 같다. 각 제품군의 Accept 메서드는 매개변수인 visitor의 visit 메서드를 호출하는 역할만 하고 있다. 
this 포인터를 smart pointer로 넘기는 방법은 [여기](https://bunhere.tistory.com/460)를 참고하자. 
```c++
class VitaInStick : public Element, public enable_shared_from_this<VitaInStick>
{
public:
    VitaInStick() : product_name_("VitaInStick") {};
    void Accept(shared_ptr<Visitor> visitor) override;
private:
    string product_name_;
};
class VitaInBottle : public Element, public enable_shared_from_this<VitaInBottle>
{
public:
    VitaInBottle() : product_name_("VitaInBottle") {};
    void Accept(shared_ptr<Visitor> visitor) override;
private:
    string product_name_;
};
class VitaInCan : public Element, public enable_shared_from_this<VitaInCan>
{
public:
    VitaInCan() : product_name_("VitaInCan") {};
    void Accept(shared_ptr<Visitor> visitor) override;
private:
    string product_name_;
};
// implement concrete element class.
void VitaInStick::Accept(shared_ptr<Visitor> visitor)
{
    cout << product_name_ << " is Ready!" << endl;
    visitor->Visit(shared_from_this());
}
void VitaInBottle::Accept(shared_ptr<Visitor> visitor)
{
    cout << product_name_ << " is Ready!" << endl;
    visitor->Visit(shared_from_this());
}
void VitaInCan::Accept(shared_ptr<Visitor> visitor)
{
    cout << product_name_ << " is Ready!" << endl;
    visitor->Visit(shared_from_this());
}
```

3. 위에서 작성한 3가지 제품군을 컨베이어 벨트에 담아보자.
```c++
class ConveyorBelt : public Element
{
public:
    ConveyorBelt()
    {
        vitas.push_back(make_shared<VitaInStick>());
        vitas.push_back(make_shared<VitaInBottle>());
        vitas.push_back(make_shared<VitaInCan>());
    }
    void Accept(shared_ptr<Visitor> visitor) override
    {
        cout << "ConveyorBelt is Ready!" << endl;
        visitor->Visit(make_shared<ConveyorBelt>());
        for (const auto& item : vitas)
        {
            item->Accept(visitor);
        }
    }
private:
    vector<shared_ptr<Element>> vitas;
};
```

4. Visitor를 상속받는 RobotArm은 세 가지 제품군에 맞게 호랑이 그림을 그려준다.   
Stick형에는 누워있는 호랑이를, Bottle형에는 운동하는 호랑이를, Can형에는 응원하는 호랑이를 그린다. 
```c++
class RobotArm : public Visitor
{
    void Visit(shared_ptr<ConveyorBelt> belt) override
    {
        cout << "Using Conveyor Belt" << endl;
    }
    void Visit(shared_ptr<VitaInStick> vitaInStick) override
    {
        cout << "Draw a Tiger laying down" << endl;
    }
    void Visit(shared_ptr<VitaInBottle> vitaInBottle) override
    {
        cout << "Draw a Tiger Exercising" << endl;
    }
    void Visit(shared_ptr<VitaInCan> vitaInCan) override
    {
        cout << "Draw a Tiger Cheering" << endl;
    }
};
```
 
5. main
```c++
int main()
{
    unique_ptr<Element> element = make_unique<ConveyorBelt>();
    shared_ptr<Visitor> visitor = make_shared<RobotArm>();
    element->Accept(visitor);
}
```

6. 결과 
```text
ConveyorBelt is Ready!
Using Conveyor Belt
VitaInStick is Ready!
Draw a Tiger laying down
VitaInBottle is Ready!
Draw a Tiger Exercising
VitaInCan is Ready!
Draw a Tiger Cheering
```
