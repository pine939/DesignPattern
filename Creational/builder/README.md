## Builder Pattern

### 개념

![image](https://user-images.githubusercontent.com/5865308/196721648-d2857cba-b532-446d-8ad3-4f568930e8ab.png)

* 동일한 프로세스를 거쳐 다양한 구성의 인스턴스를 만들 때 사용하는 패턴이다.
* 생성자만으로 객체를 만들기 어려운 상황이 있을 수 있다. 이 때, 생성자에서 초기화 하는 부분과 그 외 객체 생성에 필요한 부분을 담당하는 부분을 클래스로(Builder) 분리하여 객체를 생성하는 복잡한 과정을 숨길 수 있다.
* 클라이언트가 불완전한 객체를 사용하지 못하도록 방지할 수 있다.

### 예제 코드 작성

다양한 장르의 영화를 제작하는 MovieDirector 클래스를 빌더 패턴을 사용하여 설계해 보자. 

MovieDirector는 MovieBuilder를 사용해 "Your Name", "Extraordinary Attorney Woo"라는 이름의 Movie를 만들어 낸다.

Movie는 다음과 같은 특징을 가지고 있다.
 * 영화 제목
 * 장르
 * 제작 기간
 * 주연 배우
 * 촬영 장소
 
 
