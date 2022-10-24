## ProtoType Pattern

![image](https://user-images.githubusercontent.com/5865308/197516815-315a9433-fe23-4ba7-bc8a-734bc4d50e6e.png)

### 개념 

* Prototype 패턴이란?
  * 원형이 되는(prototypical) 인스턴스를 사용하여 생성할 객체의 종류를 명시하고, 만들어 낸 견본을 복사하여 새로운 객체를 생성한다.
* 참여자 
  * Prototype : 자신을 복제하는 데 필요한 인터페이스를 정의.
  * ConcretePrototype : 자신을 복제하는 메서드를 구현.
  * Client : Prototype에 복제를 요청하여 새로운 객체를 생성.

### 예제 코드 작성

