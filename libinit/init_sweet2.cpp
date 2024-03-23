/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifdef __ANDROID_RECOVERY__

#include <cstring>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#define DEVICE_NAME "sweet2"
#define DEVICE_PROP "ro.product.device"

void vendor_load_properties() {
	const prop_info* pi = __system_property_find(DEVICE_PROP);

	if (pi != nullptr)
		__system_property_update(const_cast<prop_info*>(pi), DEVICE_NAME, std::strlen(DEVICE_NAME));
	else
		__system_property_add(DEVICE_PROP, std::strlen(DEVICE_PROP), DEVICE_NAME, std::strlen(DEVICE_NAME));
}

#else

void vendor_load_properties() {}

#endif
