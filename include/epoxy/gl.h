/*
 * Copyright © 2013 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

/** @file gl.h
 *
 * Provides an implementation of a GL dispatch layer using either
 * global function pointers or a hidden vtable.
 *
 * You should include `<epoxy/gl.h>` instead of `<GL/gl.h>` and `<GL/glext.h>`.
 */

#ifndef EPOXY_GL_H
#define EPOXY_GL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#if defined(__gl_h_) || defined(__glext_h_)
#error epoxy/gl.h must be included before (or in place of) GL/gl.h
#else
#define __gl_h_
#define __glext_h_
#endif

#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1
#define KHRONOS_APIATTRIBUTES

#ifndef _WIN32
/* APIENTRY and GLAPIENTRY are not used on Linux or Mac. */
#define APIENTRY
#define GLAPIENTRY
#define EPOXY_IMPORTEXPORT
#define EPOXY_CALLSPEC
#define GLAPI
#define KHRONOS_APIENTRY
#define KHRONOS_APICALL

#else
#ifndef APIENTRY
#define APIENTRY __stdcall
#endif

#ifndef GLAPIENTRY
#define GLAPIENTRY APIENTRY
#endif

#ifndef EPOXY_CALLSPEC
#define EPOXY_CALLSPEC __stdcall
#endif

#ifndef EPOXY_IMPORTEXPORT
#define EPOXY_IMPORTEXPORT __declspec(dllimport)
#endif

#ifndef GLAPI
#define GLAPI extern
#endif

#define KHRONOS_APIENTRY __stdcall
#define KHRONOS_APICALL __declspec(dllimport) __stdcall

#endif /* _WIN32 */

#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif

#ifndef GLAPIENTRYP
#define GLAPIENTRYP GLAPIENTRY *
#endif

#include "epoxy/gl_generated.h"

/**
 * @brief Returns true if the given GL extension is supported in the current context.
 *
 * @param ext The name of the GL extension
 * @return `true` if the extension is available
 *
 * @note that this function can't be called from within `glBegin()` and `glEnd()`.
 *
 * @see epoxy_has_egl_extension()
 * @see epoxy_has_glx_extension()
 */
EPOXY_IMPORTEXPORT bool epoxy_has_gl_extension(const char *extension);

/**
 * @brief Checks whether we're using OpenGL or OpenGL ES
 *
 * @return `true` if we're using OpenGL
 */
EPOXY_IMPORTEXPORT bool epoxy_is_desktop_gl(void);

/**
 * @brief Returns the version of OpenGL we are using
 *
 * The version is encoded as:
 *
 * ```
 *
 *   version = major * 10 + minor
 *
 * ```
 *
 * So it can be easily used for version comparisons.
 *
 * @return The encoded version of OpenGL we are using
 */
EPOXY_IMPORTEXPORT int epoxy_gl_version(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* EPOXY_GL_H */
