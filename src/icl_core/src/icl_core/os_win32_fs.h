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
 * \date    2008-01-28
 *
 * \brief   Win32 implementation of the global filesystem functions.
 */
//----------------------------------------------------------------------
#ifndef ICL_CORE_OS_WIN32_FS_H_INCLUDED
#define ICL_CORE_OS_WIN32_FS_H_INCLUDED

#include "icl_core/ImportExport.h"

namespace icl_core {
namespace os {
//! Internal implementation details for Win32 systems.
namespace hidden_win32 {

ICL_CORE_IMPORT_EXPORT int rename(const char *old_filename, const char *new_filename);
ICL_CORE_IMPORT_EXPORT int unlink(const char *filename);

}
}
}

#endif
