#pragma once

#include "../abstract_mastermind_state.h"

class WinState : public AbstractMastermindState {
public:
    virtual bool exec(std::shared_ptr<GameArea>& area, std::unique_ptr<AbstractUserRequestAcceptor> request_acceptor) final;
    virtual std::unique_ptr<AbstractMastermindState> nextState() final;
};
