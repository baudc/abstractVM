//
// Parser.cpp for  in /home/nogue_k/Rendu/S4/synt/abstractVM_2016/nogue_k
// 
// Made by nogue_k
// Login   <nogue_k@epitech.net>
// 
// Started on  Mon Jul 24 11:22:44 2017 Kévin Nogué
// Last update Wed Jul 26 17:10:26 2017 baud
//

#include "my.hpp"
#include "Exception.hpp"
#include "Parser.hh"

Parser::Parser(std::string const& nameOfFile)
  : _nameOfFile(nameOfFile)
{
  this->initList();
}

void				Parser::pPop(std::string fullLine)
{
  _memory->pop();
}

void				Parser::pDump(std::string fullLine)
{
  _memory->dump();
}

void				Parser::pAdd(std::string fullLine)
{
  _memory->add();
}

void				Parser::pSub(std::string fullLine)
{
  _memory->sub();
}

void				Parser::pMul(std::string fullLine)
{
  _memory->mul();
}

void				Parser::pClear(std::string fullLine)
{
  _memory->clear();
}

void				Parser::pDup(std::string fullLine)
{
  _memory->dup();
}

void				Parser::pDiv(std::string fullLine)
{
  _memory->div();
}

void				Parser::pPrint(std::string line)
{
  _memory->print();
}

void				Parser::pMod(std::string fullLine)
{
  _memory->mod();
}

void				Parser::pSwap(std::string fullLine)
{
  _memory->swap();
}

void				Parser::pAssert(std::string fullLine)
{
  int		pos;
  std::string	type;
  std::string	value;

  pos = fullLine.find(" ");
  if (pos != std::string::npos)
    {
      fullLine = fullLine.substr(pos + 1);
      pos = fullLine.find("(");
      if (pos != std::string::npos)
	{
	  type = fullLine.substr(0, pos);
	  fullLine = fullLine.substr(pos + 1);
	  pos = fullLine.find(")");
	  if (pos != std::string::npos)
	    value = fullLine.substr(0, pos);
	}
    }
  if (type.empty() || value.empty())
    throw Exception(SYNTAX_ERROR);
  _memory->assert(Factory::createOperand(Factory::getOperandTypeFromStr(type),
					 value));
}

void				Parser::pLoad(std::string fullLine)
{
  int		pos;
  std::string	type;
  std::string	value;

  pos = fullLine.find(" ");
  if (pos != std::string::npos)
    {
      fullLine = fullLine.substr(pos + 1);
      pos = fullLine.find("(");
      if (pos != std::string::npos)
	{
	  type = fullLine.substr(0, pos);
	  fullLine = fullLine.substr(pos + 1);
	  pos = fullLine.find(")");
	  if (pos != std::string::npos)
	    value = fullLine.substr(0, pos);
	}
    }
  if (type.empty() || value.empty())
    throw Exception(SYNTAX_ERROR);
  else
    _memory->load(my_atoi(value.c_str()));
}

void				Parser::pStore(std::string fullLine)
{
  int		pos;
  std::string	type;
  std::string	value;

  pos = fullLine.find(" ");
  if (pos != std::string::npos)
    {
      fullLine = fullLine.substr(pos + 1);
      pos = fullLine.find("(");
      if (pos != std::string::npos)
	{
	  type = fullLine.substr(0, pos);
	  fullLine = fullLine.substr(pos + 1);
	  pos = fullLine.find(")");
	  if (pos != std::string::npos)
	    value = fullLine.substr(0, pos);
	}
    }
  if (type.empty() || value.empty())
    throw Exception(SYNTAX_ERROR);
  else
    _memory->store(my_atoi(value.c_str()));
}

void				Parser::pPush(std::string fullLine)
{
  int				pos;
  std::string			type;
  std::string			value;

  pos = fullLine.find(" ");
  if (pos != std::string::npos)
    {
      fullLine = fullLine.substr(pos + 1);
      pos = fullLine.find("(");
      if (pos != std::string::npos)
	{
	  type = fullLine.substr(0, pos);
	  fullLine = fullLine.substr(pos + 1);
	  pos = fullLine.find(")");
	  if (pos != std::string::npos)
	    value = fullLine.substr(0, pos);
	}
    }
  if (value.empty() || type.empty())
    throw Exception(SYNTAX_ERROR);
  _memory->push(Factory::createOperand(Factory::getOperandTypeFromStr(type),
				       value));
}

