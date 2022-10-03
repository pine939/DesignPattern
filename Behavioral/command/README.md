## Command Pattern

### 개념

* 요청을 캡슐화 하여 호출자(invoker)와 수신자(receiver)를 분리하는 패턴이다.
* invoker (Button, MyApp)
* receiver (Light, Game)
* command (LightOnCommand, LightOffCommand, GameStartCommand, GameEndCommand : Command)

### 예제 코드 작성