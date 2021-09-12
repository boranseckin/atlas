#!/bin/bash

BOOTMNT=/Volumes/boot

echo "Building the kernel image..."
docker run --rm -v $(pwd):/app -w /app smatyukevich/raspberry-pi-os-builder make $1
echo "Deploying into $BOOTMNT..."
cp kernel8.img $BOOTMNT/
cp config.txt $BOOTMNT/
sync
diskutil unmount /Volumes/boot
echo "Done."
