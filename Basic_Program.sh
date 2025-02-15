:'
    Name : Antuley Aman Siraj
    Roll No : 23CO25
    Batch : 01
    
    
    Tasks :-
    1) Display OS version, Release Number, Kernel version
    2) Display Top 10 processes in descending order
    3) Display processes with highest memory usage
    4) Display current logged in user and log name
    5) Display current shell, home directory, operating system type, current path setting, current working directory
'

#!/bin/sh
choice=""
exit="0"
echo ""
while [ "$choice" != "$exit" ]; 
do
    echo "1 : Display OS version, Release Number, Kernel version\n"
    echo "2 : Display Top 10 processes in descending order\n"
    echo "3 : Display processes with highest memory usage\n"
    echo "4 : Display current logged in user and log name."
    echo "5 : Display current shell, home directory, operating system type, current path setting, current working directory"
    echo "Enter your choice (0 to exit):"
    read choice
    case "$choice" in
        1)
            echo "OS version :"
            uname
            echo "Release Number :"
            uname -r
            echo "Kernel Version :"
            uname -v
            ;;
        2)
            echo "Top 10 processes in descneding order :"
            ps axl --sort=-%mem | head -n 10
            ;;
        3)
            echo "Processes with highest memory usage :"
            ps -eo pid,ppid,cmd,%mem,%cpu --sort=-%mem | head
            ;;
        4)
            echo "Current logged in User :"
            who -u
            echo "Number of logged in User :"
            who -u | wc -l
            ;;
        5)
            echo "Current Shell :"
            echo "$SHELL"
            echo "Home directory :"
            echo "$HOME"
            echo "Operating System Type :"
            uname
            echo "Current Path Setting :"
            echo "$PATH"
            echo "Current working directory"
            pwd
            ;;
        0)
            echo "Exiting..."
            ;;
        *)
            echo "Invalid choice"
            ;;

    esac
done
    
