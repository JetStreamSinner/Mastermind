#include "win_state.h"
#include "../game_area.h"
#include "../interfaces/abstract_user_request_acceptor.h"
#include "start_state.h"

bool WinState::exec(std::shared_ptr<GameArea> &area, const std::unique_ptr<AbstractUserRequestAcceptor> &request_acceptor) {
    request_acceptor->writeMessage("You won!");
    return true;
}

std::unique_ptr<AbstractMastermindState> WinState::nextState() {
    return std::make_unique<StartState>();
}