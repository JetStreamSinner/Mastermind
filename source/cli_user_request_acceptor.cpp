#include "cli_user_request_acceptor.h"
#include "utils.h"
#include <iostream>

class CliUserRequestAcceptor::CliUserRequestAcceptorImpl {
public:
    CliUserRequestAcceptorImpl(std::shared_ptr<std::istream> in, std::shared_ptr<std::ostream> out,
                               std::shared_ptr<AbstractTargetGenerateStrategy> target_generation_strategy);
    SequenceRow requestTargetRow() const;
    std::size_t requestSuggestionsCount() const;
    SequenceRow requestGuess() const;
    void writeMessage(const std::string &message) const;

private:
    std::shared_ptr<std::istream> _input_stream;
    std::shared_ptr<std::ostream> _output_stream;
    std::shared_ptr<AbstractTargetGenerateStrategy> _target_generation_strategy;
};

CliUserRequestAcceptor::CliUserRequestAcceptorImpl::CliUserRequestAcceptorImpl(std::shared_ptr<std::istream> in,
                                                                               std::shared_ptr<std::ostream> out,
                                                                               std::shared_ptr<AbstractTargetGenerateStrategy> target_generation_strategy)
    : _input_stream(std::move(in)),
      _output_stream(std::move(out)),
      _target_generation_strategy(std::move(target_generation_strategy)) {}

SequenceRow CliUserRequestAcceptor::CliUserRequestAcceptorImpl::requestTargetRow() const {
    if (!_target_generation_strategy) {
        throw std::runtime_error("Target request strategy is not set");
    }
    return _target_generation_strategy->getTarget();
}

std::size_t CliUserRequestAcceptor::CliUserRequestAcceptorImpl::requestSuggestionsCount() const {
    std::size_t suggestions_count = 0;
    *_input_stream >> suggestions_count;
    return suggestions_count;
}

SequenceRow CliUserRequestAcceptor::CliUserRequestAcceptorImpl::requestGuess() const {
    std::string raw_guess;
    std::getline(*_input_stream, raw_guess);
    return sequenceRowFromString(raw_guess);
}

void CliUserRequestAcceptor::CliUserRequestAcceptorImpl::writeMessage(const std::string &message) const {
    _output_stream->write(message.c_str(), message.size());
    _output_stream->put('\n');
}

CliUserRequestAcceptor::CliUserRequestAcceptor(std::shared_ptr<std::istream> in, std::shared_ptr<std::ostream> out,
                                               std::shared_ptr<AbstractTargetGenerateStrategy> target_generation_strategy)
    : _impl(std::make_unique<CliUserRequestAcceptor::CliUserRequestAcceptorImpl>(std::move(in),
                                                                                 std::move(out),
                                                                                 std::move(target_generation_strategy))) {}

std::size_t CliUserRequestAcceptor::requestSuggestionsCount() const {
    return _impl->requestSuggestionsCount();
}

SequenceRow CliUserRequestAcceptor::requestTargetRow() const {
    return _impl->requestTargetRow();
}

SequenceRow CliUserRequestAcceptor::requestGuess() const {
    return _impl->requestGuess();
}

void CliUserRequestAcceptor::writeMessage(const std::string &message) const {
    _impl->writeMessage(message);
}

CliUserRequestAcceptor::~CliUserRequestAcceptor() = default;
