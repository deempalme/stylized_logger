#!/bin/bash

# Defining colors
blue='\e[38;5;51m'
green='\e[38;5;118m'
red='\e[0;91m'
yellow='\e[0;93m'
## Clear all formatting
clear='\e[0;0m'

###
### Print a BLUE colored message in terminal
###
### This does not add a newline character at the end of the message
###
### Arguments:
###     $1  Message to print
###
### Returns:
###     Prints the message in blue
###
### Example:
###     print_blue "Message to print in blue"
###
print_blue(){
    echo -e -n "${blue}$1${clear}"
}

###
### Print a GREEN colored message in terminal
###
### This does not add a newline character at the end of the message
###
### Arguments:
###     $1  Message to print
###
### Returns:
###     Prints the message in green
###
### Example:
###     print_green "Message to print in green"
print_green(){
    echo -e -n "${green}$1${clear}"
}

###
### Print a RED colored message in terminal
###
### This does not add a newline character at the end of the message
###
### Arguments:
###     $1  Message to print
###
### Returns:
###     Prints the message in red
###
### Example:
###     print_red "Message to print in red"
###
print_red(){
    echo -e -n "${red}$1${clear}"
}

###
### Print a YELLOW colored message in terminal
###
### This does not add a newline character at the end of the message
###
### Arguments:
###     $1  Message to print
###
### Returns:
###     Prints the message in red
###
### Example:
###     print_yellow "Message to print in yellow"
###
print_yellow(){
    echo -e -n "${yellow}$1${clear}"
}

###
### Clear all previous formatting
###
### Arguments:
###     None
###
### Returns:
###     Clears all previous formatting
###
clear_format(){
    echo -e -n "$clear"
}

###
### Check if the error code is not 0
###
### If it is not 0, print the error message and exit with the error code
###
### Arguments:
###     $1  Error code
###     $2  Error message
###
### Returns:
###     Exits with the error code (if not 0)
###
### Example:
###     check_error 1 "Error message"
###
check_error(){
    local error_code
    local message
    error_code=$1
    message=$2
    if [[ "$error_code" -ne '0' ]]; then
        date_string=$(date +%Y-%m-%d_%H-%M-%S)
        print_red "[$date_string][ERROR][code: $error_code] $message"
        exit $error_code
    fi
}