#include "sortHead.h"

//填充颜色排序的数组
void generateColorNumbers(int* nums, int numsize){
	 srand(time(NULL));
    for (int i = 0; i < numsize; i++) {
        nums[i] = rand()%3; 
    }
}
// 生成测试数据并保存到文件
void generateTestData(int size, int min, int max, const char* filename) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        int num = generateRandomNumber(min, max);
        fprintf(fp, "%d\n", num);
    }

    fclose(fp);
}
// 生成指定范围内的随机数
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// 从文件中读取数据并存储到数组中
void readDataFromFile(const char* filename, int arr[], int* size) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    *size = 0;
    while (fscanf(fp, "%d", &arr[*size]) != EOF) {
        (*size)++;
    }

    fclose(fp);
}
// 获取数组中最大的数字
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// 使用计数排序对数组按照指定位数进行排序
void radixCountSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    // 统计每个数字出现的次数
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // 将count[i]更新为arr中小于等于i的数字的个数
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // 根据count数组将数据放到正确的位置
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // 将排序好的数据复制回原数组
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// 基数计数排序函数
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // 从个位开始，对数组按照位数进行计数排序
    for (int exp = 1; max / exp > 0; exp *= 10) {
        radixCountSort(arr, n, exp);
    }
}

void choiceRadixCountSort(int numbers[],int sortedNumbers[]){
	generateRandomNumbers(numbers, MAX_SIZE);
	printf("\nRadixCounting Sort:\n");
    copyArray(numbers, sortedNumbers, MAX_SIZE);
    double time_taken = calculateTime(radixSort, sortedNumbers, MAX_SIZE);

    printf("Time taken: %f seconds\n", time_taken);
}

void choiceCountSort(int numbers[],int sortedNumbers[]){
	generateRandomNumbers(numbers, MAX_SIZE);
	printf("\nCounting Sort:\n");
    copyArray(numbers, sortedNumbers, MAX_SIZE);
    double time_taken = calculateTime(countSort, sortedNumbers, MAX_SIZE);

    printf("Time taken: %f seconds\n", time_taken);
}

void choiceQuickSort(int numbers[],int sortedNumbers[]){
	generateRandomNumbers(numbers, MAX_SIZE);
	printf("\nQuick Sort:\n");
    copyArray(numbers, sortedNumbers, MAX_SIZE);
    double time_taken = calculateTime2(quickSort, sortedNumbers, MAX_SIZE);
  
    printf("Time taken: %f seconds\n", time_taken);
	
}
void choiceMergeSort(int numbers[],int sortedNumbers[]){
	generateRandomNumbers(numbers, MAX_SIZE);
	printf("\nMerge Sort:\n");
    copyArray(numbers, sortedNumbers, MAX_SIZE);
    double time_taken = calculateTime2(mergeSort, sortedNumbers, MAX_SIZE);

    printf("Time taken: %f seconds\n", time_taken);
}

void choiceInsertSort(int numbers[],int sortedNumbers[]){
	generateRandomNumbers(numbers, MAX_SIZE);
    printf("Insertion Sort:\n");
    copyArray(numbers, sortedNumbers, MAX_SIZE);
    double time_taken = calculateTime(insertSort, sortedNumbers, MAX_SIZE);

    
    printf("Time taken: %f seconds\n", time_taken);
}

void getXSort(int numbers[],int reqSign,int reqX){
	generateRandomNumbers(numbers, X_SIZE);

    quickSort(numbers, 0,X_SIZE-1);
    if(reqSign==1){
    	if(X_SIZE-reqX<0){
    		printf("Range Beyond\n");
    		
		}else{
			printf("the %d big is : %d\n",reqX,numbers[X_SIZE-reqX]);
		}
	}else{
		if(reqX-1>X_SIZE){
    		printf("Range Beyond\n");
    		
		}else{
			printf("the %d small is : %d\n",reqX,numbers[reqX-1]);
		}
	}
    
   
	
}


void menu(){
	printf("**1.request1:many sort\n");
	printf("**2.request2:many big time\n");
	printf("**3.request3:many small time\n");
	printf("**4.request4:io\n");
	printf("**5.request5.1:color sort\n");
	printf("**6.request5.2:get X big/small\n");
	printf("**0.exit\n");
	
}


void sortMenu(){
	printf("**1.insertSort\n");
	printf("**2.mergeSort\n");
	printf("**3.quickSort\n");
	printf("**4.countSort\n");
	printf("**5.RadixCountSort\n");
	printf("**0.exit\n");
}
// 生成随机数填充数组
void generateRandomNumbers(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand()%10000; // 可以根据需要调整生成的随机数范围
    }
}

// 输出数组
void printArray(int arr[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", arr[i-1]);
        if(i%10==0){
        	 printf("\n");
		}
    }
    printf("\n");
}

// 复制数组
void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}
// 计算排序算法的执行时间
double calculateTime2(void (*sortFunction)(int[], int, int), int arr[], int n) {
    clock_t start, end;
    double time_used;

    start = clock();
    sortFunction(arr,0, n);
    end = clock();

    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    return time_used;
}

// 计算排序算法的执行时间
double calculateTime(void (*sortFunction)(int[], int), int arr[], int n) {
    clock_t start, end;
    double time_used;

    start = clock();
    sortFunction(arr, n);
    end = clock();

    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    return time_used;
}

