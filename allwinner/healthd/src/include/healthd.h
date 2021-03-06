/*
 * Copyright (C) 2013 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _HEALTHD_H_
#define _HEALTHD_H_

#include <sys/types.h>
struct BatteryProperties {
    bool chargerAcOnline;
    bool chargerUsbOnline;
    bool chargerWirelessOnline;
    int batteryStatus;
    int batteryHealth;
    bool batteryPresent;
    int batteryLevel;
    int batteryVoltage;
    int batteryTemperature;
//    status_t writeToParcel(Parcel* parcel) const;
//    status_t readFromParcel(Parcel* parcel);
};

struct healthd_config{
	int periodic_chores_interval_fast;
	int periodic_chores_interval_slow;
	int batteryPresent;
	int batteryCapacity;
	int batteryVoltage;
	int batteryTemperature;
	//int batteryTechnology;
	int batteryCurrentNow;
	int batteryStatus;
	int batteryHealth;
	bool (*screen_on)(BatteryProperties *props);
};



//typedef unsigned short __kernel_sa_family_t;
typedef unsigned int        __u32;
typedef unsigned long uint32_tt;
/*
struct sockaddr_nl {
	__kernel_sa_family_t	nl_family;
	unsigned short	nl_pad;
	__u32		nl_pid;
	__u32		nl_groups;
};
*/

int healthd_register_event(int fd, void(*handler)(uint32_tt));
void healthd_battery_update();
//android::status_t healthd_get_property(int id,
 //   struct android::BatteryProperty *val);
//void healthd_dump_battery_state(int fd);

struct healthd_mode_ops {
    void (*init)(struct healthd_config *config);
    int (*preparetowait)(void);
    void (*heartbeat)(void);
    void (*battery_update)(struct BatteryProperties *props);
};

extern struct healthd_mode_ops *healthd_mode_ops;


// Charger mode

void healthd_mode_charger_init(struct healthd_config *config);
int healthd_mode_charger_preparetowait(void);
void healthd_mode_charger_heartbeat(void);
void healthd_mode_charger_battery_update(
    struct BatteryProperties *props);


void healthd_board_init(struct healthd_config *config);

// Process updated battery property values.  This function is called when
// the kernel sends updated battery status via a uevent from the power_supply
// subsystem, or when updated values are polled by healthd, as for periodic
// poll of battery state.
//
// props are the battery properties read from the kernel.  These values may
// be modified in this call, prior to sending the modified values to the
// Android runtime.
//
// Return 0 to indicate the usual kernel log battery status heartbeat message
// is to be logged, or non-zero to prevent logging this information.

int healthd_board_battery_update(struct BatteryProperties *props);

#endif /* _HEALTHD_H_ */
