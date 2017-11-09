//
// Int16.hpp for Int16 in /home/duhame_a/synthese/abstractVM_2016
// 
// Made by Josselin Duhamel
// Login   <duhame_a@epitech.net>
// 
// Started on  Fri Jul 21 10:55:39 2017 Josselin Duhamel
// Last update Wed Jul 26 15:20:23 2017 baud
//

#ifndef BIGDECIMAL_HPP_
# define BIGDECIMAL_HPP_

#include "IOperand.hpp"

class			BigDecimal : public IOperand
{
public:
  BigDecimal(const std::string &value);
  virtual std::string toString() const;
  virtual eOperandType getType() const;
  virtual ~BigDecimal();

  virtual IOperand        *operator+(const IOperand &rhs) const;
  virtual IOperand        *operator-(const IOperand &rhs) const;
  virtual IOperand        *operator*(const IOperand &rhs) const;
  virtual IOperand        *operator/(const IOperand &rhs) const;
  virtual IOperand        *operator%(const IOperand &rhs) const;

private:
  long double		min;
  long double		max;
  long double		_value;
  enum t_eOperandType	Type;
};

#endif
