#include "mastermind.h"
#include "abstract_mastermind_state.h"
#include "abstract_user_request_acceptor.h"


Mastermind::Mastermind(std::unique_ptr<AbstractUserRequestAcceptor> &acceptor) : _acceptor(std::move(acceptor)) {

}

void Mastermind::nextStep() {
    bool execution_status = _current_state->exec(_acceptor);
    if (execution_status) {
        _current_state = _current_state->nextState();
    }
}