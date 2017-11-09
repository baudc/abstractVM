//
// Int16.hpp for Int16 in /home/duhame_a/synthese/abstractVM_2016
// 
// Made by Josselin Duhamel
// Login   <duhame_a@epitech.net>
// 
// Started on  Fri Jul 21 10:55:39 2017 Josselin Duhamel
// Last update Mon Jul 24 16:22:38 2017 Josselin Duhamel
//

#ifndef DOUBLE_HPP_
# define DOUBLE_HPP_

#include "IOperand.hpp"

class			Double : public IOperand
{
public:
  Double(const std::string &value);
  virtual std::string toString() const;
  virtual eOperandType getType() const;
  virtual ~Double();

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
