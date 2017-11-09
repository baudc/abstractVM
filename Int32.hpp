//
// Int16.hpp for Int16 in /home/duhame_a/synthese/abstractVM_2016
// 
// Made by Josselin Duhamel
// Login   <duhame_a@epitech.net>
// 
// Started on  Fri Jul 21 10:55:39 2017 Josselin Duhamel
// Last update Mon Jul 24 16:16:38 2017 Josselin Duhamel
//

#ifndef INT32_HPP_
# define INT32_HPP_

#include "IOperand.hpp"

class			Int32 : public IOperand
{
public:
  Int32(const std::string &value);
  virtual std::string toString() const;
  virtual eOperandType getType() const;
  virtual ~Int32();

  virtual IOperand        *operator+(const IOperand &rhs) const;
  virtual IOperand        *operator-(const IOperand &rhs) const;
  virtual IOperand        *operator*(const IOperand &rhs) const;
  virtual IOperand        *operator/(const IOperand &rhs) const;
  virtual IOperand        *operator%(const IOperand &rhs) const;

private:
  long			min;
  long			max;
  int			_value;
  enum t_eOperandType	Type;
};

#endif
