#!/bin/bash

factorial_if_else(){
    echo -n "enter a number"
    read num
    fact=1
    if [$num -lt 0];
    then
    echo "factorial not exist for negative integers"
    elif [$num -eq 0];
    then
    echo " factorial of 0 is 1"
    else 
    for((i=0;i<=num;i++))
    do
    fact=$((fact*i))
    done
    echo "factorial of $num is $fact"
    fi

}

prime_while() {
    echo -n "Enter a number: "
    read num
    if [ $num -le 1 ]; then
        echo "$num is not a prime number."
        return
    fi

    i=2
    while [ $i -le $(($num / 2)) ]
    do
        if [ $(($num % i)) -eq 0 ]; then
            echo "$num is not a prime number."
            return
        fi
        i=$(($i + 1))
    done
    echo "$num is a prime number."
}


sum_for() {
    echo -n "Enter the limit: "
    read limit
    sum=0
    for ((i=1; i<=limit; i++))
    do
        sum=$((sum + i))
    done
    echo "Sum of numbers from 1 to $limit is $sum."
}


countdown_until() {
    echo -n "Enter a number: "
    read num
    until [ $num -lt 1 ]
    do
        echo "$num"
        num=$((num - 1))
    done
    echo "Countdown finished!"
}


show_menu() {
    echo "1) Factorial (using if-else)"
    echo "2) Prime Check (using while loop)"
    echo "3) Sum of Numbers (using for loop)"
    echo "4) Countdown (using until loop)"
    echo "5) Exit"
    echo -n "Enter your choice: "
    read choice
}

while true
do
    show_menu
    case $choice in
        1) factorial_if_else ;;
        2) prime_while ;;
        3) sum_for ;;
        4) countdown_until ;;
        5) exit ;;
        *) echo "Invalid choice! Please try again." ;;
    esac
    echo