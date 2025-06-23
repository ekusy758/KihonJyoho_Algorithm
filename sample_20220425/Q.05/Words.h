#ifndef WORDS_H
#define WORDS_H

#include <string>
#include <vector>

class Words {
  private:
    std::vector<std::string> words_;

  public:
    Words(std::vector<std::string> words) : words_(words) {}

    int freq(std::string str);
    int freqE(std::string str);
};

#endif
