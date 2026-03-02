#!/bin/bash

# Defining colors
blue="\e[38;5;51m"
green="\e[38;5;118m"
red="\e[0;91m"
yellow="\e[0;93m"
## Clear all formatting
clear="\e[0m"

###
### Print a GREEN colored message in terminal
###
### This does not add a newline character at the end of the message
###
### Arguments:
###     None
###
print_done(){
    echo -e -n "${green}+++ Done!!!${clear}\n\n"
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
        date_string=$(date "+%Y-%m-%d %H:%M:%S %Z")
        print_red "[$date_string][ERROR][code: $error_code] $message\n"
        exit $error_code
    fi
    print_done
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
### Get the number of jobs to use based on the percentage of the available cores
###
### Arguments:
###     $1  Percentage of the available cores to use
###
### Returns:
###     The number of jobs to use (minimum 1, maximum the number of available cores)
###
### Example:
###     get_jobs 70 # Use 70% of the available cores
###     get_jobs 100 # Use all available cores
###     get_jobs # Use all available cores (default)
###
get_jobs(){
    local jobs
    local max_jobs
    local percentage
    percentage=$1
    if [[ -z "$percentage" ]]; then
        # Default percentage is 100 (use all available cores)
        percentage=100
    fi
    max_jobs=$(nproc)
    jobs=$((max_jobs * percentage / 100))
    if [[ "$jobs" -eq 0 ]]; then
        # Minimum number of jobs is 1
        jobs=1
    elif [[ "$jobs" -gt "$max_jobs" ]]; then
        # Maximum number of jobs is the number of available cores
        jobs=$max_jobs
    fi
    echo "$jobs"
}

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