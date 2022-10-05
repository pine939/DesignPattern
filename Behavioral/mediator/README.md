## Mediator Pattern

### 개념

![image](https://user-images.githubusercontent.com/5865308/194076912-0d82514b-3a4d-4cbf-acfa-d0d53d66f635.png)

* 여러 객체들이 소통하는 방법을 캡슐화한 패턴이다.
* 여러 객체들 간의 의존성을 최소화 한다. 즉, UML에서 핵심은 colleagueA와 colleagueB가 서로 통신하지 않는다는 점이다. ConcreteMediator는 이 둘을 참조하고 있으며, 이들을 추상화한 클래스인 Colleague는 Mediator(중재자, Interface)만을 사용함으로써 여러 객체들(colleagueA, colleagueB) 간의 의존성을 최소화 할 수 있다.
* Mediator(중재자)란 모든 Colleague들의 요청을 받아들여 처리하는 역할을 한다. (이 곳으로 의존성을 몰아 넣는다는 개념)

### 예제 코드 작성