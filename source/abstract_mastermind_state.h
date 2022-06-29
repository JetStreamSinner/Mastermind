#pragma once

#include "abstract_user_request_acceptor.h"
#include <memory>

class AbstractMastermindState {
public:
    virtual bool exec(std::unique_ptr<AbstractUserRequestAcceptor>& request_acceptor) = 0;
    virtual std::unique_ptr<AbstractMastermindState> nextState() = 0;
    virtual ~AbstractMastermindState() = default;
};
