#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <iostream>

enum TokenKind
{
    TOKEN_EOF        = -1,
    TOKEN_INT        = -2,
    TOKEN_NUMBER     = -3,
    TOKEN_IDENTIFIER = -4
};

class Token
{
    int kind_;
    int line_;
    int column_;
    std::string file_;

public:
    Token(int kind, int line, int column, std::string file)
        : kind_(kind), line_(line), column_(column), file_(file)
    {
    }

    operator int() const
    {
        return kind_;
    }

    int GetLine() const
    {
        return line_;
    }

    int GetColumn() const
    {
        return column_;
    }

    std::string const &GetFile() const
    {
        return file_;
    }

    // For debug purpose
    virtual void Print() const
    {
        std::cout << "[" << file_ << ":" << line_ << ":" << column_ << " ";
        switch(kind_)
        {
            case TOKEN_EOF:
                std::cout << "EOF";
                break;
            case TOKEN_INT:
                std::cout << "int";
                break;
            case TOKEN_NUMBER:
                std::cout << "NUMBER";
                break;
            case TOKEN_IDENTIFIER:
                std::cout << "IDENTIFIER";
                break;
            default:
                std::cout << (char)kind_;
        }
        std::cout << "]" << std::endl;
    }
};

#endif // TOKEN_H
