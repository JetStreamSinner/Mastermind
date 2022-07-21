#include "mastermind.h"
#include "game_area.h"
#include "guess_checker.h"
#include "interfaces/abstract_input_reader.h"
#include "interfaces/abstract_input_writer.h"
#include "interfaces/abstract_mastermind_state.h"
#include "mastermind_states/start_state.h"

class Mastermind::MastermindImpl {
public:
    explicit MastermindImpl(std::unique_ptr<AbstractInputWriter> writer, std::unique_ptr<AbstractInputReader> reader);
    void nextStep();
    ~MastermindImpl() = default;

private:
    std::unique_ptr<AbstractMastermindState> _current_state;
    std::unique_ptr<AbstractInputWriter> _writer;
    std::unique_ptr<AbstractInputReader> _reader;
    std::shared_ptr<GameArea> _area;
};


Mastermind::MastermindImpl::MastermindImpl(std::unique_ptr<AbstractInputWriter> writer, std::unique_ptr<AbstractInputReader> reader)
    : _current_state(std::make_unique<StartState>()),
      _writer(std::move(writer)),
      _reader(std::move(reader)) {
}

void Mastermind::MastermindImpl::nextStep() {
    bool execution_status = _current_state->exec(_area, _writer, _reader);
    if (execution_status) {
        _current_state = _current_state->nextState();
    }
}


Mastermind::Mastermind(std::unique_ptr<AbstractInputWriter> writer, std::unique_ptr<AbstractInputReader> reader)
    : _impl(std::make_unique<Mastermind::MastermindImpl>(std::move(writer), std::move(reader))) {
}

void Mastermind::nextStep() {
    _impl->nextStep();
}

Mastermind::~Mastermind() = default;
