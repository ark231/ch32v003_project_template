#!/usr/bin/bash

while read line
do
    echo $line | nc -u -w0 127.0.0.1 47269
done
