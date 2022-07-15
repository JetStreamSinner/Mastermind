# Overview
Skeleton for Mastermind game. I got an idea for writing this, when I read
Herb Sutter "Exceptional C++"

# Mastermind
## Rules
Board split on three part:
- First - The target sequence of holes with different colors, which offered by first player;
- Second - Empty holes, which should be filled by guesses of the second player;
- Third - Also empty holes, which show how near second player was to target sequence, when does his guess;

Game process happening in the next way:
First player randomly fill the holes in the first part. After that second player making his guess and fill one row in the second part of field. At the next step first player fill the third part of field using next rule: if second player guess has correct color, than first player put white color, if second player guess have correct color in correct place, than first player put in hole black color. If first player can correctly guess full sequence than second player win, in other case win first player, which offer target sequence.
