#include "guess_state.h"
#include <iostream>
#include "../abstract_user_request_acceptor.h"
#include "../game_area.h"
#include "../utils.h"
#include "lose_state.h"
#include "win_state.h"

GuessState::GuessState() : _nextState(NextState::Same) {
}

bool GuessState::exec(std::shared_ptr<GameArea> &area, const std::unique_ptr<AbstractUserRequestAcceptor> &request_acceptor) {
    request_acceptor->writeMessage("Make your guess");
    SequenceRow guess = request_acceptor->requestGuess();
    const bool suggestions_end = !area->makeGuess(guess);

    if (suggestions_end) {
        request_acceptor->writeMessage("Suggestion end");
        _nextState = NextState::Lose;
        return true;
    }

    const bool last_guess_valid = area->lastGuessValid();
    if (last_guess_valid) {
        request_acceptor->writeMessage("Suggestion correct");
        _nextState = NextState::Win;
        return true;
    }

    const std::string hint_message = stringFromSequenceRow(area->lastGuessHint());
    std::cout << "Hint message: " << hint_message << std::endl;
    request_acceptor->writeMessage(hint_message);

    _nextState = NextState::Same;
    return false;
}

std::unique_ptr<AbstractMastermindState> GuessState::nextState() {
    switch (_nextState) {
        case NextState::Win:
            return std::make_unique<WinState>();
        case NextState::Lose:
            return std::make_unique<LoseState>();
        case NextState::Same:
            return std::make_unique<GuessState>();
    }
    throw std::runtime_error("State error");
}