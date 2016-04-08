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
 * \date    2007-10-02
 *
 */
//----------------------------------------------------------------------
#include "LogLevel.h"

#include <icl_core/BaseTypes.h>

namespace icl_core {
namespace logging {

const char *log_level_descriptions[] =
{
  "Trace",
  "Debug",
  "Info",
  "Warning",
  "Error",
  "Mute",
  NULL
};

const char *logLevelDescription(LogLevel log_level)
{
  if (log_level < eLL_TRACE || log_level > eLL_MUTE)
  {
    return "";
  }
  else
  {
    return log_level_descriptions[log_level];
  }
}

bool stringToLogLevel(const std::string& log_level_text, LogLevel& log_level)
{
  for (size_t index = 0; index <= eLL_MUTE; ++index)
  {
    if (log_level_text == log_level_descriptions[index])
    {
      log_level = LogLevel(index);
      return true;
    }
  }

  return false;
}

////////////// DEPRECATED VERSIONS //////////////
#ifdef _IC_BUILDER_DEPRECATED_STYLE_

const char *LogLevelDescription(LogLevel log_level)
{
  return logLevelDescription(log_level);
}

bool StringToLogLevel(const std::string& log_level_text, LogLevel& log_level)
{
  return stringToLogLevel(log_level_text, log_level);
}

#endif
/////////////////////////////////////////////////

}
}
