/**
 *  Copyright (C) 2010  Allan McRae <allan@archlinux.org>
 *  Modifications (2012) by Daniel Graziotin <dgraziotin@task3.cc>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 */

/** Basic fan speed parameters
 */
extern int min_fan_speed;
extern int max_fan_speed;

/** Temperature Thresholds
 *  low_temp - temperature below which fan speed will be at minimum
 *  high_temp - fan will increase speed when higher than this temperature
 *  max_temp - fan will run at full speed above this temperature */
extern int low_temp;
extern int high_temp;
extern int max_temp;

/** Temperature polling interval
 *  Default value was 10 (seconds)
 */
extern int polling_interval;

/** Represents a Temperature sensor
 */
struct s_sensors;
typedef struct s_sensors t_sensors;

/**
 * Detect the sensors in /sys/devices/platform/coretemp.0/temp
 * Return a linked list of t_sensors (first temperature detected)
 */
t_sensors *retrieve_sensors();

/**
 * Given a linked list of t_sensors, refresh their detected
 * temperature
 */
t_sensors *refresh_sensors(t_sensors *sensors);

/**
 * Detect the fans in /sys/devices/platform/applesmc.768/
 * Associate each fan to a sensor
 */
void find_fans(t_sensors *sensors);

/**
 * Given a list of sensors with associated fans
 * Set them to manual control
 */
void set_fans_man(t_sensors *sensors);

/**
 *  Return average CPU temp in degrees (ceiling)
 */
unsigned short get_temp(t_sensors* sensors);

/**
 * Main Program
 */
void mbpfan();