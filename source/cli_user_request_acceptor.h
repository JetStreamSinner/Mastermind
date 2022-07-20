#pragma once

#include "interfaces/abstract_target_generate_strategy.h"
#include "interfaces/abstract_user_request_acceptor.h"
#include <memory>

class CliUserRequestAcceptor : public AbstractUserRequestAcceptor {
public:
    CliUserRequestAcceptor(std::shared_ptr<std::istream> in, std::shared_ptr<std::ostream> out,
                           std::shared_ptr<AbstractTargetGenerateStrategy> target_generation_strategy);
    SequenceRow requestTargetRow() const final;
    std::size_t requestSuggestionsCount() const final;
    SequenceRow requestGuess() const final;
    void writeMessage(const std::string &message) const final;
    ~CliUserRequestAcceptor() override;

private:
    class CliUserRequestAcceptorImpl;
    std::unique_ptr<CliUserRequestAcceptorImpl> _impl;
};