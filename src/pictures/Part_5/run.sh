#!/bin/bash

gcc miniserver.c -lfcgi -o myserver
./myserver &
nginx -g "daemon off;"
# myserver nginx start
# nginx -s reload

# /bin/bash
