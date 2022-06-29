#pragma once
#include <vector>

enum class EnmColor {
    Red,
    Green,
    Yellow,
    Purple,
    Blue,
    Brown,
    White,
    Black
};

using Color = EnmColor;
using SequenceRow = std::vector<Color>;