void				Parser::pExit(std::string line)
{
  exit(0);
}

void				Parser::getContentOfFile()
{
  std::ifstream			file(_nameOfFile.c_str());
  std::string			line;

  if (!_nameOfFile.empty())
    {
      if (file.good() == 0)
	throw Exception(INCORRECT_FILE);
      else
	while (std::getline(file, line))
	  _lines.push_back(epur_string(line));
    }
  else
    {
      while (std::getline(std::cin, line))
	{
	  _lines.push_back(epur_string(line));
	  if (line.find(";;") != std::string::npos)
	    break;
	}
    }
}

void				Parser::initList()
{
  _membersTab[0] = &Parser::pAdd;
  _membersTab[1] = &Parser::pPop;
  _membersTab[2] = &Parser::pDump;
  _membersTab[3] = &Parser::pSub;
  _membersTab[4] = &Parser::pPush;
  _membersTab[5] = &Parser::pClear;
  _membersTab[6] = &Parser::pMod;
  _membersTab[7] = &Parser::pDiv;
  _membersTab[8] = &Parser::pLoad;
  _membersTab[9] = &Parser::pPrint;
  _membersTab[10] = &Parser::pExit;
  _membersTab[11] = &Parser::pStore;
  _membersTab[12] = &Parser::pMul;
  _membersTab[13] = &Parser::pAssert;
  _membersTab[14] = &Parser::pSwap;
  _membersTab[15] = &Parser::pDup;
  _commandTab[0] = "add";
  _commandTab[1] = "pop";
  _commandTab[2] = "dump";
  _commandTab[3] = "sub";
  _commandTab[4] = "push";
  _commandTab[5] = "clear";
  _commandTab[6] = "mod";
  _commandTab[7] = "div";
  _commandTab[8] = "load";
  _commandTab[9] = "print";
  _commandTab[10] = "exit";
  _commandTab[11] = "store";
  _commandTab[12] = "mul";
  _commandTab[13] = "assert";
  _commandTab[14] = "swap";
  _commandTab[15] = "dup";
}

int				Parser::callCmd(std::string const& line)
{
  int				find;
  std::string			cmd;
  std::vector<std::string>	key_tab;
  int				count;
  bool				found;

  cmd = (line.find(" ") == std::string::npos ? line : line.substr(0, line.find(" ")));
  for (int i = 0; i < 16; i++)
    {
      if (_commandTab[i] == cmd)
	{
	  (this->*_membersTab[i])(line);
	  found = true;
	  break;
	}
    }
  return ((found ? 0 : 1));
}

void			Parser::start(Memory *mem)
{
  int			count;
  std::ostringstream	convert;

  count = 0;
  _memory = mem;
  for (std::vector<std::string>::iterator it = _lines.begin();
       it != _lines.end(); it++)
    {
      if (!it->empty() && it->at(0) != ';')
	{
	  try
	    {
	      if ((callCmd(*it)) == 1)
		{
		  throw Exception(SYNTAX_ERROR, count + 1);
		}
	    }
	  catch (Exception const& e)
	    {
	      throw Exception(e.what(), count + 1);
	    }
	}
      count++;
    }
}

std::string			Parser::epur_string(std::string const& line)
{
  std::string			str;
  bool				word = false;
  int				count = -1;
  int				find;

  while (++count < line.size())
    if (line.at(count) != ' ' && line.at(count) != '\t')
      {
	word = true;
	str += line.at(count);
      }
    else if (word && count + 1 != line.size() &&
	     line.at(count + 1) != ' ' &&
	     line.at(count + 1) != '\t')
      {
	str += ' ';
	word = false;
      }
  if ((find = line.find(";")) != std::string::npos)
    return (str.substr(0, find));
  else
    return (str);
}
