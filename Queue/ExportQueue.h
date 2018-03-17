// Author£ºxiongy
// Date£º2018/02/08
// filename:Exportqueue.h
#ifndef _EXPORTQUEUE_H_
#define _EXPORTQUEUE_H_
#if defined(QUEUE_LIBRARY)
#define BINARYTREE_LIBRARY_EXPORT __declspec(dllexport)
#else
#define BINARYTREE_LIBRARY_EXPORT 
# endif

#endif //!_EXPORTQUEUE_H_