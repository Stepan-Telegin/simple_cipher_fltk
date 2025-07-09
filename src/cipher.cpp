#include "inc/cipher.hpp"

std::vector<int> Cipher::parseKey(const std::string &key)
{
    std::vector<int> perm;
    int num = 0;
    bool in_number = false;
    for (size_t i = 0; i < key.length(); ++i)
    {
        char c = key[i];
        if (c >= '0' && c <= '9')
        {
            num = num * 10 + (c - '0');
            in_number = true;
        }
        else if (in_number)
        {
            perm.push_back(num - 1);
            num = 0;
            in_number = false;
        }
    }
    if (in_number)
        perm.push_back(num - 1);
    return perm;
}

bool Cipher::isValidKey(const std::vector<int> &perm, int length)
{
    if (perm.size() != static_cast<size_t>(length))
        return false;
    std::vector<bool> used(length, false);
    for (int i : perm)
    {
        if (i < 0 || i >= length || used[i])
            return false;
        used[i] = true;
    }
    return true;
}

std::string Cipher::encode(const std::string &text, const std::string &key)
{
    if (text.empty())
        return "";
    int charCount = static_cast<int>(text.length());
    std::vector<int> perm = parseKey(key);
    if (!isValidKey(perm, charCount))
    {
        return "ERROR";
    }
    std::string result = text;
    for (int i = 0; i < charCount; i++)
    {
        result[i] = text[perm[i]];
    }
    return result;
}

std::string Cipher::decode(const std::string &text, const std::string &key)
{
    if (text.empty())
        return "";
    int charCount = static_cast<int>(text.length());
    std::vector<int> perm = parseKey(key);
    if (!isValidKey(perm, charCount))
    {
        return "ERROR";
    }
    std::vector<int> inverse_perm(perm.size());
    for (size_t i = 0; i < perm.size(); i++)
    {
        inverse_perm[perm[i]] = static_cast<int>(i);
    }
    std::string result = text;
    for (int i = 0; i < charCount; i++)
    {
        result[i] = text[inverse_perm[i]];
    }
    return result;
}