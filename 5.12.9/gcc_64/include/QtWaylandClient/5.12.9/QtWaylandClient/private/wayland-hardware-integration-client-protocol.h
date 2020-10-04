/* Generated by wayland-scanner 1.15.0 */

#ifndef HARDWARE_INTEGRATION_CLIENT_PROTOCOL_H
#define HARDWARE_INTEGRATION_CLIENT_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-client.h"

#ifdef  __cplusplus
extern "C" {
#endif

/**
 * @page page_hardware_integration The hardware_integration protocol
 * @section page_ifaces_hardware_integration Interfaces
 * - @subpage page_iface_qt_hardware_integration - compostors communicates supported buffer sharing extensions
 * @section page_copyright_hardware_integration Copyright
 * <pre>
 *
 * Copyright (C) 2015 The Qt Company Ltd.
 * Contact: http://www.qt.io/licensing/
 *
 * This file is part of the plugins of the Qt Toolkit.
 *
 * $QT_BEGIN_LICENSE:BSD$
 * You may use this file under the terms of the BSD license as follows:
 *
 * "Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in
 * the documentation and/or other materials provided with the
 * distribution.
 * * Neither the name of The Qt Company Ltd nor the names of its
 * contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
 *
 * $QT_END_LICENSE$
 * </pre>
 */
struct qt_hardware_integration;

/**
 * @page page_iface_qt_hardware_integration qt_hardware_integration
 * @section page_iface_qt_hardware_integration_desc Description
 *
 * Using this protocol the compositor can signal to clients which buffer sharing extensions
 * the client should use
 * @section page_iface_qt_hardware_integration_api API
 * See @ref iface_qt_hardware_integration.
 */
/**
 * @defgroup iface_qt_hardware_integration The qt_hardware_integration interface
 *
 * Using this protocol the compositor can signal to clients which buffer sharing extensions
 * the client should use
 */
extern const struct wl_interface qt_hardware_integration_interface;

/**
 * @ingroup iface_qt_hardware_integration
 * @struct qt_hardware_integration_listener
 */
struct qt_hardware_integration_listener {
	/**
	 */
	void (*client_backend)(void *data,
			       struct qt_hardware_integration *qt_hardware_integration,
			       const char *name);
	/**
	 */
	void (*server_backend)(void *data,
			       struct qt_hardware_integration *qt_hardware_integration,
			       const char *name);
};

/**
 * @ingroup iface_qt_hardware_integration
 */
static inline int
qt_hardware_integration_add_listener(struct qt_hardware_integration *qt_hardware_integration,
				     const struct qt_hardware_integration_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) qt_hardware_integration,
				     (void (**)(void)) listener, data);
}

/**
 * @ingroup iface_qt_hardware_integration
 */
#define QT_HARDWARE_INTEGRATION_CLIENT_BACKEND_SINCE_VERSION 1
/**
 * @ingroup iface_qt_hardware_integration
 */
#define QT_HARDWARE_INTEGRATION_SERVER_BACKEND_SINCE_VERSION 1


/** @ingroup iface_qt_hardware_integration */
static inline void
qt_hardware_integration_set_user_data(struct qt_hardware_integration *qt_hardware_integration, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) qt_hardware_integration, user_data);
}

/** @ingroup iface_qt_hardware_integration */
static inline void *
qt_hardware_integration_get_user_data(struct qt_hardware_integration *qt_hardware_integration)
{
	return wl_proxy_get_user_data((struct wl_proxy *) qt_hardware_integration);
}

static inline uint32_t
qt_hardware_integration_get_version(struct qt_hardware_integration *qt_hardware_integration)
{
	return wl_proxy_get_version((struct wl_proxy *) qt_hardware_integration);
}

/** @ingroup iface_qt_hardware_integration */
static inline void
qt_hardware_integration_destroy(struct qt_hardware_integration *qt_hardware_integration)
{
	wl_proxy_destroy((struct wl_proxy *) qt_hardware_integration);
}

#ifdef  __cplusplus
}
#endif

#endif
