#include "start_state.h"
#include "guess_state.h"
#include "../game_area.h"
#include "../abstract_user_request_acceptor.h"
#include "../guess_checker.h"

bool StartState::exec(std::shared_ptr<GameArea>& area, std::unique_ptr<AbstractUserRequestAcceptor> request_acceptor) {
    const std::size_t suggestions_count = request_acceptor->requestSuggestionsCount();
    const SequenceRow target_row = request_acceptor->requestTargetRow();

    auto guess_checker = std::make_unique<GuessChecker>(target_row);
    area = std::make_shared<GameArea>(suggestions_count, std::move(guess_checker));
    return true;
}

std::unique_ptr<AbstractMastermindState> StartState::nextState() {
    return std::make_unique<GuessState>();
}