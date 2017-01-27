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

/** @file glx.h
 *
 * Provides an implementation of a GLX dispatch layer using global
 * function pointers.
 */

#ifndef EPOXY_GLX_H
#define EPOXY_GLX_H

#ifdef __cplusplus
extern "C" {
#endif

#include <epoxy/gl.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdbool.h>

#if defined(GLX_H) || defined(__glxext_h_)
#error epoxy/glx.h must be included before (or in place of) GL/glx.h
#else
#define GLX_H
#define __glx_h__
#define __glxext_h_
#endif

#include "epoxy/glx_generated.h"

/**
 * @brief Returns true if the given GLX extension is supported in the current context.
 *
 * @param dpy The X11 display
 * @param screen The X11 screen
 * @param extension The name of the GLX extension
 *
 * @return `true` if the extension is available
 *
 * @see epoxy_has_gl_extension()
 * @see epoxy_has_egl_extension()
 */
bool epoxy_has_glx_extension(Display *dpy, int screen, const char *extension);

/**
 * @brief Returns the version of GLX we are using
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
 * @param dpy The X11 display
 * @param screen The X11 screen
 *
 * @return The encoded version of GLX we are using
 *
 * @see epoxy_gl_version()
 */
int epoxy_glx_version(Display *dpy, int screen);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* EPOXY_GLX_H */
