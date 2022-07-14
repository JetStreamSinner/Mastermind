#include "guess_checker.h"
#include <algorithm>
#include <random>
#include <unordered_set>

GuessChecker::GuessChecker(const SequenceRow &target_row) : _target_row(target_row) {
}

SequenceRow GuessChecker::makeHintRow(const SequenceRow &guess_row) const {
    SequenceRow hint;
    auto forwarder = guess_row.begin();
    std::unordered_set<Color> colors_hash;
    std::for_each(_target_row.begin(), _target_row.end(), [&forwarder, &hint, &colors_hash](auto item) {

        const Color white_color = Color::White;
        const Color black_color = Color::Black;

        if (item == *forwarder) {
            hint.push_back(white_color);
            colors_hash.insert(*forwarder);
        } else {
            hint.push_back(black_color);
        }
    });

    std::random_device device;
    std::mt19937 generator(device());

    std::shuffle(hint.begin(), hint.end(), generator);
    return hint;
}

bool GuessChecker::guessValid(const SequenceRow &guess_row) const {
    return guess_row == _target_row;
}