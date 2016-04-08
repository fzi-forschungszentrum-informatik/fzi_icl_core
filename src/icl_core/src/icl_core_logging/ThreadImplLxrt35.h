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
 * \author  Klaus Uhl <uhl@fzi.de>
 * \date    2010-06-30
 *
 * \brief   Contains icl_core::lthread::ThreadImplLxrt35
 *
 * \b icl_core::lthread::ThreadImplLxrt35
 *
 */
//----------------------------------------------------------------------
#ifndef ICL_CORE_LOGGING_THREAD_IMPL_LXRT35_H_INCLUDED
#define ICL_CORE_LOGGING_THREAD_IMPL_LXRT35_H_INCLUDED

#include <rtai_posix.h>

#include <icl_core/os_thread.h>

#include "ThreadImpl.h"

#define DEFAULT_STACK_SIZE 0x4000

namespace icl_core {
namespace logging {

class Thread;

class ThreadImplLxrt35 : public ThreadImpl
{
public:
  ThreadImplLxrt35(Thread *thread, icl_core::ThreadPriority priority);
  virtual ~ThreadImplLxrt35();

  virtual void join();
  virtual bool start();

private:
  static void *runThread(void *arg);

  pthread_t m_thread_id;
  Thread *m_thread;
  ThreadPriority m_priority;

  RT_TASK *m_rt_task;
  pthread_barrier_t* m_rt_start_sync;
};

}
}

#endif
