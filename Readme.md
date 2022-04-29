# Sorting Algorithms

This project includes various types of arrays and algorithms that sort them.

## Project description

The main goal of the project is to check the efficiency of a sorting algorithms, by mesuring time of execution.

### This project contains various types of arrays such as:

1. Random array - contains random numbers in random order
2. Increasing array - contains increasing numbers, so this array is already sorted, but that does not mean that all algorithms
3. Decreasing array - contains decreasing numbers, this is the worst case, because alborithms has to do maximum amount of steps to sort this array
4. Constant array - contains elements of the same value
5. V-shape array - half of the array contains decreasing numbers, second half contains increasing numbers

### Implemented algorithms are:

1. Insertion sort - simple sorting algorithm that builds the final sorted array one item at a time
2. Selection sort - sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning
3. Heap sort - comparison-based sorting technique based on Binary Heap data structure
4. Merge sort - *Divide and Conquer* algorithm. It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves

I am aware that I could do this time measurement more pretty but i did it for university project and we were only interested in results so I'm leaving it like this for now.

## How to Install and Run the project

You can just download .zip from github, unpack it and run the .exe file.

### For programmers
I am using DEV C++ IDE for C++ development. In that case you should download contents of this repo and open the .dev file. After that you can hit the run button and it all should work properly. 
In case you are using other compiler you can create your own project and then copy contents of .cpp file.

## How to use Project

I think I made the application very self-descriptive. After you run the project you will be asked to choose which array and algorithm you want to use and also how long do you want your array to be. After that the algorithm will be executed and the time will be measured. At the end programme will ask you if you want to exit. If no whole process will be repeated untill you want to exit the application.
