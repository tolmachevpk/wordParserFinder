#ifndef WORDPARSERFINDER_AHOKORASIK_H
#define WORDPARSERFINDER_AHOKORASIK_H
#include "trie.h"

class AhoKorasik : private MakeTrie {
public:
    explicit AhoKorasik(const std::string& s) : MakeTrie(s) {}
    void algorithmRealization(const std::string &word);
private:
    Trie* sufLink(Trie* node);
    Trie* goTo(Trie* node, char a);
    void out(Trie* node);
    Trie* termLink(Trie* node);
};

#endif // WORDPARSERFINDER_AHOKORASIK_H