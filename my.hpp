//
// my.hpp for my in /home/duhame_a/synthese
// 
// Made by Josselin Duhamel
// Login   <duhame_a@epitech.net>
// 
// Started on  Thu Jul 20 14:47:48 2017 Josselin Duhamel
// Last update Mon Jul 24 16:02:15 2017 Josselin Duhamel
//

#ifndef MY_HPP_
# define MY_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include <strings.h>
#include <stdlib.h>

int	my_atoi(std::string);
int	my_atol(std::string);
void	open_file(char *str);
void	disp_error(std::string str);
void	read_input();
float	my_atof(std::string);
double	my_atod(std::string);

#endif
