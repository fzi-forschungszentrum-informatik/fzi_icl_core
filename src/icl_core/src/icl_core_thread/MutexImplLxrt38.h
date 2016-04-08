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
 * \date    2009-06-09
 * \author  Jan Oberländer <oberlaen@fzi.de>
 * \date    2009-11-09
 *
 * \brief   Contains icl_core::thread::MutexImplLxrt38
 *
 * \b icl_core::thread::MutexImplLxrt38
 *
 */
//----------------------------------------------------------------------
#ifndef ICL_CORE_THREAD_MUTEX_IMPL_LXRT38_H_INCLUDED
#define ICL_CORE_THREAD_MUTEX_IMPL_LXRT38_H_INCLUDED

#include <rtai_posix.h>

#include "icl_core_thread/MutexImpl.h"
#include "icl_core_thread/SemaphoreImplLxrt38.h"

namespace icl_core {
namespace thread {

class MutexImplLxrt38 : public MutexImpl
{
public:
  MutexImplLxrt38();
  virtual ~MutexImplLxrt38();

  virtual bool lock();
  virtual bool lock(const icl_core::TimeSpan& timeout);
  virtual bool lock(const icl_core::TimeStamp& timeout);
  virtual bool tryLock();
  virtual void unlock();

private:
  SemaphoreImplLxrt38 m_sem;
};

}
}

#endif
