#!/bin/bash


# Start DBus session if not already running
if [ -z "$DBUS_SESSION_BUS_ADDRESS" ]; then
    eval "$(dbus-launch --sh-syntax --exit-with-session)"
fi

# Kill any existing PipeWire processes
killall pipewire pipewire-pulse wireplumber 2>/dev/null

# Start WirePlumber first
wireplumber &

# Start PipeWire and Pulse
pipewire &
pipewire-pulse &

# Set it as default sink
pactl set-default-sink alsa_output.usb-C-Media_Electronics_Inc._Addasound_SR_Series-00.analog-stereo



