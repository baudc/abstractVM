//
// Exception.hpp for  in /home/baud/0.RENDU/5.SYNTHESE/2.AbstractVM/abstractVM_2016
// 
// Made by baud
// Login   <cesar.baud@epitech.eu>
// 
// Started on  Thu Jul 20 15:37:57 2017 baud
// Last update Wed Jul 26 14:16:28 2017 Kévin Nogué
//

#ifndef _EXCEPTION_H
# define _EXCEPTION_H

# include <exception>
# include <string>

#define SYNTAX_ERROR "Syntax Error"
#define POP_EMPTY_STACK "Pop on empty stack"
#define DUP_EMPTY_STACK "Dup on empty stack"
#define DIVISION_ZERO "Division by zero"
#define MODULO_ZERO "Modulo by zero"
#define MISS_VALUE_STACK "Stack must have more than one element"
#define INCORRECT_FILE "Invalid File"
#define UNKNOWN_REGISTER "Invalid register"
#define NOT_8_BIT "Value isn't 8bit"
#define VAL_NOT_EQUAL "val not equal"

class	Exception : public std::exception
{
public:
  Exception(std::string const&) throw();
  Exception(std::string const&, int line_nb) throw();
  virtual ~Exception() throw();
  virtual const char* what() const throw();
  int	getLine() const throw();
private:
  std::string	_name;
  int		_line;
};

#endif /* _EXCEPTION_H */