int main() {
    int numbers[MAX_SIZE];
    int sortedNumbers[MAX_SIZE];
    double time_taken;
    int sign=1;
   	int choice=0;
   	
    int dataSize = 100; // 数据大小
    int minValue = 1;  // 最小值
    int maxValue = 100; // 最大值
    const char* filename = "testdata.txt"; // 文件名
    int fileArr[100]; // 数组，假设最多存储100个整数
    int fileSize; 	
    
    
	int colorNums[COLORSORT_SIZE];
    int numsSize = sizeof(colorNums) / sizeof(colorNums[0]);
	generateColorNumbers(colorNums,numsSize)	;
  
    int reqSign;
    int reqX;
    int numsX[X_SIZE];
    
	while(sign!=0) {
		menu();
		printf("please input:");
		scanf("%d",&sign);
		switch(sign){
			case 1:
				
		
				sortMenu();
				printf("please input:");
				scanf("%d",&choice);
				switch(choice){
				 case 1:
				 	choiceInsertSort(numbers,sortedNumbers);
				   	break;
				 case 2:
				 	choiceMergeSort(numbers,sortedNumbers);
				   	break;
				 case 3:
				 	choiceQuickSort(numbers,sortedNumbers);
				   	break;
				 case 4:
				 	choiceCountSort(numbers,sortedNumbers);
				   	break;
				 case 5:
				 	choiceRadixCountSort(numbers,sortedNumbers);
				   	break;
				 case 0:
				   	break;
				
				}

				break;
			case 2:
				
				double time_taken1;
				double time_taken2;
				double time_taken3;
				
				int numbers1[NUMBERS1_SIZE];
				int numbers2[NUMBERS2_SIZE];
				int numbers3[NUMBERS3_SIZE];
				
				int sortedNumbers1[NUMBERS1_SIZE];
				int sortedNumbers2[NUMBERS2_SIZE];
				int sortedNumbers3[NUMBERS3_SIZE];
				
				generateRandomNumbers(numbers1,NUMBERS1_SIZE);
				generateRandomNumbers(numbers2,NUMBERS2_SIZE);
				generateRandomNumbers(numbers3,NUMBERS3_SIZE);
				
				copyArray(numbers1, sortedNumbers1,NUMBERS1_SIZE);
				copyArray(numbers2, sortedNumbers2,NUMBERS2_SIZE);
				copyArray(numbers3, sortedNumbers3,NUMBERS3_SIZE);
				 
				time_taken1 = calculateTime(insertSort, sortedNumbers1, NUMBERS1_SIZE);
				time_taken2 = calculateTime(insertSort, sortedNumbers2,NUMBERS2_SIZE);
				time_taken3 = calculateTime(insertSort, sortedNumbers3, NUMBERS3_SIZE);
			
    			printf("Time taken: %f seconds\n", time_taken1);
				
			
    			printf("Time taken: %f seconds\n", time_taken2);
    			
    		
    			printf("Time taken: %f seconds\n", time_taken3);
				break;
			   
			case 3:
				for(int i = 0; i<FORTIME ;i++){
				double time_taken1;
			
				
				int numbers1[FORSIZE];
			
				
				int sortedNumbers1[FORSIZE];
			
			    generateRandomNumbers(numbers1,FORSIZE);
			    
			    copyArray(numbers1, sortedNumbers1,FORSIZE);
			
				time_taken1 = calculateTime(insertSort, sortedNumbers1, FORSIZE);
				
				printf("Time taken: %f seconds\n", time_taken1);
				}	
				break;
			case 4:
				generateTestData(dataSize, minValue, maxValue, filename);

   				printf("Test data generated and saved to file: %s\n", filename);
   				
    			readDataFromFile(filename, fileArr, &fileSize);

    			printf("Data read from file: \n");
    			printArray(fileArr, fileSize);

    			quickSort(fileArr, 0,fileSize - 1);

   				 printf("Sorted data: \n");
    			printArray(fileArr, fileSize);
				
				break;
				
			case 5:
				 printf("Original array:\n ");
   				 for (int i = 0; i < numsSize; i++) {
       				 printf("%d ", colorNums[i]);
   				}
   				 printf("\n");

   				 sortColors(colorNums, numsSize);
			
    			printf("Sorted array: ");
   				 for (int i = 0; i < numsSize; i++) {
     			   printf("%d ",colorNums[i]);
  				}
				printf("\n");
				break;	
			case 6:
				printf("please input big(1) or small(0)");
				scanf("%d",&reqSign);
				printf("please input X");
				scanf("%d",&reqX);
				getXSort(numsX,reqSign,reqX);
				break;		
			case 0:
				return 0;
				break;		
		}
	} 

    return 0;
}

// 插入排序
void insertSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// 归并排序
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void merge(int arr[], int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = low;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 快速排序
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// 计数排序
void countSort(int arr[], int n) {
    
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

      // 创建计数数组，并初始化为0
    int* count = (int*)malloc((max + 1) * sizeof(int));
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // 计算每个元素的出现次数
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // 将计数数组中的值累加，得到每个元素应该出现的位置
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // 创建临时数组存储排序后的结果
    int* output = (int*)malloc(n * sizeof(int));
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // 将排序后的结果复制回原数组
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // 释放动态分配的内存
    free(count);
    free(output);
}

//颜色排序
void sortColors(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;
    int i = 0;

    while (i <= right) {
        if (nums[i] == 0) {
            // 如果当前元素是0，则将其与左边界交换，并向右移动左边界
            int temp = nums[left];
            nums[left] = nums[i];
            nums[i] = temp;
            left++;
            i++;
        } else if (nums[i] == 2) {
            // 如果当前元素是2，则将其与右边界交换，并向左移动右边界
            int temp = nums[right];
            nums[right] = nums[i];
            nums[i] = temp;
            right--;
        } else {
            // 如果当前元素是1，则直接跳过，继续向后遍历
            i++;
        }
    }
}
