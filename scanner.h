// Thomas Cholak

#ifndef SCANNER_H
#define SCANNER_H

struct Token  // used for storing a token as a triplet
{
    std::string tokenID, tokenInstance;
    int line_num
            {
            };
};

void scanner(std::ifstream& inputFile);

#endif
