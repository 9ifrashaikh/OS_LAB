#!/bin/bash

# Function for Factorial without recursion
factorial_non_recursive() {
  factorial=1
  echo -n "Enter a number: "
  read num
  for (( i=1; i<=num; i++ )); do
    factorial=$((factorial * i))
  done
  echo "Factorial of $num is $factorial"
}

# Function for Factorial with recursion
factorial_recursive() {
  factorial() {
    if [ "$1" -le 1 ]; then
      echo 1
    else
      echo $(( $1 * $(factorial $(( $1 - 1 ))) ))
    fi
  }
  
  echo -n "Enter a number: "
  read num
  result=$(factorial "$num")
  echo "Factorial of $num is $result"
}

# Function to check palindrome
check_palindrome() {
  echo -n "Enter a string or number: "
  read input
  reverse=$(echo "$input" | rev)
  if [ "$input" == "$reverse" ]; then
    echo "$input is a palindrome"
  else
    echo "$input is not a palindrome"
  fi
}

# Function for Bubble Sort
bubble_sort() {
  echo -n "Enter numbers separated by space: "
  read -a arr
  n=${#arr[@]}
  for (( i = 0; i < n; i++ )); do
    for (( j = 0; j < n-i-1; j++ )); do
      if (( arr[j] > arr[j+1] )); then
        temp=${arr[j]}
        arr[j]=${arr[j+1]}
        arr[j+1]=$temp
      fi
    done
  done
  echo "Sorted array: ${arr[*]}"
}

# Function to count occurrences of a substring
count_occurrences() {
  echo -n "Enter a string: "
  read str
  echo -n "Enter a substring to count: "
  read substr
  count=$(echo "$str" | grep -o "$substr" | wc -l)
  echo "The substring '$substr' occurs $count times in the string."
}

# Function to calculate the sum of digits
sum_of_digits() {
  echo -n "Enter a number: "
  read num
  sum=0
  while [ "$num" -gt 0 ]; do
    digit=$(( num % 10 ))
    sum=$(( sum + digit ))
    num=$(( num / 10 ))
  done
  echo "Sum of digits is $sum"
}

# Function to reverse digits
reverse_digits() {
  echo -n "Enter a number: "
  read num
  reverse=0
  while [ "$num" -gt 0 ]; do
    digit=$(( num % 10 ))
    reverse=$(( reverse * 10 + digit ))
    num=$(( num / 10 ))
  done
  echo "Reversed number is $reverse"
}

# Function to check Armstrong number
check_armstrong() {
  echo -n "Enter a number: "
  read num
  temp=$num
  sum=0
  while [ "$temp" -gt 0 ]; do
    digit=$(( temp % 10 ))
    sum=$(( sum + digit * digit * digit ))
    temp=$(( temp / 10 ))
  done
  if [ "$sum" -eq "$num" ]; then
    echo "$num is an Armstrong number"
  else
    echo "$num is not an Armstrong number"
  fi
}

# Main menu loop
while true; do
  echo "------------------ MENU ------------------"
  echo "1. Factorial (Non-Recursive)"
  echo "2. Factorial (Recursive)"
  echo "3. Check Palindrome"
  echo "4. Bubble Sort"
  echo "5. Count Occurrences of Substring"
  echo "6. Sum of Digits"
  echo "7. Reverse Digits"
  echo "8. Check Armstrong Number"
  echo "9. Exit"
  echo "------------------------------------------"
  echo -n "Enter your choice: "
  read choice
  
  case $choice in
    1) factorial_non_recursive ;;
    2) factorial_recursive ;;
    3) check_palindrome ;;
    4) bubble_sort ;;
    5) count_occurrences ;;
    6) sum_of_digits ;;
    7) reverse_digits ;;
    8) check_armstrong ;;
    9) echo "Exiting..."; exit 0 ;;
    *) echo "Invalid option. Please try again." ;;
  esac
  echo ""
done
