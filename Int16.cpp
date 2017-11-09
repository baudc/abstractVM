//
// Int8.cpp for Int8 in /home/duhame_a/synthese/abstractVM_2016/class
// 
// Made by Josselin Duhamel
// Login   <duhame_a@epitech.net>
// 
// Started on  Fri Jul 21 11:14:42 2017 Josselin Duhamel
// Last update Tue Jul 25 16:55:51 2017 Kévin Nogué
//

#include "Factory.hh"
#include "Int16.hpp"
#include "my.hpp"

Int16::Int16(const std::string &value)
{
  this->_value = my_atoi(value);
  this->Type = t_Int16;
  this->min = -32768;
  this->max = 32767;
  
  // long	res;
  // res = my_atol(res);
  // if (res > 32767)
  //       throw Exception("Overflow");
  // if (res < -32768)
  //       throw Exception("underflow");
}

Int16::~Int16()
{
}

std::string             Int16::toString() const
{
  std::stringstream     sstream;
  std::string           str;

  sstream << _value;
  sstream >> str;
  return (str);
}

eOperandType    Int16::getType() const
{
  return (Type);
}


IOperand                *Int16::operator+(const IOperand &rhs) const
{
  double		nb;
  eOperandType          type;
  std::stringstream     sstream;

  sstream << rhs.toString();
  type = this->Type >= rhs.getType() ? this->Type : rhs.getType();
  sstream >> nb;
  return (Factory::createOperand(type, std::to_string(_value + nb)));
}

IOperand                *Int16::operator-(const IOperand &rhs) const
{
  double		nb;
  eOperandType          type;
  std::stringstream     sstream;

  sstream << rhs.toString();
  type = Type >= rhs.getType() ? Type : rhs.getType();
  sstream >> nb;
  return (Factory::createOperand(type, std::to_string(_value - nb)));
}

IOperand                *Int16::operator*(const IOperand &rhs) const
{
  double		nb;
  eOperandType          type;
  std::stringstream     sstream;

  sstream << rhs.toString();
  type = Type >= rhs.getType() ? Type : rhs.getType();
  sstream >> nb;
  return (Factory::createOperand(type, std::to_string(_value * nb)));
}

IOperand                *Int16::operator/(const IOperand &rhs) const
{
  double		nb;
  eOperandType          type;
  std::stringstream     sstream;

  sstream << rhs.toString();
  type = Type >= rhs.getType() ? Type : rhs.getType();
  sstream >> nb;
  if (!nb)
    throw Exception("Division by zero");
  return (Factory::createOperand(type, std::to_string(_value / nb)));
}

IOperand                *Int16::operator%(const IOperand &rhs) const
{
  double		nb;
  eOperandType          type;
  std::stringstream     sstream;

  sstream << rhs.toString();
  type = Type >= rhs.getType() ? Type : rhs.getType();
  sstream >> nb;
  if (!nb)
    throw Exception("Modulo by zero");
  return (Factory::createOperand(type, std::to_string(fmod(_value, nb))));
}
