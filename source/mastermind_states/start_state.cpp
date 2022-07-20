#include "start_state.h"
#include "../game_area.h"
#include "../guess_checker.h"
#include "../interfaces/abstract_user_request_acceptor.h"
#include "guess_state.h"

class StartState::StartStateImpl {
public:
    bool exec(std::shared_ptr<GameArea> &area, const std::unique_ptr<AbstractUserRequestAcceptor> &request_acceptor);
    std::unique_ptr<AbstractMastermindState> nextState();
};

bool StartState::StartStateImpl::exec(std::shared_ptr<GameArea> &area, const std::unique_ptr<AbstractUserRequestAcceptor> &request_acceptor) {
    request_acceptor->writeMessage("Welcome to the game");
    request_acceptor->writeMessage("Write suggestions count");
    const std::size_t suggestions_count = request_acceptor->requestSuggestionsCount();
    request_acceptor->writeMessage("Write target sequence");
    const SequenceRow target_row = request_acceptor->requestTargetRow();

    auto guess_checker = std::make_unique<GuessChecker>(target_row);
    area = std::make_shared<GameArea>(suggestions_count, std::move(guess_checker));
    return true;
}

std::unique_ptr<AbstractMastermindState> StartState::StartStateImpl::nextState() {
    return std::make_unique<GuessState>();
}

StartState::StartState() : _impl(std::make_unique<StartState::StartStateImpl>()) {

}

bool StartState::exec(std::shared_ptr<GameArea> &area, const std::unique_ptr<AbstractUserRequestAcceptor> &request_acceptor) {
    return _impl->exec(area, request_acceptor);
}

std::unique_ptr<AbstractMastermindState> StartState::nextState() {
    return _impl->nextState();
}

StartState::~StartState() = default;
