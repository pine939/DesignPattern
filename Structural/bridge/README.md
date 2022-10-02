## Bridge Pattern 

### 개념

* 구성요소
  * ![image](https://user-images.githubusercontent.com/5865308/193432196-d069049d-d1e0-45fe-a1da-f8e7c296a69d.png)
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

'무언가 한다'는 엄청나게 추상화된 클래스를 사용해 '책을 읽는다'는 프로그램을 작성해 본다.

1. 기능에 대한 클래스를 작성한다. 기능은 'start', 'act', 'end'로 정의하며, 인터페이스와 이를 상속한 구체 클래스로 작성한다. 기능 클래스에는 구현 인터페이스(Bridge)를 가지고 있다.

2. 구현에 대한 클래스를 작성한다. 구현은 'rawstart', rawact', 'rawend'로 정의하며, 기능과 마찬가지로 인터페이스와 이를 상속한 구체 클래스로 작성한다.

3. Client에서는 기능 클래스 생성자에 구체 클래스를 넘겨 이 두 클래스를 이어주면 된다.

4. Result