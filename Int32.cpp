//
// Int8.cpp for Int8 in /home/duhame_a/synthese/abstractVM_2016/class
// 
// Made by Josselin Duhamel
// Login   <duhame_a@epitech.net>
// 
// Started on  Fri Jul 21 11:14:42 2017 Josselin Duhamel
// Last update Tue Jul 25 16:54:36 2017 Kévin Nogué
//

#include "Factory.hh"
#include "Int32.hpp"
#include "my.hpp"

Int32::Int32(const std::string &value)
{
  this->_value = my_atoi(value);
  if (this->_value > 2147483647)
    throw Exception("Overflow");
  if (this->_value < -2147483648)
    throw Exception("Underflow");
  this->Type = t_Int32;
  this->min = -2147483648;
  this->max = 2147483647;
}

Int32::~Int32()
{
}

std::string             Int32::toString() const
{
  std::stringstream     sstream;
  std::string           str;

  sstream << _value;
  sstream >> str;
  return (str);
}

eOperandType    Int32::getType() const
{
  return (Type);
}

IOperand                *Int32::operator+(const IOperand &rhs) const
{
  double                nb;
  eOperandType          type;
  std::stringstream     sstream;

  sstream << rhs.toString();
  type = this->Type >= rhs.getType() ? this->Type : rhs.getType();
  sstream >> nb;
  return (Factory::createOperand(type, std::to_string(_value + nb)));
}

IOperand                *Int32::operator-(const IOperand &rhs) const
{
  double		nb;
  eOperandType          type;
  std::stringstream     sstream;

  sstream << rhs.toString();
  type = Type >= rhs.getType() ? Type : rhs.getType();
  sstream >> nb;
  return (Factory::createOperand(type, std::to_string(_value - nb)));
}

IOperand                *Int32::operator*(const IOperand &rhs) const
{
  double                nb;
  eOperandType          type;
  std::stringstream     sstream;
  
  sstream << rhs.toString();
  type = Type >= rhs.getType() ? Type : rhs.getType();
  sstream >> nb;
  return (Factory::createOperand(type, std::to_string(_value * nb)));
}

IOperand                *Int32::operator/(const IOperand &rhs) const
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

IOperand                *Int32::operator%(const IOperand &rhs) const
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
