#!/bin/bash

# Replace './program' with the actual path to your executable
PROGRAM="./pipex_bonus"

# Get the PID of the program
PID=$(pgrep -f "$PROGRAM")

if [ -z "$PID" ]; then
    echo "Program not running. Please start it first."
    exit 1
fi

while true; do
    echo "Monitoring file descriptors for PID $PID..."

    # Check the number of open file descriptors
    FD_COUNT=$(lsof -p $PID | wc -l)
    echo "Number of open file descriptors: $FD_COUNT"

    # Optionally, list all open file descriptors
    echo "Open file descriptors:"
    lsof -p $PID

    # Sleep for a specified interval before the next check
    sleep 5
done

