#include "lose_state.h"
#include "../game_area.h"
#include "../interfaces/abstract_user_request_acceptor.h"
#include "start_state.h"

class LoseState::LoseStateImpl {
public:
    bool exec(std::shared_ptr<GameArea> &area, const std::unique_ptr<AbstractUserRequestAcceptor> &request_acceptor);
    std::unique_ptr<AbstractMastermindState> nextState();
};

bool LoseState::LoseStateImpl::exec(std::shared_ptr<GameArea> &area, const std::unique_ptr<AbstractUserRequestAcceptor> &request_acceptor) {
    request_acceptor->writeMessage("You lose!");
    return true;
}

std::unique_ptr<AbstractMastermindState> LoseState::LoseStateImpl::nextState() {
    return std::make_unique<StartState>();
}

LoseState::LoseState() : _impl(std::make_unique<LoseState::LoseStateImpl>()) {

}

bool LoseState::exec(std::shared_ptr<GameArea> &area, const std::unique_ptr<AbstractUserRequestAcceptor> &request_acceptor) {
    return _impl->exec(area, request_acceptor);
}

std::unique_ptr<AbstractMastermindState> LoseState::nextState() {
    return _impl->nextState();
}

LoseState::~LoseState() = default;
