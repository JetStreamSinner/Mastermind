#pragma once

#include <memory>
class AbstractUserRequestAcceptor;
class GameArea;

class AbstractMastermindState {
public:
    virtual bool exec(std::shared_ptr<GameArea>& area, const std::unique_ptr<AbstractUserRequestAcceptor>& request_acceptor) = 0;
    virtual std::unique_ptr<AbstractMastermindState> nextState() = 0;
};
