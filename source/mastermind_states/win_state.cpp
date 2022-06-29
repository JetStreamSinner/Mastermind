#include "win_state.h"
#include "../game_area.h"
#include "../abstract_user_request_acceptor.h"
#include "start_state.h"

bool WinState::exec(std::shared_ptr<GameArea>& area, std::unique_ptr<AbstractUserRequestAcceptor> request_acceptor) {
    return true;
}

std::unique_ptr<AbstractMastermindState> WinState::nextState() {
    return std::make_unique<StartState>();
}