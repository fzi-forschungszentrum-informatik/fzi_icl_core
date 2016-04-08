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
 * \date    2006-06-10
 *
 */
//----------------------------------------------------------------------
#include <iostream>

#include "icl_core_logging/Logging.h"
#include "icl_core_logging/StdErrorLogOutput.h"

namespace icl_core {
namespace logging {

REGISTER_LOG_OUTPUT_STREAM(Stderr, &StdErrorLogOutput::create)

LogOutputStream *StdErrorLogOutput::create(const icl_core::String& name,
                                           const icl_core::String& config_prefix,
                                           icl_core::logging::LogLevel log_level)
{
  return new StdErrorLogOutput(name, config_prefix, log_level);
}

void StdErrorLogOutput::pushImpl(const icl_core::String& log_line)
{
  std::cerr << log_line;
}

}
}
