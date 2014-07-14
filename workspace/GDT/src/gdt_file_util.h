/*
 * gdt_file_util.h
 *
 *  Created on: May 5, 2014
 *      Author: autoyujun
 */

#ifndef GDT_FILE_UTIL_H_
#define GDT_FILE_UTIL_H_

#include "gdt_sys.h"
using namespace std;

/*
  This class includes all functions during file operation

*/
namespace gdt{
      
      int open(const char* name, int flags, mode_t mode = 0666);
      int close(int fd);
      int dup(int fd);
      int fsync(int fd);
      int truncate(const char* path, off_t len);
      
      ssize_t read(int fd, void* buf, size_t n);
      ssize_t pread(int fd, void* buf, size_t n, off_t offset);
      
      ssize_t write(int fd, void* buf, size_t n);
      ssize_t pwrite(int fd, void* buf, size_t n, off_t offset);
  
  
  }


#endif /* GDT_FILE_UTIL_H_*/
