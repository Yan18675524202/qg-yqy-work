#ifndef __SORTHEAD_H__
#define __SORTHEAD_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLORSORT_SIZE 100

#define MAX_SIZE 1000

#define NUMBERS1_SIZE 10000
#define NUMBERS2_SIZE 50000
#define NUMBERS3_SIZE 200000

#define FORTIME 100
#define FORSIZE 100

#define X_SIZE 100


// 函数声明
void generateRandomNumbers(int arr[], int n);
void insertSort(int arr[], int n);
void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void countSort(int arr[], int n);
void radixCountSort(int arr[], int n);
void menu();
void sortMenu();
int getMax(int arr[], int n);
void radixSort(int arr[], int n);
void copyArray(int src[], int dest[], int n);
double calculateTime(void (*sortFunction)(int[], int), int arr[], int n);
double calculateTime2(void (*sortFunction)(int[], int, int), int arr[], int n);
void choiceMergeSort(int numbers[],int sortedNumbers[]);
void printArray(int arr[], int n); 
void choiceQuickSort(int numbers[],int sortedNumbers[]);
void choiceCountSort(int numbers[],int sortedNumbers[]);
void choiceRadixCountSort(int numbers[],int sortedNumbers[]);
void readDataFromFile(const char* filename, int arr[], int* size);
void generateTestData(int size, int min, int max, const char* filename);
int generateRandomNumber(int min, int max);
void sortColors(int* nums, int numsSize);
void generateColorNumbers(int* nums ,int numsize);
void getXSort(int numbers[],int reqSign,int reqX);
#endif