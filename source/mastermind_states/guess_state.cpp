#include "guess_state.h"
#include "../game_area.h"
#include "../abstract_user_request_acceptor.h"
#include "lose_state.h"
#include "win_state.h"

GuessState::GuessState() : _nextState(NextState::Same) {

}

bool GuessState::exec(std::shared_ptr<GameArea>& area, std::unique_ptr<AbstractUserRequestAcceptor> request_acceptor) {
    SequenceRow guess = request_acceptor->requestGuess();
    const bool suggestions_end = !area->makeGuess(std::move(guess));

    if (suggestions_end) {
        _nextState = NextState::Lose;
        return true;
    }

    const bool last_guess_valid = area->lastGuessValid();
    if (last_guess_valid) {
        _nextState = NextState::Win;
        return true;
    }

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
}