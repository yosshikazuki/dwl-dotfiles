/* Generated by wayland-scanner 1.23.0 */

#ifndef DWL_IPC_UNSTABLE_V2_SERVER_PROTOCOL_H
#define DWL_IPC_UNSTABLE_V2_SERVER_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-server.h"

#ifdef  __cplusplus
extern "C" {
#endif

struct wl_client;
struct wl_resource;

/**
 * @page page_dwl_ipc_unstable_v2 The dwl_ipc_unstable_v2 protocol
 * inter-proccess-communication about dwl's state
 *
 * @section page_desc_dwl_ipc_unstable_v2 Description
 *
 * This protocol allows clients to update and get updates from dwl.
 *
 * Warning! The protocol described in this file is experimental and
 * backward incompatible changes may be made. Backward compatible
 * changes may be added together with the corresponding interface
 * version bump.
 * Backward incompatible changes are done by bumping the version
 * number in the protocol and interface names and resetting the
 * interface version. Once the protocol is to be declared stable,
 * the 'z' prefix and the version number in the protocol and
 * interface names are removed and the interface version number is
 * reset.
 *
 * @section page_ifaces_dwl_ipc_unstable_v2 Interfaces
 * - @subpage page_iface_zdwl_ipc_manager_v2 - manage dwl state
 * - @subpage page_iface_zdwl_ipc_output_v2 - control dwl output
 */
struct wl_output;
struct zdwl_ipc_manager_v2;
struct zdwl_ipc_output_v2;

#ifndef ZDWL_IPC_MANAGER_V2_INTERFACE
#define ZDWL_IPC_MANAGER_V2_INTERFACE
/**
 * @page page_iface_zdwl_ipc_manager_v2 zdwl_ipc_manager_v2
 * @section page_iface_zdwl_ipc_manager_v2_desc Description
 *
 * This interface is exposed as a global in wl_registry.
 *
 * Clients can use this interface to get a dwl_ipc_output.
 * After binding the client will recieve the dwl_ipc_manager.tags and dwl_ipc_manager.layout events.
 * The dwl_ipc_manager.tags and dwl_ipc_manager.layout events expose tags and layouts to the client.
 * @section page_iface_zdwl_ipc_manager_v2_api API
 * See @ref iface_zdwl_ipc_manager_v2.
 */
/**
 * @defgroup iface_zdwl_ipc_manager_v2 The zdwl_ipc_manager_v2 interface
 *
 * This interface is exposed as a global in wl_registry.
 *
 * Clients can use this interface to get a dwl_ipc_output.
 * After binding the client will recieve the dwl_ipc_manager.tags and dwl_ipc_manager.layout events.
 * The dwl_ipc_manager.tags and dwl_ipc_manager.layout events expose tags and layouts to the client.
 */
extern const struct wl_interface zdwl_ipc_manager_v2_interface;
#endif
#ifndef ZDWL_IPC_OUTPUT_V2_INTERFACE
#define ZDWL_IPC_OUTPUT_V2_INTERFACE
/**
 * @page page_iface_zdwl_ipc_output_v2 zdwl_ipc_output_v2
 * @section page_iface_zdwl_ipc_output_v2_desc Description
 *
 * Observe and control a dwl output.
 *
 * Events are double-buffered:
 * Clients should cache events and redraw when a dwl_ipc_output.frame event is sent.
 *
 * Request are not double-buffered:
 * The compositor will update immediately upon request.
 * @section page_iface_zdwl_ipc_output_v2_api API
 * See @ref iface_zdwl_ipc_output_v2.
 */
/**
 * @defgroup iface_zdwl_ipc_output_v2 The zdwl_ipc_output_v2 interface
 *
 * Observe and control a dwl output.
 *
 * Events are double-buffered:
 * Clients should cache events and redraw when a dwl_ipc_output.frame event is sent.
 *
 * Request are not double-buffered:
 * The compositor will update immediately upon request.
 */
extern const struct wl_interface zdwl_ipc_output_v2_interface;
#endif

/**
 * @ingroup iface_zdwl_ipc_manager_v2
 * @struct zdwl_ipc_manager_v2_interface
 */
struct zdwl_ipc_manager_v2_interface {
	/**
	 * release dwl_ipc_manager
	 *
	 * Indicates that the client will not the dwl_ipc_manager object
	 * anymore. Objects created through this instance are not affected.
	 */
	void (*release)(struct wl_client *client,
			struct wl_resource *resource);
	/**
	 * get a dwl_ipc_outout for a wl_output
	 *
	 * Get a dwl_ipc_outout for the specified wl_output.
	 */
	void (*get_output)(struct wl_client *client,
			   struct wl_resource *resource,
			   uint32_t id,
			   struct wl_resource *output);
};

#define ZDWL_IPC_MANAGER_V2_TAGS 0
#define ZDWL_IPC_MANAGER_V2_LAYOUT 1

/**
 * @ingroup iface_zdwl_ipc_manager_v2
 */
#define ZDWL_IPC_MANAGER_V2_TAGS_SINCE_VERSION 1
/**
 * @ingroup iface_zdwl_ipc_manager_v2
 */
#define ZDWL_IPC_MANAGER_V2_LAYOUT_SINCE_VERSION 1

/**
 * @ingroup iface_zdwl_ipc_manager_v2
 */
#define ZDWL_IPC_MANAGER_V2_RELEASE_SINCE_VERSION 1
/**
 * @ingroup iface_zdwl_ipc_manager_v2
 */
#define ZDWL_IPC_MANAGER_V2_GET_OUTPUT_SINCE_VERSION 1

/**
 * @ingroup iface_zdwl_ipc_manager_v2
 * Sends an tags event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zdwl_ipc_manager_v2_send_tags(struct wl_resource *resource_, uint32_t amount)
{
	wl_resource_post_event(resource_, ZDWL_IPC_MANAGER_V2_TAGS, amount);
}

/**
 * @ingroup iface_zdwl_ipc_manager_v2
 * Sends an layout event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zdwl_ipc_manager_v2_send_layout(struct wl_resource *resource_, const char *name)
{
	wl_resource_post_event(resource_, ZDWL_IPC_MANAGER_V2_LAYOUT, name);
}

#ifndef ZDWL_IPC_OUTPUT_V2_TAG_STATE_ENUM
#define ZDWL_IPC_OUTPUT_V2_TAG_STATE_ENUM
enum zdwl_ipc_output_v2_tag_state {
	/**
	 * no state
	 */
	ZDWL_IPC_OUTPUT_V2_TAG_STATE_NONE = 0,
	/**
	 * tag is active
	 */
	ZDWL_IPC_OUTPUT_V2_TAG_STATE_ACTIVE = 1,
	/**
	 * tag has at least one urgent client
	 */
	ZDWL_IPC_OUTPUT_V2_TAG_STATE_URGENT = 2,
};
/**
 * @ingroup iface_zdwl_ipc_output_v2
 * Validate a zdwl_ipc_output_v2 tag_state value.
 *
 * @return true on success, false on error.
 * @ref zdwl_ipc_output_v2_tag_state
 */
