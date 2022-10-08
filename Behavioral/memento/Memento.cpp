//
// Created by kangdasol on 22. 10. 8.
//

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