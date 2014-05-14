#!/bin/bash

host=$1
port=$2

nc -z ${host} ${port}
err=$?
if [[ $err -eq 1 ]]; then
	notify-send "Daemon Down!" "Daemon at ${host}:${port} is not reachable"
fi

exit $err
