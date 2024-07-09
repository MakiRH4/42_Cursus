#!/bin/bash

BACKUP_DIR=~/Documents/GitHub/42_Cursus/config_backup

# xrandr settings
xrandr --verbose > $BACKUP_DIR/xrandr_backup.sh
chmod +x $BACKUP_DIR/xrandr_backup.sh

# GTK settings
cp ~/.config/gtk-3.0/settings.ini $BACKUP_DIR/gtk-3.0-settings.ini
cp ~/.config/gtk-4.0/settings.ini $BACKUP_DIR/gtk-4.0-settings.ini

# Fonts configuration
cp ~/.config/fontconfig/fonts.conf $BACKUP_DIR/fonts.conf

# GNOME Terminal settings
dconf dump /org/gnome/terminal/ > $BACKUP_DIR/gnome-terminal.dconf

# GNOME desktop settings
dconf dump /org/gnome/ > $BACKUP_DIR/gnome.dconf

echo "Backup completed successfully."

