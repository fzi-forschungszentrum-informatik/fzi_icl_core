// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// This file is part of FZIs ic_workspace.
//
// This program is free software licensed under the LGPL
// (GNU LESSER GENERAL PUBLIC LICENSE Version 3).
// You can find a copy of this license in LICENSE folder in the top
// directory of the source code.
//
// © Copyright 2016 FZI Forschungszentrum Informatik, Karlsruhe, Germany
//
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Klaus Uhl <uhl@fzi.de>
 * \date    2008-03-29
 *
 */
//----------------------------------------------------------------------
#include <stdio.h>
#include <string.h>

#include "icl_core/os_win32_string.h"

namespace icl_core {
namespace os {
namespace hidden_win32 {

char *stpcpy(char *dst, const char *src)
{
  char *result = strcpy(dst, src);
  for (; *result != 0; ++result) {}
  return result;
}

char *strdup(const char *s)
{
  return ::_strdup(s);
}

int vsnprintf(char *buffer, size_t maxlen, const char *format, va_list argptr)
{
  return ::_vsnprintf(buffer, maxlen, format, argptr);
}

}
}
}
