class Solution {
public:
    int minMoves(int sx, int sy, int tx, int ty) {
        if (sx == tx && sy == ty) {
            return 0;
        }

        if (sx == 0 && sy == 0) {
            return -1;
        }

        long long current_tx = tx;
        long long current_ty = ty;
        int moves = 0;

        while (current_tx > sx || current_ty > sy) {
            if (current_tx < sx || current_ty < sy) {
                return -1;
            }

            if (current_tx == current_ty) {
                if (current_tx == 0) { 
                    return -1;
                }
                
                if ((sx == 0 && sy == current_ty) || (sy == 0 && sx == current_tx)) {
                    moves++;
                    current_tx = sx; 
                    current_ty = sy; 
                } else if (sx > 0 && sy > 0) {
                    return -1;
                } else if (sx == 0 && sy < current_ty) {
                    moves++;
                    current_tx = sx;
                } else if (sy == 0 && sx < current_tx) {
                    moves++;
                    current_ty = sy;
                } else {
                    return -1;
                }
            } else if (current_tx > current_ty) {
                if (current_tx >= 2 * current_ty) {
                    if (current_tx % 2 != 0) {
                        return -1;
                    }
                    current_tx /= 2;
                } else { 
                    current_tx -= current_ty;
                }
                moves++;
            } else { // current_ty > current_tx
                if (current_ty >= 2 * current_tx) {
                    if (current_ty % 2 != 0) {
                        return -1;
                    }
                    current_ty /= 2;
                } else { 
                    current_ty -= current_tx;
                }
                moves++;
            }
        }

        return (current_tx == sx && current_ty == sy) ? moves : -1;
    }
};