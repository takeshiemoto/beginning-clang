//
// Created by Takeshi Emoto on 2023/12/25.
//

int recursively(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n + recursively(n - 1);
    }
}