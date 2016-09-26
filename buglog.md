# BUG LOG

## Found issue in `revealAdjacent`

Reveal adjacent should update the status of the location to `EMPTY_SHOWN` when the location contains `EMPTY_HIDDEN`.
Test 2 concludes that the statis of the location is not updated to `EMPTY_SHOWN` despite the location containing `EMPTY_HIDDEN` prior to calling `revealAdjacent`
I suspect the following line is breaking the code causing the function to immediately return when the location is in bounds:
```cpp
    if( inBounds(col,row) || _map[col][row] == MINE_HIDDEN || _map[col][row] == MINE_SHOWN )
```