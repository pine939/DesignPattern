## Bridge Pattern 

### 개념

* 구성요소
  * ![image](https://user-images.githubusercontent.com/5865308/193460133-aa62fc05-ea07-45b5-a675-e6672f330090.png)
    * Client
    * Abstract
    * RedefinedAbstract
    * Implementation (Interface)
    * ConcreteImplementation
    
* 추상적인 것(기능)과 구체적인 것(구현)을 분리하여 연결하는 패턴이다.
* 성질이 다른 것들을 하나의 계층 구조 보다 독립적으로 나누는 것.
* 예를 들어, 게임 캐릭터의 'Skill'과 'Skin'은 독립적으로 나누는 것이 더 좋을 수 있다.
* 다른 계층 구조를 건드리지 않고, 각자의 계층 구조만 확장한다.

### 예제 코드 작성

다양한 도형을 다양한 도구를 사용해 그리는 프로그램을 Bridge 패턴으로 작성해 본다.

1. 도형의 추상 클래스를 작성한다. Shape클래스는 어떤 도형을 그리고, 사이즈를 재설정하는 기능을 한다.

```c++
class Shape {
public:
    virtual void Draw() = 0;
    virtual void Resize() = 0;
};
```

2. 도형 클래스를 구현한 구체 클래스를 작성한다. Shape 클래스를 상속받아 메서드들을 각자 역할에 맞게 오버라이딩한다. Circle클래스는 멤버 변수인 Tool (브릿지)를 사용해 원을 그리고, 원의 사이즈를 재설정한다는 문자열을 출력한다.

```c++
class Circle : public Shape {
public:
    explicit Circle(Tool &tool1) : tool(tool1) {}
    void Draw() override;
    void Resize() override;
private:
    Tool &tool;
};

void Circle::Draw() {
    std::cout << "draw circle by " << tool.GetToolName() << std::endl;
}

void Circle::Resize() {
    std::cout << "resize circle by " << tool.GetToolName() << std::endl;
}
```

3. 브릿지 클래스를 작성한다. Tool 클래스는 사용하는 도구의 이름을 반환하는 추상 클래스이다.

```c++
class Tool {
public:
    virtual std::string GetToolName() = 0;
};
```

4. 브릿지 클래스를 상속받은 구체 클래스를 작성한다.

```c++
class Pen : public Tool {
public:
    std::string GetToolName();
};

std::string Pen::GetToolName() {
    return "pen";
}
```

5. Client는 인터페이스인 shape의 메서드를 통해 원을 그리고, 사이즈를 재설정할 수 있다.

```c++
int main() {
    Shape *shape = new Circle(*new Pen());
    shape->Draw();
    shape->Resize();
    return 0;
}
```

6. Result

```text
draw circle by pen
resize circle by pen
```