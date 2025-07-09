#pragma once
#include <string>
#include <vector>

class Cipher
{
private:
    std::vector<int> parseKey(const std::string &key);
    bool isValidKey(const std::vector<int> &perm, int length);

public:
    std::string encode(const std::string &text, const std::string &key);
    std::string decode(const std::string &text, const std::string &key);
};