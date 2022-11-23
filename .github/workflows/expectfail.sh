#!/bin/bash

if $1; then
    echo "POSITIVE!"
else
    echo "FAILED!"
    exit 1
fi
