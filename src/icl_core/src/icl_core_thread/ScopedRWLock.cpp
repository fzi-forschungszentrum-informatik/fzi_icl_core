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
 * \author  Jan Oberländer <oberlaen@fzi.de>
 * \date    2010-09-27
 *
 */
//----------------------------------------------------------------------
#include "icl_core_thread/ScopedRWLock.h"

#include "icl_core_thread/RWLock.h"

namespace icl_core {
namespace thread {

ScopedRWLock::ScopedRWLock(RWLock& lock, LockMode lock_mode, bool force)
  : m_lock(lock), m_is_locked(false)
{
  if (lock_mode == eLM_READ_LOCK)
  {
    do { m_is_locked = m_lock.readLock(); } while (force && !m_is_locked);
  }
  else
  {
    do { m_is_locked = m_lock.writeLock(); } while (force && !m_is_locked);
  }
}

ScopedRWLock::~ScopedRWLock()
{
  if (isLocked())
  {
    m_lock.unlock();
  }
}

////////////// DEPRECATED VERSIONS //////////////
#ifdef _IC_BUILDER_DEPRECATED_STYLE_

/*! Check if the read-write lock has been successfully locked.
 *  \deprecated Obsolete coding style.
 */
bool ScopedRWLock::IsLocked() const
{
  return isLocked();
}

#endif
/////////////////////////////////////////////////

}
}
