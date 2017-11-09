//
// my_atoi.cpp for  in /home/baud/0.RENDU/5.SYNTHESE/2.AbstractVM/abstractVM_2016/baud
// 
// Made by baud
// Login   <cesar.baud@epitech.eu>
// 
// Started on  Fri Jul 21 14:29:56 2017 baud
// Last update Mon Jul 24 16:03:37 2017 Josselin Duhamel
//

#include <sstream>

int			my_atoi(std::string str)
{
  int			nb;
  std::stringstream	sstream;

  sstream << str;
  sstream >> nb;
  return (nb);
}

long			my_atol(std::string str)
{
  long			nb;
  std::stringstream	sstream;

  sstream << str;
  sstream >> nb;
  return (nb);
}

double			my_atod(std::string str)
{
  double		nb;
  std::stringstream	sstream;

  sstream << str;
  sstream >> nb;
  return (nb);
}

float			my_atof(std::string str)
{
  float			nb;
  std::stringstream	sstream;

  sstream << str;
  sstream >> nb;
  return (nb);
}
