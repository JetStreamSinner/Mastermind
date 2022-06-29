#pragma once

#include "../abstract_mastermind_state.h"

class LoseState : public AbstractMastermindState {
public:
    bool exec(std::shared_ptr<GameArea>& area, const std::unique_ptr<AbstractUserRequestAcceptor>& request_acceptor) final;
    std::unique_ptr<AbstractMastermindState> nextState() final;
};
