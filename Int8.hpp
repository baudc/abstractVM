//
// Int8.hh for  in /home/nogue_k/Rendu/S4/synt/vm
// 
// Made by nogue_k
// Login   <nogue_k@epitech.net>
// 
// Started on  Thu Jul 20 22:03:14 2017 Kévin Nogué
// Last update Mon Jul 24 17:01:28 2017 baud
//

#ifndef INT8_HPP_
# define INT8_HPP_

#include "IOperand.hpp"

class			Int8 : public IOperand
{
public:
  Int8(const std::string &value);
  virtual std::string toString() const;
  virtual eOperandType getType() const;
  virtual ~Int8() {};

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
