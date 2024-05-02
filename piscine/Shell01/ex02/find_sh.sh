#!/bin/sh

find ./ -name "*.sh" -exec basename --suffix=.sh {} \;
