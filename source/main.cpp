#include "abstract_mastermind_state.h"
#include "cli_user_request_acceptor.h"
#include "user_input_target_generate_strategy.h"
#include "mastermind.h"
#include <iostream>

int main(int argc, char *argv[]) {
    std::shared_ptr<std::istream> is = std::shared_ptr<std::istream>(&std::cin, [](std::istream *is) {

    });
    std::shared_ptr<std::ostream> out = std::shared_ptr<std::ostream>(&std::cout, [](std::ostream *os) {

    });

    std::shared_ptr<AbstractTargetGenerateStrategy> generation_strategy = std::make_shared<UserInputTargetGenerateStrategy>(is);

    std::unique_ptr<AbstractUserRequestAcceptor> acceptor = std::make_unique<CliUserRequestAcceptor>(is, out, generation_strategy);
    Mastermind mastermind(std::move(acceptor));
    while (true) {
        mastermind.nextStep();
    }
    return 0;
}