//
// Double8.cpp for Double8 in /home/duhame_a/synthese/abstractVM_2016/class
// 
// Made by Josselin Duhamel
// Login   <duhame_a@epitech.net>
// 
// Started on  Fri Jul 21 11:14:42 2017 Josselin Duhamel
// Last update Tue Jul 25 15:02:16 2017 baud
//

#include "Factory.hh"
#include "Double.hpp"
#include "my.hpp"

Double::Double(const std::string &value)
{
  this->_value = my_atod(value);
  if (this->_value > 2147483647)
    throw Exception("Overflow");
  if (this->_value < -2147483648)
    throw Exception("Underflow");
  this->Type = t_Double;
  this->min = -2147483648;
  this->max = 2147483647;
}

Double::~Double()
{
}

std::string             Double::toString() const
{
  std::stringstream     sstream;
  std::string           str;

  sstream << _value;
  sstream >> str;
  return (str);
}

eOperandType    Double::getType() const
{
  return (Type);
}

IOperand                *Double::operator+(const IOperand &rhs) const
{
  double                   nb;
  eOperandType          type;
  std::stringstream     sstream;

  sstream << rhs.toString();
  type = this->Type >= rhs.getType() ? this->Type : rhs.getType();
  sstream >> nb;
  return (Factory::createOperand(type, std::to_string(_value + nb)));
}

IOperand                *Double::operator-(const IOperand &rhs) const
{
  double                nb;
  eOperandType          type;
  std::stringstream     sstream;

  sstream << rhs.toString();
  type = Type >= rhs.getType() ? Type : rhs.getType();
  sstream >> nb;
  return (Factory::createOperand(type, std::to_string(_value - nb)));
}

IOperand                *Double::operator*(const IOperand &rhs) const
{
  double                   nb;
  eOperandType          type;
  std::stringstream     sstream;

  sstream << rhs.toString();
  type = Type >= rhs.getType() ? Type : rhs.getType();
  sstream >> nb;
  return (Factory::createOperand(type, std::to_string(_value * nb)));
}

IOperand                *Double::operator/(const IOperand &rhs) const
{
  double                   nb;
  eOperandType          type;
  std::stringstream     sstream;

  sstream << rhs.toString();
  type = Type >= rhs.getType() ? Type : rhs.getType();
  sstream >> nb;
  if (!nb)
    throw Exception("Division by zero");
  return (Factory::createOperand(type, std::to_string(_value / nb)));
}

IOperand                *Double::operator%(const IOperand &rhs) const
{
  double                nb;
  eOperandType          type;
  std::stringstream     sstream;

  sstream << rhs.toString();
  type = Type >= rhs.getType() ? Type : rhs.getType();
  sstream >> nb;
  if (!nb)
    throw Exception("Modulo by zero");
  return (Factory::createOperand(type, std::to_string(fmod(_value, nb))));
}
