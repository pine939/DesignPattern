## Iterator Pattern

### 개념 

![image](https://user-images.githubusercontent.com/5865308/194068227-4748f7af-a9a8-48cb-8f3b-56968e7f32e4.png)

* 집합 내부 구조를 노출시키지 않고, 순회 하는 방법을 제공하는 패턴이다.
* 구성 요소
    * Client
    * Iterator<Interface> : 어떻게 순회할지에 대한 방법을 가지고 있는 인터페이스
    * ConcreteIterator : Iterator를 구현
    * Aggregate<Interface> : 있을 수도 있고, 없을 수도 있다.
    * ConcreteAggregate : 얘도 있을 수도 있고, 없을 수도 있다. 

### 예제 코드 작성