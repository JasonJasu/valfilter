#ifndef TEXT_UTILS_H
#define TEXT_UTILS_H

#include <string>
#include <vector>

void insertActor(char letter, int repetitions, std::string& result);
void clipboardCopy(const std::wstring& utf16Text);
std::string randomPickChar(const std::vector<std::string>& charVector);
std::wstring utf8to16(const std::string& utf8str);

#endif
