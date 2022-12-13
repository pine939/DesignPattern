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

