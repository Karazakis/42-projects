#!/bin/bash
if [ ! -d "/${USER}/data" ]; then
        mkdir ~/data
        mkdir ~/data/mariadb-data
        mkdir ~/data/wordpress
        mkdir ~/data/prt
fi