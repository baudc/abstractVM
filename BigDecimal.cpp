//
// BigDecimal8.cpp for BigDecimal8 in /home/duhame_a/synthese/abstractVM_2016/class
// 
// Made by Josselin Duhamel
// Login   <duhame_a@epitech.net>
// 
// Started on  Fri Jul 21 11:14:42 2017 Josselin Duhamel
// Last update Wed Jul 26 10:57:10 2017 baud
//

#include "Factory.hh"
#include "BigDecimal.hpp"
#include "my.hpp"

BigDecimal::BigDecimal(const std::string &value)
{
  this->_value = my_atod(value);
  if (this->_value > 2147483647)
    throw Exception("Overflow");
  if (this->_value < -2147483648)
    throw Exception("Underflow");
  this->Type = t_BigDecimal;
  this->min = -2147483648;
  this->max = 2147483647;
}

BigDecimal::~BigDecimal()
{
}

std::string             BigDecimal::toString() const
{
  std::stringstream     sstream;
  std::string           str;

  sstream << _value;
  sstream >> str;
  return (str);
}

eOperandType    BigDecimal::getType() const
{
  return (Type);
}

IOperand                *BigDecimal::operator+(const IOperand &rhs) const
{
  long double           nb;
  eOperandType          type;
  std::stringstream     sstream;

  sstream << rhs.toString();
  type = this->Type >= rhs.getType() ? this->Type : rhs.getType();
  sstream >> nb;
  return (Factory::createOperand(type, std::to_string(_value + nb)));
}

IOperand                *BigDecimal::operator-(const IOperand &rhs) const
{
  long double           nb;
  eOperandType          type;
  std::stringstream     sstream;

  sstream << rhs.toString();
  type = Type >= rhs.getType() ? Type : rhs.getType();
  sstream >> nb;
  return (Factory::createOperand(type, std::to_string(_value - nb)));
}

IOperand                *BigDecimal::operator*(const IOperand &rhs) const
{
  long double           nb;
  eOperandType          type;
  std::stringstream     sstream;

  sstream << rhs.toString();
  type = Type >= rhs.getType() ? Type : rhs.getType();
  sstream >> nb;
  return (Factory::createOperand(type, std::to_string(_value * nb)));
}

IOperand                *BigDecimal::operator/(const IOperand &rhs) const
{
  long double           nb;
  eOperandType          type;
  std::stringstream     sstream;

  sstream << rhs.toString();
  type = Type >= rhs.getType() ? Type : rhs.getType();
  sstream >> nb;
  if (!nb)
    throw Exception("Division by zero");
  return (Factory::createOperand(type, std::to_string(_value / nb)));
}

IOperand                *BigDecimal::operator%(const IOperand &rhs) const
{
  long double           nb;
  eOperandType          type;
  std::stringstream     sstream;

  sstream << rhs.toString();
  type = Type >= rhs.getType() ? Type : rhs.getType();
  sstream >> nb;
  if (!nb)
    throw Exception("Modulo by zero");
  return (Factory::createOperand(type, std::to_string(fmod(_value, nb))));
}
