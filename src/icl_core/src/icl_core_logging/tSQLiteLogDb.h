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
 * \date    2009-07-03
 *
 */
//----------------------------------------------------------------------
#ifndef ICL_CORE_LOGGING_T_SQLITE_LOG_DB_H_INCLUDED
#define ICL_CORE_LOGGING_T_SQLITE_LOG_DB_H_INCLUDED

#include "icl_core/Deprecate.h"
#include "icl_core_logging/SQLiteLogDb.h"

namespace icl_core {
namespace logging {

typedef ICL_CORE_VC_DEPRECATE SQLiteLogDb tSQLiteLogDb ICL_CORE_GCC_DEPRECATE;

}
}

#endif
