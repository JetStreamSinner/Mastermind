#include "guess_checker.h"
#include <algorithm>
#include <random>
#include <unordered_set>

GuessChecker::GuessChecker(const SequenceRow &target_row) : _target_row(target_row) {
}

SequenceRow GuessChecker::makeHintRow(const SequenceRow &guess_row) const {
    SequenceRow hint;
    auto guess_forwarder = guess_row.begin();
    std::unordered_set<Color> colors_hash(_target_row.begin(), _target_row.end());

    std::for_each(_target_row.begin(), _target_row.end(), [&guess_forwarder, &hint, &colors_hash](auto base_item) {

        const Color white_color = Color::White;
        const Color black_color = Color::Black;

        if (base_item == *guess_forwarder) {
            hint.push_back(black_color);
        } else if (colors_hash.find(*guess_forwarder) != colors_hash.end()) {
            hint.push_back(white_color);
        }
        guess_forwarder = std::next(guess_forwarder);
    });

    std::random_device device;
    std::mt19937 generator(device());

    std::shuffle(hint.begin(), hint.end(), generator);
    return hint;
}

bool GuessChecker::guessValid(const SequenceRow &guess_row) const {
    return guess_row == _target_row;
}