static inline bool
zdwl_ipc_output_v2_tag_state_is_valid(uint32_t value, uint32_t version) {
	switch (value) {
	case ZDWL_IPC_OUTPUT_V2_TAG_STATE_NONE:
		return version >= 1;
	case ZDWL_IPC_OUTPUT_V2_TAG_STATE_ACTIVE:
		return version >= 1;
	case ZDWL_IPC_OUTPUT_V2_TAG_STATE_URGENT:
		return version >= 1;
	default:
		return false;
	}
}
#endif /* ZDWL_IPC_OUTPUT_V2_TAG_STATE_ENUM */

/**
 * @ingroup iface_zdwl_ipc_output_v2
 * @struct zdwl_ipc_output_v2_interface
 */
struct zdwl_ipc_output_v2_interface {
	/**
	 * release dwl_ipc_outout
	 *
	 * Indicates to that the client no longer needs this
	 * dwl_ipc_output.
	 */
	void (*release)(struct wl_client *client,
			struct wl_resource *resource);
	/**
	 * Set the active tags of this output
	 *
	 * 
	 * @param tagmask bitmask of the tags that should be set.
	 * @param toggle_tagset toggle the selected tagset, zero for invalid, nonzero for valid.
	 */
	void (*set_tags)(struct wl_client *client,
			 struct wl_resource *resource,
			 uint32_t tagmask,
			 uint32_t toggle_tagset);
	/**
	 * Set the tags of the focused client.
	 *
	 * The tags are updated as follows: new_tags = (current_tags AND
	 * and_tags) XOR xor_tags
	 */
	void (*set_client_tags)(struct wl_client *client,
				struct wl_resource *resource,
				uint32_t and_tags,
				uint32_t xor_tags);
	/**
	 * Set the layout of this output
	 *
	 * 
	 * @param index index of a layout recieved by dwl_ipc_manager.layout
	 */
	void (*set_layout)(struct wl_client *client,
			   struct wl_resource *resource,
			   uint32_t index);
};

