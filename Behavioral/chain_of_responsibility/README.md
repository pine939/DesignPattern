## Chain of Responsibility Pattern

### 개념

![image](https://user-images.githubusercontent.com/5865308/193574640-05ebdfb2-c1c3-4f2b-b99d-e87cf522ca9d.png)

* 요청을 보내는 쪽과 처리하는 쪽을 분리하는 패턴이다.
* 여기서 Responsibility는 '단일 책임 원칙'에서 말하는 책임이다. 즉, 각 하위 객체들은 각자의 유일한 책임이 있고(Request) Client에서는 이를 엮어서 처리(Response)한다.

### 예제 코드 작성

1. Request 클래스를 작성한다.

```c++
class Request {
public:
    explicit Request(std::string body);
    virtual ~Request();
    std::string GetBody();
    void SetBody(std::string body);
private:
    std::string body;
};
Request::Request(std::string body) : body(std::move(body)){}
Request::~Request() {}
std::string Request::GetBody() {
    return this->body;
}

void Request::SetBody(std::string body) {
    this->body = body;
}
```

2. RequestHandler 클래스를 작성한다. RequestHandler객체를 멤버 변수(RequestHandler *nextHandler)로 받아서 해당 객체의 handler에 요청(Request 객체)을 넘겨준다.

```c++
class RequestHandler {
public:
    explicit RequestHandler(RequestHandler *requestHandler);
    virtual ~RequestHandler();
    virtual void handler(Request *requset);  // handle the request!
protected:
    RequestHandler *nextHandler;
};
RequestHandler::RequestHandler(RequestHandler *requestHandler) : nextHandler(requestHandler){}

void RequestHandler::handler(Request *request) {
    std::cout << request->GetBody() << std::endl;
    if (!nextHandler) return;
    nextHandler->handler(request);
}
```

4. RequestHandler를 상속하는 ConcreteRequestHandler 클래스들을 작성한다. 해당 ConcreteRequestHandler 클래스들은 request처리 후, 다음 핸들러에게 요청을 넘긴다.

```c++
DishWashRequestHandler::DishWashRequestHandler(RequestHandler *requestHandler) : RequestHandler(requestHandler) {}

void DishWashRequestHandler::handler(Request *request) {
    request->SetBody("Handle Dish Wash");
    //nextHandler->handler(request);
    RequestHandler::handler(request);
}
// LaundryRequestHandler, VacuumRequestHandler 코드 참고
```

5. Client에서는 RequestHandler 체인을 만들어서 해당 체인의 handler메서드를 호출한다. Request는 연쇄적으로 처리된다.

```c++
class Client {
public:
    explicit Client(RequestHandler *requestHandler);
    virtual ~Client();
    void Work();
private:
    RequestHandler *requestHandler;
};

Client::Client(RequestHandler *requestHandler) : requestHandler(requestHandler) {}

Client::~Client() {}

void Client::Work() {
    requestHandler->handler(new Request("Work Start!"));
}

int main() {
    RequestHandler *chain = new RequestHandler(new DishWashRequestHandler(new LaundryRequestHandler(new VacuumRequestHandler(
            nullptr))));
    Client *client = new Client(chain);
    client->Work();
    return 0;
}
```

7. Result

```text
Work Start!
Handle Dish Wash
Handle Laundry
Handle Vacuum
```