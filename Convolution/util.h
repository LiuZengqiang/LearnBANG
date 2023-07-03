/**
 * @file util.h
 * @author liuzengqiang
 * @brief utils
 * @version 0.1
 * @date 2023-07-03
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef CONVOLUTION_UTIL_H_
#define CONVOLUTION_UTIL_H_
#include <bang.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "cnnl.h"
#include "cnrt.h"

#define ERROR(s)                                                      \
  {                                                                   \
    std::stringstream _message;                                       \
    _message << __FILE__ << ':' << __LINE__ << " " << std::string(s); \
    std::cerr << _message.str() << "\nAborting...\n";                 \
    exit(EXIT_FAILURE);                                               \
  }

std::string cnnlErrorString(cnnlStatus_t status) {
  switch (status) {
    default: {
      return "CNNL_STATUS_UNKNOWN";
    }
    case CNNL_STATUS_SUCCESS: {
      return "CNNL_STATUS_SUCCESS";
    }
    case CNNL_STATUS_NOT_INITIALIZED: {
      return "CNNL_STATUS_NOT_INITIALIZED";
    }
    case CNNL_STATUS_ALLOC_FAILED: {
      return "CNNL_STATUS_ALLOC_FAILED";
    }
    case CNNL_STATUS_BAD_PARAM: {
      return "CNNL_STATUS_BAD_PARAM";
    }
    case CNNL_STATUS_INTERNAL_ERROR: {
      return "CNNL_STATUS_INTERNAL_ERROR";
    }
    case CNNL_STATUS_ARCH_MISMATCH: {
      return "CNNL_STATUS_MISMATCH";
    }
    case CNNL_STATUS_EXECUTION_FAILED: {
      return "CNNL_STATUS_EXECUTION_FAILED";
    }
    case CNNL_STATUS_NOT_SUPPORTED: {
      return "CNNL_STATUS_NOT_SUPPORTED";
    }
    case CNNL_STATUS_NUMERICAL_OVERFLOW: {
      return "CNNL_STATUS_NUMERICAL_OVERFLOW";
    }
  }
}

#define CNNL_CHECK(val)               \
  {                                   \
    if (val != CNNL_STATUS_SUCCESS) { \
      ERROR(cnnlErrorString(val));    \
    }                                 \
  }

#endif  // CONVOLUTION_UTIL_H_
