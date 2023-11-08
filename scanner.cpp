// Thomas Cholak

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <vector>
#include <iomanip>
#include "scanner.h"  // header file "scanner.h"

void scanner(std::ifstream& inputFile) {
    // keywords array: https://www.thecrazyprogrammer.com/2017/02/lexical-analyzer-in-c.html
    char keywords[32][10] =
            {"auto", "break", "case", "char", "const", "continue", "default",
             "do", "double", "else", "enum", "extern", "float", "for", "goto",
             "if", "int", "long", "register", "return", "short", "signed",
             "sizeof", "static", "struct", "switch", "typedef", "union",
             "unsigned", "void", "volatile", "while"
            };

    std::string line;
    int line_number = 0;
    bool test = false;
    bool inside_comment = false;

    std::vector<Token> tokens; // creates a token vector for storing tokens which are created

    while (std::getline(inputFile, line)) {
        line_number++;

        // loops through file character by character
        for (auto cursor = line.begin(); cursor != line.end(); ++cursor) {

            if (!inside_comment && *cursor == '/' && cursor + 1 != line.end() && *(cursor + 1) == '/') {
                break;  // skips single-line comment
            } else if (!inside_comment && *cursor== '/' && *(cursor + 1) == '*' && cursor + 1 != line.end()) {
                inside_comment = true;
                cursor++;
            } else if (inside_comment && *cursor == '*' && *(cursor + 1) == '/' && cursor + 1 != line.end()) {
                inside_comment = false;
                cursor++;
            } else if (inside_comment) {
                continue;
            }

            // skips whitespace
            if (std::isspace(*cursor)) {
                continue;
            }

            Token token; // used for pushing to triplet

            // checks alphabetic characters for if a keyword is present
            if (std::isalpha(*cursor)) {
                auto start = cursor;
                while (cursor != line.end() && std::isalpha(*cursor))
                    // checks for if it's the end of the line and a letter and continues parsing if true
                {
                    ++cursor;
                }

                // vector to store string in case cursor's selection is a keyword
                std::string keyword_check(start, cursor);

                bool isKeyword = false;
                for (auto &keyword: keywords) {
                    if (std::strcmp(keyword_check.c_str(), keyword) == 0) // looks for keywords
                    {
                        isKeyword = true;
                        break;
                    }
                }

                if (isKeyword) {
                    token.tokenID = "KEYWORD";
                    token.tokenInstance = keyword_check;
                    token.line_num = line_number;
                } else {
                    token.tokenID = "IDENTIFIER";
                    token.tokenInstance = keyword_check;
                    token.line_num = line_number;
                }

                --cursor; // moves the cursor back one step after checking the keyword

            } else if (*cursor == '=') {
                token.tokenID = "EQUALS";
                token.tokenInstance = *cursor;
                token.line_num = line_number;
            } else if (*cursor == '<') {
                token.tokenID = "LESS_THAN";
                token.tokenInstance = *cursor;
                token.line_num = line_number;
            } else if (*cursor == '>') {
                token.tokenID = "GREATER_THAN";
                token.tokenInstance = *cursor;
                token.line_num = line_number;
            } else if (*cursor == ':') {
                token.tokenID = "COLON";
                token.tokenInstance = *cursor;
                token.line_num = line_number;
            } else if (*cursor == '+') {
                token.tokenID = "PLUS";
                token.tokenInstance = *cursor;
                token.line_num = line_number;
            } else if (*cursor == '*') {
                token.tokenID = "MULTIPLY";
                token.tokenInstance = *cursor;
                token.line_num = line_number;
            } else if (*cursor == '/') {
                token.tokenID = "DIVIDE";
                token.tokenInstance = *cursor;
                token.line_num = line_number;
            } else if (*cursor == '%') {
                token.tokenID = "MOD";
                token.tokenInstance = *cursor;
                token.line_num = line_number;
            } else if (*cursor == '.') {
                token.tokenID = "DOT";
                token.tokenInstance = *cursor;
                token.line_num = line_number;
            } else if (*cursor == '(') {
                token.tokenID = "L_PAREN";
                token.tokenInstance = *cursor;
                token.line_num = line_number;
            } else if (*cursor == ')') {
                token.tokenID = "R_PAREN";
                token.tokenInstance = *cursor;
                token.line_num = line_number;
            } else if (*cursor == ',') {
                token.tokenID = "COMMA";
                token.tokenInstance = *cursor;
                token.line_num = line_number;
            } else if (*cursor == '{') {
                token.tokenID = "L_BRACE";
                token.tokenInstance = *cursor;
                token.line_num = line_number;
            } else if (*cursor == '}') {
                token.tokenID = "R_BRACE";
                token.tokenInstance = *cursor;
                token.line_num = line_number;
            } else if (*cursor == ';') {
                token.tokenID = "SEMI-COLON";
                token.tokenInstance = *cursor;
                token.line_num = line_number;
            } else if (*cursor == '0' || *cursor == '1' || *cursor == '2' || *cursor == '3' || *cursor == '4' ||
                       *cursor == '5' || *cursor == '6' || *cursor == '7' || *cursor == '8' || *cursor == '9') {
                token.tokenID = "NUM";
                token.tokenInstance = *cursor;
                token.line_num = line_number;
            } else {
                token.tokenID = "OTHER";
                token.tokenInstance = *cursor;
                token.line_num = line_number;
            }

            tokens.push_back(token);  // pushes to token struct

        }
    }

    std::cout << std::left << std::setw(15) << "TokenID"
              << std::setw(15) << "TokenInstance"
              << std::setw(1) << "Line#" <<
              "\n---------------------------------------" << std::endl;

    // printing tokens formatting
    for (const auto &token: tokens) {
        std::cout << std::left << std::setw(15) << token.tokenID
                  << std::setw(15) << token.tokenInstance
                  << std::right << token.line_num << std::endl;
    }

    // creates the EOFtk token (end-of-file token)
    Token EOF_Token;
    EOF_Token.tokenID = "EOFtk";
    EOF_Token.tokenInstance = "EOFtk";
    EOF_Token.line_num = line_number + 1;

    //prints the EOFtk token
    std::cout << std::left << std::setw(15) << EOF_Token.tokenID
              << std::setw(15) << EOF_Token.tokenInstance
              << std::right << EOF_Token.line_num << std::endl;
}
