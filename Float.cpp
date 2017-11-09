//
// Int8.cpp for Int8 in /home/duhame_a/synthese/abstractVM_2016/class
// 
// Made by Josselin Duhamel
// Login   <duhame_a@epitech.net>
// 
// Started on  Fri Jul 21 11:14:42 2017 Josselin Duhamel
// Last update Tue Jul 25 15:15:14 2017 baud
//

#include "Factory.hh"
#include "Float.hpp"
#include "my.hpp"

Float::Float(const std::string &value)
{
  this->_value = my_atof(value);
  if (this->_value > 32767)
        throw Exception("Overflow");
  if (this->_value < -32768)
        throw Exception("Underflow");
  this->Type = t_Float;
  this->min = -32768;
  this->max = 32767;
}

Float::~Float()
{
}

std::string             Float::toString() const
{
  std::stringstream     sstream;
  std::string           str;

  sstream << _value;
  sstream >> str;
  return (str);
}

eOperandType    Float::getType() const
{
  return (Type);
}

IOperand                *Float::operator+(const IOperand &rhs) const
{
  float                   nb;
  eOperandType          type;
  std::stringstream     sstream;

  sstream << rhs.toString();
  type = this->Type >= rhs.getType() ? this->Type : rhs.getType();
  sstream >> nb;
  return (Factory::createOperand(type, std::to_string(_value + nb)));
}

IOperand                *Float::operator-(const IOperand &rhs) const
{
  float                   nb;
  eOperandType          type;
  std::stringstream     sstream;

  sstream << rhs.toString();
  type = Type >= rhs.getType() ? Type : rhs.getType();
  sstream >> nb;
  return (Factory::createOperand(type, std::to_string(_value - nb)));
}

IOperand                *Float::operator*(const IOperand &rhs) const
{
  float                   nb;
  eOperandType          type;
  std::stringstream     sstream;

  sstream << rhs.toString();
  type = Type >= rhs.getType() ? Type : rhs.getType();
  sstream >> nb;
  return (Factory::createOperand(type, std::to_string(_value * nb)));
}

IOperand                *Float::operator/(const IOperand &rhs) const
{
  float                   nb;
  eOperandType          type;
  std::stringstream     sstream;

  sstream << rhs.toString();
  type = Type >= rhs.getType() ? Type : rhs.getType();
  sstream >> nb;
  if (!nb)
    throw Exception("Division by zero");
  return (Factory::createOperand(type, std::to_string(_value / nb)));
}

IOperand                *Float::operator%(const IOperand &rhs) const
{
  float                   nb;
  eOperandType          type;
  std::stringstream     sstream;

  sstream << rhs.toString();
  type = Type >= rhs.getType() ? Type : rhs.getType();
  sstream >> nb;
  if (!nb)
    throw Exception("Modulo by zero");
  return (Factory::createOperand(type, std::to_string(fmod(_value, nb))));
}
