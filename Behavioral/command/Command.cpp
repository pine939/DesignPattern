//
// Created by kangdasol on 22. 12. 10.
//
#include<memory>
#include <utility>
#include <iostream>

// Command Interface
class Command
{
public:
    virtual void execute() = 0;
};

// Invoker
class Button
{
public:
    explicit Button(std::shared_ptr<Command> command) : command_(std::move(command)) {}
    void Press()
    {
        command_->execute();
    }
private:
    std::shared_ptr<Command> command_;
};

// Receiver
class Light
{
public:
    void On()
    {
        candle = "On";
        std::cout << "Light " << candle << std::endl;
    }
    void Off()
    {
        candle = "Off";
        std::cout << "Light " << candle << std::endl;
    }
private:
    std::string candle;
};

// Concrete Command
class LightOnCommand : public Command
{
public:
    void execute() override
    {
        light_.On();
    }
private:
    Light light_;
};

class LightOffCommand : public Command
{
public:
    void execute() override
    {
        light_.Off();
    }
private:
    Light light_;
};

int main()
{
    auto on_command = std::make_shared<LightOnCommand>();
    auto off_command = std::make_shared<LightOffCommand>();

    auto button = std::make_shared<Button>(on_command);
    button->Press();
    button = std::make_shared<Button>(off_command);
    button->Press();

    return 0;
}