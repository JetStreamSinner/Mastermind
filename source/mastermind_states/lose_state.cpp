#include "lose_state.h"
#include "../abstract_user_request_acceptor.h"
#include "../game_area.h"
#include "start_state.h"

bool LoseState::exec(std::shared_ptr<GameArea> &area, const std::unique_ptr<AbstractUserRequestAcceptor> &request_acceptor) {
    request_acceptor->writeMessage("You lose!");
    return true;
}

std::unique_ptr<AbstractMastermindState> LoseState::nextState() {
    return std::make_unique<StartState>();
}
