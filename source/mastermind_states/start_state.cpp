#include "start_state.h"
#include "guess_state.h"

bool StartState::exec(std::unique_ptr<AbstractUserRequestAcceptor> &request_acceptor) {

}

std::unique_ptr<AbstractMastermindState> StartState::nextState() {
    return std::make_unique<GuessState>();
}