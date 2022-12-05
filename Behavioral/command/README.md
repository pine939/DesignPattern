## Command Pattern

### 개념

![image](https://user-images.githubusercontent.com/5865308/205651189-86d739c8-6a22-420e-ab38-feb2bd1329ef.png)

* 요청을 캡슐화 하여 호출자(invoker)와 수신자(receiver)를 분리하는 패턴이다.
* 이벤트가 발생했을 때 실행될 기능이 다양하면서도 변경이 필요한 경우에 이벤트를 발생시키는 클래스를 변경하지 않고 재사용할 때 유용한 패턴이다. 
* 실행될 기능을 캡슐화 함으로써 주어진 여러 기능을 실행할 수 있는 재사용성이 높은 클래스를 설계하는 패턴이다. 

### 예제 코드 작성

[참고](https://leveloper.tistory.com/156)   
눌리면 특정 기능을 수행하는 버튼을 표현한 예제이다. 

***Command : Interface***   
***Button : Invoker(호출자의 코드는 변경되지 않는다.)***   
***Light : Receiver(요청을 처리하는 방법이 바뀌더라도)***   
***LightOnCommand, LightOffCommand : Concrete Command***   

1. Command 
* 동작을 수행하는 Execute 메서드가 포함된 Command 인터페이스이다. 

2. Button
* Button 클래스의 Pressed 메서드에서 구체적인 기능(라이트 켜기, 끄기)을 직접 구현하는 대신 버튼을 눌렀을 때 실행될 기능을 Button 클래스 외부에서 제공받아 캡슐화해 Pressed 메서드에서 호출한다. 

3. Light

4. LightOnCommand
* Command인터페이스를 상속받아 Execute 메서드를 구현해 라이트를 켜는 기능을 구현한다.

5. LightffCommand
* Command인터페이스를 상속받아 Execute메서드를 구현해 라이트를 끄는 기능을 구현한다. 

7. Client 
* Command인터페이스를 구현하는 LightOnCommand와 LightOffCommand객체를 Button객체에 설정한다. 
* 그리고 Button클래스의 pressed메서드에서 Command인터페이스의 Execute메서드를 호출할 수 있게 함으로써 LightOnCommand와 LightOffCommand클래스의 Execute 메서드를 실행할 수 있다. 
