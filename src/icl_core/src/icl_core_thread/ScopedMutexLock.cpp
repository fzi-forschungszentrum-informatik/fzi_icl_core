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
 * \date    2009-06-08
 *
 */
//----------------------------------------------------------------------
#include "icl_core_thread/ScopedMutexLock.h"

#include "icl_core_thread/Mutex.h"

namespace icl_core {
namespace thread {

ScopedMutexLock::ScopedMutexLock(Mutex& mutex, bool force)
  : m_mutex(mutex), m_is_locked(false)
{
  do
  {
    m_is_locked = m_mutex.lock();
  }
  while (force && !m_is_locked);
}

ScopedMutexLock::~ScopedMutexLock()
{
  if (isLocked())
  {
    m_mutex.unlock();
  }
}

////////////// DEPRECATED VERSIONS //////////////
#ifdef _IC_BUILDER_DEPRECATED_STYLE_

/*! Check if the mutex has been successfully locked.
 *  \deprecated Obsolete coding style.
 */
bool ScopedMutexLock::IsLocked() const
{
  return isLocked();
}

#endif
/////////////////////////////////////////////////

}
}
