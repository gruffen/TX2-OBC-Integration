#!/bin/bash
set pass "raspberry"

sudo raspi-config
expect "password: "
send pass

