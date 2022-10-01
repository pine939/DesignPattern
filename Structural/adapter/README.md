## Adapter Pattern

### 개념

* 구성요소
  * Target (Interface)
  * Client
  * Adapter 
  * Adaptee
* 클라이언트가 사용하지 않는 기존 코드(Adaptee)를 클라이언트가 사용하는 인터페이스(Target)의 구현체로 바꿔주는 패턴이다. (Adapter)
* Client는 Target을 기반으로 동작한다. 즉, Client가 Target Interface만 알면 되도록 코드를 작성해야 한다.

### 예제 코드 작성

1. Target Interface를 작성한다. UserInfo는 username과 password를 반환하는 추상 클래스이고, UserInfoService는 username을 매개변수로 받아 UserInfo를 반환하는 추상 클래스이다. 여기서 Target Interface는 UserInfoService이다.

```cpp
// UserInfo.h
class UserInfo
{
public:
    virtual std::string GetUserName() = 0;
    virtual std::string GetPassword() = 0;
};
```

2. 클라이언트가 사용하지 않는 Adaptee를 작성한다. Account는 email, name, password를 가지는 클래스이고, AccountService는 Account를 멤버로 가지며 FindAccountByUserName를 멤버 함수로 가짐으로써 주어진 username을 Account에 세팅해 주는 클래스이다.

```c++
// Account.h
class Account
{
public:
    std::string GetAccountName();
    std::string GetAccountPassword();
    std::string GetAccountEmail();
    void SetAccountName(const std::string& name);
    void SetAccountPassword(const std::string& password);
    void SetAccountEmail(const std::string& email);
private:
    std::string email;
    std::string name;
    std::string password;
};

// AccountService.h, AccountService.cpp
class AccountService {
public:
    AccountService();
    virtual ~AccountService();
    Account* FindAccountByUserName(const std::string& username);
private:
    Account* account;
};

AccountService::AccountService()
{
    account = new Account();
}

AccountService::~AccountService()
{
    delete account;
}

Account* AccountService::FindAccountByUserName(const std::string& username)
{
    account->SetAccountName(username);
    account->SetAccountPassword(username);
    account->SetAccountEmail(username);

    return account;
}
```

3. Adapter 클래스를 작성한다. AccountUserInfoService는 Target Interface인 UserInfoService를 상속 받아 구현한다. AccountService를 생성자 매개변수로 받아 Target과 Adaptee를 연결하는 역할을 한다. AccountUserInfo도 마찬가지로 UserInfo를 상속받고 생성자 매개변수로 Account를 받아 Account와 UserInfo를 연결하기 때문에 또 다른 Adapter역할이라고 볼 수 있다.

```c++
// AccountUserInfoService.h AccountUserInfoService.cpp
class AccountUserInfoService : public UserInfoService
{
public:
    explicit AccountUserInfoService(AccountService accountService);
    UserInfo* LoadUser(const std::string& username) override;
private:
    AccountService accountService;
};

AccountUserInfoService::AccountUserInfoService(AccountService accountService)
{
    this->accountService = accountService;
}

UserInfo* AccountUserInfoService::LoadUser(const std::string& username)
{
    return new AccountUserInfo(accountService.FindAccountByUserName(username));  // 반환형은 인터페이스(추상)이고, 실제 반환은 구체 클래스
}
```

4. Client를 작성한다. LoginHandler는 Target Interface인 UserInfoService를 사용해 로그인을 처리하는 클래스이다.

```c++
class LoginHandler
{
public:
    explicit LoginHandler(UserInfoService *userInfoService);
    virtual ~LoginHandler();

    std::string Login(const std::string& username, const std::string& password);
private:
    UserInfoService* userInfoService1;
};
```

```c++
LoginHandler::LoginHandler(UserInfoService *userInfoService)
                : userInfoService1(userInfoService) {}

LoginHandler::~LoginHandler() {}

std::string LoginHandler::Login(const std::string& username, const std::string& password)
{
    UserInfo *userInfo = userInfoService1->LoadUser(username);
    if (userInfo->GetPassword() == password)
    {
        std::cout << "login success!" << std::endl;
        return userInfo->GetPassword();
    }
    else
    {
        std::cout << "login fail!" << std::endl;
    }
    return std::string();
}
```

5. main.cpp에서는 Adapter가 Target과 Adaptee를 연결해 주기만 하면 된다.

```c++
int main()
{
    AccountService accountService;
    UserInfoService *userInfoService = new AccountUserInfoService(accountService);

    LoginHandler *loginHandler = new LoginHandler(userInfoService);
    std::string loginStr = loginHandler->Login("pine939", "pine939");

    std::cout << loginStr << std::endl;
    return 0;
}
```

6. Result 

```text
login success!
pine939
```