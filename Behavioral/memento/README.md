## Memonto Pattern

### 개념

![image](https://user-images.githubusercontent.com/5865308/194677563-6cd61b3d-5d9e-4e17-b064-ecaafee16cb7.png)

* 객체의 정보를 외부에 노출하지 않으면서 외부에 저장했다가 해당 상태로 복구하는 패턴이다.
* CareTaker는 Memento를 참조하여, Originator를 몰라도 이 객체의 상태를 저장할 수 있고, 복원해 낼 수 있는 Client이다. (High Level)
* Originator는 Memento를 사용하여 자신의 정보를 저장하고, 복구한다. (Low Level)
* Memento는 캡슐화를 유지할 수 있도록 설계된 클래스이다.

### 예제 코드 작성 

* RedTeam, BluTeam 두 팀의 점수를 저장하고, 이전 값을 복원하는 코드를 Memento패턴을 사용해 구현해 본다.

```c++
#include <iostream>

// Memento
class GameSaver final {

public:
    GameSaver(int redteamscore, int blueteamscore) : red(redteamscore), blue(blueteamscore) {}

    int GetRedTeamScore() const {
        return red;
    }

    int GetBlueTeamScore() const {
        return blue;
    }

private:
    int red;
    int blue;
};

// Originator
class Game {
public:
    void SetRedTeamScore(int score) {
        this->redteamscore = score;
    }

    void SetBlueTeamScore(int score) {
        this->blueteamscore = score;
    }

    int GetRedTeamSocre() const {
        return redteamscore;
    }

    int BlueTeamScore() const {
        return blueteamscore;
    }

    GameSaver *const Save() const {
        GameSaver *saver = new GameSaver(redteamscore, blueteamscore);
        return saver;
    }

    void Rescore(GameSaver *saver) {
        SetRedTeamScore(saver->GetRedTeamScore());
        SetBlueTeamScore(saver->GetBlueTeamScore());
    }

private:
    int redteamscore;
    int blueteamscore;
};




// Client
int main() {
    Game *game = new Game();
    game->SetRedTeamScore(10);
    game->SetBlueTeamScore(20);

    GameSaver *saver = game->Save();

    game->SetRedTeamScore(30);
    game->SetBlueTeamScore(40);

    game->Rescore(saver);

    std::cout << game->GetRedTeamSocre() << std::endl;  // 10
    std::cout << game->BlueTeamScore() << std::endl;  // 20
    return 0;
}
```
