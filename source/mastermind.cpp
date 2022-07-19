#include "mastermind.h"
#include "game_area.h"
#include "guess_checker.h"
#include "interfaces/abstract_mastermind_state.h"
#include "interfaces/abstract_user_request_acceptor.h"
#include "mastermind_states/start_state.h"

class Mastermind::MastermindImpl {
public:
    explicit MastermindImpl(std::unique_ptr<AbstractUserRequestAcceptor> &acceptor);
    void nextStep();
    ~MastermindImpl() = default;
private:
    std::unique_ptr<AbstractMastermindState> _current_state;
    std::unique_ptr<AbstractUserRequestAcceptor> _acceptor;
    std::shared_ptr<GameArea> _area;
};


Mastermind::MastermindImpl::MastermindImpl(std::unique_ptr<AbstractUserRequestAcceptor> &acceptor) : _current_state(std::make_unique<StartState>()),
                                                                                                     _acceptor(std::move(acceptor)) {
}

void Mastermind::MastermindImpl::nextStep() {
    bool execution_status = _current_state->exec(_area, _acceptor);
    if (execution_status) {
        _current_state = _current_state->nextState();
    }
}


Mastermind::Mastermind(std::unique_ptr<AbstractUserRequestAcceptor> acceptor) : _impl(std::make_unique<Mastermind::MastermindImpl>(acceptor)){
}

void Mastermind::nextStep() {
    _impl->nextStep();
}

Mastermind::~Mastermind() = default;
