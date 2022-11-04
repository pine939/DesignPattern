//
// Created by kangdasol on 22. 11. 4.
//

#include <iostream>

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