#include <iostream>
#include "ahoKorasik.h"

using namespace std;

int main() {
    string s = "bca ";
    AhoKorasik *g = new AhoKorasik(s);
    string line;
    cin >> line;
    g->algorithmRealization(line);
}
