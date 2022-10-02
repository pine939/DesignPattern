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

온점을 trim하고, SQL Injection에 안전한 댓글 프로그램을 작성해 본다.