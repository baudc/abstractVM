//
// Int16.hpp for Int16 in /home/duhame_a/synthese/abstractVM_2016
// 
// Made by Josselin Duhamel
// Login   <duhame_a@epitech.net>
// 
// Started on  Fri Jul 21 10:55:39 2017 Josselin Duhamel
// Last update Mon Jul 24 16:19:37 2017 Josselin Duhamel
//

#ifndef FLOAT_HPP_
# define FLOAT_HPP_

#include "IOperand.hpp"

class			Float : public IOperand
{
public:
  Float(const std::string &value);
  virtual std::string toString() const;
  virtual eOperandType getType() const;
  virtual ~Float();

  virtual IOperand        *operator+(const IOperand &rhs) const;
  virtual IOperand        *operator-(const IOperand &rhs) const;
  virtual IOperand        *operator*(const IOperand &rhs) const;
  virtual IOperand        *operator/(const IOperand &rhs) const;
  virtual IOperand        *operator%(const IOperand &rhs) const;

private:
  double		min;
  double		max;
  float			_value;
  enum t_eOperandType	Type;
};

#endif
