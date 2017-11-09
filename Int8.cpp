//
// Int8.cpp for Int8 in /home/duhame_a/synthese/abstractVM_2016/class
// 
// Made by Josselin Duhamel
// Login   <duhame_a@epitech.net>
// 
// Started on  Fri Jul 21 11:14:42 2017 Josselin Duhamel
// Last update Wed Jul 26 15:59:15 2017 baud
//

#include "Exception.hpp"
#include "Factory.hh"
#include "Int8.hpp"
#include "my.hpp"

Int8::Int8(const std::string &value)
{
  this->_value = my_atoi(value);
  if (_value > 127)
        throw Exception("Overflow");
  if (_value < -128)
        throw Exception("underflow");
  this->Type = t_Int8;
  this->min = -128;
  this->max = 127;
}

std::string		Int8::toString() const
{
  std::stringstream	sstream;
  std::string		str;

  sstream << _value;
  sstream >> str;
  return (str);
}

eOperandType	Int8::getType() const
{
  return (Type);
}

IOperand		*Int8::operator+(const IOperand &rhs) const
{
  double			nb;
  eOperandType		type;
  std::stringstream	sstream;

  sstream << rhs.toString();
  type = this->Type >= rhs.getType() ? this->Type : rhs.getType();
  sstream >> nb;
  return (Factory::createOperand(type, std::to_string(_value + nb)));
}

IOperand		*Int8::operator-(const IOperand &rhs) const
{
  double			nb;
  eOperandType		type;
  std::stringstream	sstream;

  sstream << rhs.toString();
  type = Type >= rhs.getType() ? Type : rhs.getType();
  sstream >> nb;
  return (Factory::createOperand(type, std::to_string(_value - nb)));
}

IOperand		*Int8::operator*(const IOperand &rhs) const
{
  double			nb;
  eOperandType		type;
  std::stringstream	sstream;

  sstream << rhs.toString();
  type = Type >= rhs.getType() ? Type : rhs.getType();
  sstream >> nb;
  return (Factory::createOperand(type, std::to_string(_value * nb)));
}

IOperand		*Int8::operator/(const IOperand &rhs) const
{
  double			nb;
  eOperandType		type;
  std::stringstream	sstream;

  sstream << rhs.toString();
  type = Type >= rhs.getType() ? Type : rhs.getType();
  sstream >> nb;
  if (!nb)
    throw Exception("Division by zero");
  return (Factory::createOperand(type, std::to_string(_value / nb)));
}

IOperand		*Int8::operator%(const IOperand &rhs) const
{
  eOperandType		type;
  std::stringstream	sstream;

  sstream << rhs.toString();
  type = Type >= rhs.getType() ? Type : rhs.getType();
  switch (rhs.getType())
    {
    case t_Float:
      {
	float	nb;
      
	sstream >> nb;
	if (!nb)
	  throw Exception("Modulo by zero");
	return (Factory::createOperand(type, std::to_string(fmod((float)_value, nb))));
      }
    case t_Double:
      {
	double	nb;

	sstream >> nb;
	if (!nb)
	  throw Exception("Modulo by zero");
	return (Factory::createOperand(type, std::to_string(fmod((double)_value, nb))));
      }
    default:
      {
	int	nb;

	sstream >> nb;
	if (!nb)
	  throw Exception("Modulo by zero");
	return (Factory::createOperand(type, std::to_string(_value % nb)));
      }
    }  
}
