## Abstract Factory Pattern 

### 개념

![image](https://user-images.githubusercontent.com/5865308/196193425-ce1c0f6f-960a-4fee-941c-38d366ecb148.png)

서로 연관 있는 여러 객체를 만들어주는 인터페이스이다.   
구체적으로 어떤 클래스의 인스턴스를(concrete product)를 사용하는지 감출 수 있다.


### 예제 코드 작성

CakeStore의 서울지점과 대전지점에서 Cake를 만들 때 중복되는 재료가 있다.   
두 가게 모두 케익을 만드는 스타일은 다르지만 같은 종류의 밀가루, 우유, 설탕이 필요하다.   
이러한 부분을 묶어서 팩토리화 하는 것이 추상 팩토리 패턴이다.

구체적인 재료들은 어떤 팩토리를 쓰는지에 따라 달라진다.