#define ZDWL_IPC_OUTPUT_V2_TOGGLE_VISIBILITY 0
#define ZDWL_IPC_OUTPUT_V2_ACTIVE 1
#define ZDWL_IPC_OUTPUT_V2_TAG 2
#define ZDWL_IPC_OUTPUT_V2_LAYOUT 3
#define ZDWL_IPC_OUTPUT_V2_TITLE 4
#define ZDWL_IPC_OUTPUT_V2_APPID 5
#define ZDWL_IPC_OUTPUT_V2_LAYOUT_SYMBOL 6
#define ZDWL_IPC_OUTPUT_V2_FRAME 7
#define ZDWL_IPC_OUTPUT_V2_FULLSCREEN 8
#define ZDWL_IPC_OUTPUT_V2_FLOATING 9

/**
 * @ingroup iface_zdwl_ipc_output_v2
 */
#define ZDWL_IPC_OUTPUT_V2_TOGGLE_VISIBILITY_SINCE_VERSION 1
/**
 * @ingroup iface_zdwl_ipc_output_v2
 */
#define ZDWL_IPC_OUTPUT_V2_ACTIVE_SINCE_VERSION 1
/**
 * @ingroup iface_zdwl_ipc_output_v2
 */
#define ZDWL_IPC_OUTPUT_V2_TAG_SINCE_VERSION 1
/**
 * @ingroup iface_zdwl_ipc_output_v2
 */
#define ZDWL_IPC_OUTPUT_V2_LAYOUT_SINCE_VERSION 1
/**
 * @ingroup iface_zdwl_ipc_output_v2
 */
#define ZDWL_IPC_OUTPUT_V2_TITLE_SINCE_VERSION 1
/**
 * @ingroup iface_zdwl_ipc_output_v2
 */
#define ZDWL_IPC_OUTPUT_V2_APPID_SINCE_VERSION 1
/**
 * @ingroup iface_zdwl_ipc_output_v2
 */
#define ZDWL_IPC_OUTPUT_V2_LAYOUT_SYMBOL_SINCE_VERSION 1
/**
 * @ingroup iface_zdwl_ipc_output_v2
 */
#define ZDWL_IPC_OUTPUT_V2_FRAME_SINCE_VERSION 1
/**
 * @ingroup iface_zdwl_ipc_output_v2
 */
#define ZDWL_IPC_OUTPUT_V2_FULLSCREEN_SINCE_VERSION 2
/**
 * @ingroup iface_zdwl_ipc_output_v2
 */
#define ZDWL_IPC_OUTPUT_V2_FLOATING_SINCE_VERSION 2

/**
 * @ingroup iface_zdwl_ipc_output_v2
 */
#define ZDWL_IPC_OUTPUT_V2_RELEASE_SINCE_VERSION 1
/**
 * @ingroup iface_zdwl_ipc_output_v2
 */
#define ZDWL_IPC_OUTPUT_V2_SET_TAGS_SINCE_VERSION 1
/**
 * @ingroup iface_zdwl_ipc_output_v2
 */
#define ZDWL_IPC_OUTPUT_V2_SET_CLIENT_TAGS_SINCE_VERSION 1
/**
 * @ingroup iface_zdwl_ipc_output_v2
 */
#define ZDWL_IPC_OUTPUT_V2_SET_LAYOUT_SINCE_VERSION 1

