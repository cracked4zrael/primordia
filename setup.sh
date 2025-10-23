#!/usr/bin/env bash

set -e

# Update system
echo "Updating system..."
sudo apt update && sudo apt upgrade -y

# -------------------------------
# Core Sway Packages
# -------------------------------
CORE_PACKAGES=(
    sway
    xwayland
    gtklock
    build-essential
    waybar
)

echo "Installing core packages..."
sudo apt install -y "${CORE_PACKAGES[@]}"

# -------------------------------
# Sway Utilities & Tools
# -------------------------------
SWAY_UTILS=(
    swayidle
    swaylock
    wl-clipboard
    grim
    slurp
    swappy
    alacritty
    xdg-desktop-portal-wlr
    autotiling
    sway-notification-center
    nwg-look
    thunar
    thunar-archive-plugin
    thunar-volman
    gvfs-backends
    unzip
    pavucontrol
    pulsemixer
    pamixer
    pipewire-audio
    nwg-displays
    eog
    wlr-randr
    wofi
    foot
    gawk
    cmake
    curl
    meson
    ninja-build
    pkg-config
    g++
    rustc
    cargo
    mingw-w64
    git
    feh
)

FONTS=(
    fonts-jetbrains-mono
    fonts-noto-color-emoji
    fonts-font-awesome
    fonts-firacode
    fonts-hack
    fonts-nerd-fonts
    papirus-icon-theme
)

echo "Installing Sway utilities and fonts..."
sudo apt install -y "${SWAY_UTILS[@]}" "${FONTS[@]}"

# -------------------------------
# Media Players
# -------------------------------
MEDIA_PLAYERS=(
    mpv
    celluloid
)

echo "Installing media players..."
sudo apt install -y "${MEDIA_PLAYERS[@]}"

# -------------------------------
# User Applications
# -------------------------------
USER_APPS=(
    brave-browser
    obsidian
    neovim
)

VIRTUALIZATION=(
    qemu-kvm
    libvirt-daemon-system
    libvirt-clients
    bridge-utils
    virt-manager
)

echo "Installing user applications..."
sudo apt install -y "${USER_APPS[@]}" "${VIRTUALIZATION[@]}"

# -------------------------------
# KVM / Virtualization Setup
# -------------------------------
echo "Configuring KVM permissions..."
sudo usermod -aG libvirt $USER
sudo usermod -aG kvm $USER
sudo systemctl enable --now libvirtd

# -------------------------------
# Done
# -------------------------------
echo "Installation complete!"
echo "Log out and back in for KVM group changes to take effect."

