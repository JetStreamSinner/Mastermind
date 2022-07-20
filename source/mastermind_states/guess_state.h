#pragma once

#include "../interfaces/abstract_mastermind_state.h"

class GuessState : public AbstractMastermindState {
public:
    explicit GuessState();
    bool exec(std::shared_ptr<GameArea> &area, const std::unique_ptr<AbstractUserRequestAcceptor> &request_acceptor) final;
    std::unique_ptr<AbstractMastermindState> nextState() final;
    ~GuessState() override;

private:
    class GuessStateImpl;
    std::unique_ptr<GuessStateImpl> _impl;
};
