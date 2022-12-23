## Interpreter Pattern

### 개념

* 문법적 규칙을 클래스화 하여, 일련의 규칙을 통해 언어/문법을 해석하는 패턴이다. 
* 예를 들어, master 테이블에서 데이터를 조회할 때 select * from master; 라는 sql 문법을 사용하여 개발자들은 손쉽게 DB를 사용할 수 있다. 이처럼 문법적 규칙을 클래스화 하여 사용자가 원하는 답을 얻도록 해주는 패턴이 interpretor패턴이다. 

### 예제 코드 작성

interpretor 패턴을 사용해 후위 표기법을 구현해 본다.   

* 출처 : https://velog.io/@hoit_98/%EB%94%94%EC%9E%90%EC%9D%B8-%ED%8C%A8%ED%84%B4-Interpreter-%ED%8C%A8%ED%84%B4
