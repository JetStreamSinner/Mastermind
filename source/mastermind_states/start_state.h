#pragma once

#include "../interfaces/abstract_mastermind_state.h"

class StartState : public AbstractMastermindState {
public:
    explicit StartState();
    bool exec(std::shared_ptr<GameArea> &area, const std::unique_ptr<AbstractUserRequestAcceptor> &request_acceptor) final;
    std::unique_ptr<AbstractMastermindState> nextState() final;
    ~StartState();
private:
    class StartStateImpl;
    std::unique_ptr<StartStateImpl> _impl;
};
