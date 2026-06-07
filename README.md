# Bandmon

This is a project intended to deploy a distributed band monitoring system to better quantify 2m repeater usage. 

The goal was to implement a system that can monitor a repeater audio output and detect activity and generate a summary to evaluate activity. 

funding provided by the WVU Amateur radio club [W8CUL](https://wvuarc.orgs.wvu.edu)
## Dependencies 

- Arduino board manager: `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
- MQTT pub/sub library placed in side `~/Arduino/libraries/` 

```
git clone git@github.com:knolleary/pubsubclient.git
```
- this can also be added using the library manager
- more info[link](https://pubsubclient.knolleary.net)

## Configuring wifi 


## MQTT interface

For data collection and commanding, MQTT is used as the main protocol. Each device has a unique node ID based on the device's MAC address. It is visible on startup along with the MAC address. 

A sample serial output on startup is shown below

```
Need to get a sample out put from a connected device
```

To send commands to and from a device, the user needs to know the node ID. Basic MQTT data and topics and usage can be found in the following table 

| Topic                     | content                             | usage                                                                                                                       |
| ------------------------- | ----------------------------------- | --------------------------------------------------------------------------------------------------------------------------- |
| `bandmon/alive`           | float; Node ID                      | on restart every node publishes its node ID to this topic. We can look at basic network wide statistic using this topic     |
| `bandmon/cmd/<node id>`   | `r`                                 | soft restart                                                                                                                |
| `bandmon/cmd/<node id>`   | `c`                                 | calibrate, this runs a noice level calibration and returns the data to both the serial out put and `bandmon/rply/<node-id>` |
| `bandmon/cmd/<node id>`   | `w`                                 | saves the user config to EEPROM memory, needs to be run after calibration to save                                           |
| `bandmon/<state>/<RCALL>` | float                               | active seconds                                                                                                              |
| `bandmon/data`            | `{"call":"W8CUL","activity":10.00}` | This is the total number of seconds voice is detected on the input signal                                                   |



## Tools 

- [Mqtt_spy](https://github.com/eclipse/paho.mqtt-spy/releases/) > 1.0.1-beta9. Running with jre 8.6 works well in linux/Windows. 
	- MAC still has trouble running it correctly
- [esp_tools](https://github.com/espressif/esptool) - For installation and firmware update

## To-do list

- [x] Basic code for Wifi and MQTT connection
- [x] Send repeater activity based on audio input
 - [x] EEPROM data save
	 - [x] Increase the URL space to allow for a longer address
	 - [ ] add a serial syntax for reset ?
- [ ] Configurable settings TUI
- [ ] Hardware design 
    - [ ] final PCB design - audio based
    - [ ] 3D printable case design
- [x] Server end logging
	- [x] Display with Grafana
	- [x] Deploy in the ARC server
- [ ] Write an article about it 
    - [ ] reach out to other local clubs
