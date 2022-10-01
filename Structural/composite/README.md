## Composite Pattern

* 구성요소
    * Client
    * Component (Interface)
    * Leaf
    * Composite
* 그룹 전체와 개별 객체를 동일하게 처리할 수 있는 패턴이다.
* 클라이언트는 전체나 부분이 모두 동일한 컴포넌트로 인식할 수 있도록 계층구조를 만드는 것. 즉, 클라이언트는 컴포넌트에게만 위임한다.
* 컴포넌트?
* Leaf, Composite의 공통된 Operation을 컴포넌트 인터페이스에 작성한다.
* Leaf?
* Leaf를 참조하는 것이 아니라 Component를 참조한다.
* 예를 들어, Bag에 들어있는 Item들의 가격을 알아내는 어플리케이션을 개발할 때,
    * Item(Leaf), Bag(Composite)의 계층 구조를 Component로 추상화 하여 클라이언트는 Component 객체를 통해 Item의 가격을 알아낼 수 있다.
    * 물론 Item의 가격은 Item이 알고 있고, 계산은 Bag 객체가 책임지도록 한다.