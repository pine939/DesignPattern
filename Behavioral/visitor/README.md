## Visitor Pattern

### 개념

![image](https://user-images.githubusercontent.com/5865308/194742588-4745b2fd-58cc-4c49-97a2-fed846e89e45.png)

![image](https://user-images.githubusercontent.com/5865308/206937419-28a1197d-9e18-4266-ac5f-06fb7964e644.png)
* Visitor Pattern(방문자 패턴)은 알고리즘을 객체 구조에서 분리시키는 디자인 패턴이다. 이렇게 분리하면 구조를 변경하지 않고도 실질적으로 새로운 동작을 기존의 객체 구조에 추가할 수 있다. 개방-폐쇄의 원칙을 적용하는 방법의 하나이다. 
* Visitor(Interface) : 추가하고 싶은 로직을 담고 있다.
* Element(Interface) : 변하지 않는 클래스. (본연의 기능만 가지고 있다.)


### 예제 코드 작성

