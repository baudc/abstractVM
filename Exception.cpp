//
// Exception.cpp for  in /home/baud/0.RENDU/5.SYNTHESE/2.AbstractVM/abstractVM_2016
// 
// Made by baud
// Login   <cesar.baud@epitech.eu>
// 
// Started on  Thu Jul 20 15:46:37 2017 baud
// Last update Wed Jul 26 14:16:45 2017 Kévin Nogué
//

#include "Exception.hpp"

Exception::Exception(std::string const& name) throw()
  : _name(name), _line(-1)
{
}

Exception::Exception(std::string const& name, int line) throw()
  : _name(name), _line(line)
{
}

Exception::~Exception() throw() {}

const char	*Exception::what() const throw()
{
  return (_name.c_str());
}

int		Exception::getLine() const throw()
{
  return (_line);
}