/**
 * @ingroup iface_zdwl_ipc_output_v2
 * Sends an toggle_visibility event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zdwl_ipc_output_v2_send_toggle_visibility(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, ZDWL_IPC_OUTPUT_V2_TOGGLE_VISIBILITY);
}

/**
 * @ingroup iface_zdwl_ipc_output_v2
 * Sends an active event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zdwl_ipc_output_v2_send_active(struct wl_resource *resource_, uint32_t active)
{
	wl_resource_post_event(resource_, ZDWL_IPC_OUTPUT_V2_ACTIVE, active);
}

/**
 * @ingroup iface_zdwl_ipc_output_v2
 * Sends an tag event to the client owning the resource.
 * @param resource_ The client's resource
 * @param tag Index of the tag
 * @param state The state of the tag.
 * @param clients The number of clients in the tag.
 * @param focused If there is a focused client. Nonzero being valid, zero being invalid.
 */
static inline void
zdwl_ipc_output_v2_send_tag(struct wl_resource *resource_, uint32_t tag, uint32_t state, uint32_t clients, uint32_t focused)
{
	wl_resource_post_event(resource_, ZDWL_IPC_OUTPUT_V2_TAG, tag, state, clients, focused);
}

/**
 * @ingroup iface_zdwl_ipc_output_v2
 * Sends an layout event to the client owning the resource.
 * @param resource_ The client's resource
 * @param layout Index of the layout.
 */
static inline void
zdwl_ipc_output_v2_send_layout(struct wl_resource *resource_, uint32_t layout)
{
	wl_resource_post_event(resource_, ZDWL_IPC_OUTPUT_V2_LAYOUT, layout);
}

/**
 * @ingroup iface_zdwl_ipc_output_v2
 * Sends an title event to the client owning the resource.
 * @param resource_ The client's resource
 * @param title The new title name.
 */
static inline void
zdwl_ipc_output_v2_send_title(struct wl_resource *resource_, const char *title)
{
	wl_resource_post_event(resource_, ZDWL_IPC_OUTPUT_V2_TITLE, title);
}

/**
 * @ingroup iface_zdwl_ipc_output_v2
 * Sends an appid event to the client owning the resource.
 * @param resource_ The client's resource
 * @param appid The new appid.
 */
static inline void
zdwl_ipc_output_v2_send_appid(struct wl_resource *resource_, const char *appid)
{
	wl_resource_post_event(resource_, ZDWL_IPC_OUTPUT_V2_APPID, appid);
}

/**
 * @ingroup iface_zdwl_ipc_output_v2
 * Sends an layout_symbol event to the client owning the resource.
 * @param resource_ The client's resource
 * @param layout The new layout
 */
static inline void
zdwl_ipc_output_v2_send_layout_symbol(struct wl_resource *resource_, const char *layout)
{
	wl_resource_post_event(resource_, ZDWL_IPC_OUTPUT_V2_LAYOUT_SYMBOL, layout);
}

/**
 * @ingroup iface_zdwl_ipc_output_v2
 * Sends an frame event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zdwl_ipc_output_v2_send_frame(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, ZDWL_IPC_OUTPUT_V2_FRAME);
}

/**
 * @ingroup iface_zdwl_ipc_output_v2
 * Sends an fullscreen event to the client owning the resource.
 * @param resource_ The client's resource
 * @param is_fullscreen If the selected client is fullscreen. Nonzero is valid, zero invalid
 */
static inline void
zdwl_ipc_output_v2_send_fullscreen(struct wl_resource *resource_, uint32_t is_fullscreen)
{
	wl_resource_post_event(resource_, ZDWL_IPC_OUTPUT_V2_FULLSCREEN, is_fullscreen);
}

/**
 * @ingroup iface_zdwl_ipc_output_v2
 * Sends an floating event to the client owning the resource.
 * @param resource_ The client's resource
 * @param is_floating If the selected client is floating. Nonzero is valid, zero invalid
 */
static inline void
zdwl_ipc_output_v2_send_floating(struct wl_resource *resource_, uint32_t is_floating)
{
	wl_resource_post_event(resource_, ZDWL_IPC_OUTPUT_V2_FLOATING, is_floating);
}

#ifdef  __cplusplus
}
#endif

#endif
