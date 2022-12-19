## Iterator Pattern

### 개념 

![image](https://user-images.githubusercontent.com/5865308/208037515-fac040e2-1d4a-447f-b0d1-209672e4dbf2.png)

![image](https://user-images.githubusercontent.com/5865308/208392068-19660ded-81a6-4663-88e4-1e259c6224e0.png)

* 복잡한 데이터 구조 세부 정보(list, vector, ...)를 노출시키지 않고, 해당 구조를 차례대로 순회할 수 있도록 하는 행동 디자인 패턴이다.   
클라이언트들은 단일 iterator interface를 통해 서로 다른 컬렉션들의 요소를 탐색할 수 있다. 
* 구성 요소
    * Client
    * Iterator<Interface> : 어떻게 순회할지에 대한 방법을 가지고 있는 인터페이스
    * ConcreteIterator : Iterator를 구현
    * Aggregate<Interface> : 있을 수도 있고, 없을 수도 있다.
    * ConcreteAggregate : 얘도 있을 수도 있고, 없을 수도 있다. 

### 예제 코드 작성
