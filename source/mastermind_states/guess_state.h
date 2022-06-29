#pragma once

#include "../abstract_mastermind_state.h"

class GuessState : public AbstractMastermindState {
public:
    virtual bool exec(std::unique_ptr<AbstractUserRequestAcceptor> &request_acceptor) final;
    virtual std::unique_ptr<AbstractMastermindState> nextState() final;
};
