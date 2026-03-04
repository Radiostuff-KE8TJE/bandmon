# Docker configuration

Grafana docker deployment 

```
docker run -d -p 3000:3000 --name=grafana-2 \
  --user "$(id -u)" \
  --volume "$PWD/custom.ini:/etc/grafana/grafana.ini" \
  --volume "$PWD/data:/var/lib/grafana" \
  grafana/grafana-oss
``` 
Influxdb 2 deployment
```
docker run  --name influxdb2  --publish 8086:8086  --mount type=volume,source=influxdb2-data,target=/var/lib/influxdb2  --mount type=volume,source=influxdb2-config,target=/etc/influxdb2 influxdb:2
```
Telegraf deployment 

```
sudo docker run --name=telegraf-1 --net=container:influxdb2 -v /opt/telegraf/telegraf.conf:/etc/telegraf/telegraf.conf:ro telegraf
```

### General docker usage commands
- `docker ps`
- `docker start/stop/restart <con-name>`
- `docker logs <con-name>`
- `docker network inspect bridge`: To find internal docker routing Ip addresses you can use
- `docker pull grafana/grafana-oss`: Update the container and pull the latest docker image

## basic data usage example

The following dashboard is a basic view with a collection plots to show repeater activity on W8CUL - 2m repeater. (Grafana v11.3 dashboard) the json file can be found [here](./basic_dashboard.json)

<img width="2196" height="1079" alt="image" src="https://github.com/user-attachments/assets/7db453e9-1f90-4cf4-a80f-ef48b19d0305" />


## Updating grafana

- Initial version of grafana installed was v11.3
- March 2026 attempted to update to v12.x due to updated plugins
  - Moving users and dashboards needs to be done manually
  - same config file is used 
