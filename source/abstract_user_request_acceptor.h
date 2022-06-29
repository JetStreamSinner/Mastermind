#pragma once

#include <string>
#include <vector>

class AbstractUserRequestAcceptor {
public:
    virtual std::vector<int> requestTargetRow() const = 0;
    virtual int requestSuggestionsCount() const = 0;
    virtual int requestGuess() const = 0;
    virtual std::string lastDescriptionResponse() const = 0;
};