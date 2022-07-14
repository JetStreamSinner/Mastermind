#pragma once
#include <vector>

enum class EnmColor : int {
    Empty = 0,
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
