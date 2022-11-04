## Facade Pattern

### 개념

![image](https://user-images.githubusercontent.com/5865308/199246797-a4342f6a-6a76-46e2-bf9a-540ca1a093ad.png)

* 복잡한 서브 시스템 의존성을 최소화 하는 패턴이다. Client가 사용하는 서브 시스템을 추상화하여 숨긴다.
* 퍼사드 클래스가 서브 시스템에 대한 모든 의존성을 가지게 되지만 모든 API를 Client에 노출하지 않으므로 Application에 대한 진입장벽을 낮출 수 있다.
* 서브 시스템에 대한 의존성을 한 곳으로 모을 수 있다는 장점이 있지만, 
* 퍼사드 클래스가 서브 시스템에 대한 모든 의존성을 가지게 된다. 

### 예제 코드 작성

컴퓨터의 CPU, 메모리, 하드디스크를 점검하는 프로그램을 퍼사드 패턴을 사용해 간단히 작성해 본다.   
CPU, 메모리, 하드디스크는 복잡한 로직으로 구성된 서브 시스템들이라고 가정한다. (예시에서는 간단한 출력이다.)   
클라이언트는 컴퓨터 객체의 CheckSystem 메서드만을 사용해 서브시스템들을 모두 점검할 수 있다.

```c++
class CPU
{
public:
    void CheckCPU()
    {
        std::cout << "Check CPU" << std::endl;
    }
};

class Memory
{
public:
    void CheckMemory()
    {
        std::cout << "Check The Memory" << std::endl;
    }
};

class HardDrive
{
public:
    void CheckHardDrive()
    {
        std::cout << "Check Hard Drive" << std::endl;
    }
};

class Computer
{
public:
    void CheckSystem()
    {
        cpu.CheckCPU();
        memory.CheckMemory();
        hardDrive.CheckHardDrive();
    }
private:
    CPU cpu;
    Memory memory;
    HardDrive hardDrive;
};

int main()
{
    Computer computer;
    computer.CheckSystem();
    return 0;
}
```
