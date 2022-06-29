#include "start_state.h"
#include "guess_state.h"
#include "../game_area.h"

bool StartState::exec(std::shared_ptr<GameArea>& area, std::unique_ptr<AbstractUserRequestAcceptor> request_acceptor) {
}

std::unique_ptr<AbstractMastermindState> StartState::nextState() {
    return std::make_unique<GuessState>();
}