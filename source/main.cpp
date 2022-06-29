#include <iostream>
#include "mastermind.h"
#include "abstract_mastermind_state.h"
#include "cli_user_request_acceptor.h"

int main(int argc, char * argv[])
{
    std::shared_ptr<std::istream> is = std::shared_ptr<std::istream>(&std::cin, [](std::istream * is) {

    });
    std::shared_ptr<std::ostream> out = std::shared_ptr<std::ostream>(&std::cout, [](std::ostream * os) {

    });

    std::unique_ptr<AbstractUserRequestAcceptor> acceptor = std::make_unique<CliUserRequestAcceptor>(is, out);
    Mastermind mastermind(acceptor);
    mastermind.nextStep();
    return 0;
}