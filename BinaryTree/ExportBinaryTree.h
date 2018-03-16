// Author£ºxiongy
// Date£º2018/02/08
// filename:ExportBinaryTree.h
#ifndef _EXPORTBINARYTREE_
#define _EXPORTBINARYTREE_
#if defined(BINARYTREE_LIBRARY)
#define BINARYTREE_LIBRARY_EXPORT __declspec(dllexport)
#else
#define BINARYTREE_LIBRARY_EXPORT 
# endif

#endif //!_EXPORTBINARYTREE_
