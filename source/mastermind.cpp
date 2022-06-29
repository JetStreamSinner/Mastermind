#include "mastermind.h"
#include "abstract_mastermind_state.h"
#include "abstract_user_request_acceptor.h"
#include "game_area.h"
#include "guess_checker.h"
#include "mastermind_states/start_state.h"


Mastermind::Mastermind(std::unique_ptr<AbstractUserRequestAcceptor> &acceptor) : _current_state(std::make_unique<StartState>()),
                                                                                 _acceptor(std::move(acceptor)) {
}

void Mastermind::nextStep() {
    bool execution_status = _current_state->exec(_area, _acceptor);
    if (execution_status) {
        _current_state = _current_state->nextState();
    }
}