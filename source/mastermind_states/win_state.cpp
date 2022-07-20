#include "win_state.h"
#include "../game_area.h"
#include "../interfaces/abstract_user_request_acceptor.h"
#include "start_state.h"

class WinState::WinStateImpl {
public:
    bool exec(std::shared_ptr<GameArea> &area, const std::unique_ptr<AbstractUserRequestAcceptor> &request_acceptor);
    std::unique_ptr<AbstractMastermindState> nextState();
};

bool WinState::WinStateImpl::exec(std::shared_ptr<GameArea> &area, const std::unique_ptr<AbstractUserRequestAcceptor> &request_acceptor) {
    request_acceptor->writeMessage("You won!");
    return true;
}

std::unique_ptr<AbstractMastermindState> WinState::WinStateImpl::nextState() {
    return std::make_unique<StartState>();
}

WinState::WinState() : _impl(std::make_unique<WinState::WinStateImpl>()) {
}

bool WinState::exec(std::shared_ptr<GameArea> &area, const std::unique_ptr<AbstractUserRequestAcceptor> &request_acceptor) {
    return _impl->exec(area, request_acceptor);
}

std::unique_ptr<AbstractMastermindState> WinState::nextState() {
    return _impl->nextState();
}

WinState::~WinState() = default;
