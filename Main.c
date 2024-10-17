#include <stdio.h>

// Function to count maximum possible odd numbers in prefix sum array
int count_max_odd_prefixes(int num_elements, int array[]) {
    int odd_num_count = 0;  // Count of odd numbers in input
    int even_num_count = 0; // Count of even numbers in input
    
    // Count odd and even numbers in input array
    for(int i = 0; i < num_elements; i++) {
        if(array[i] % 2 == 0) even_num_count++;
        else odd_num_count++;
    }
    
    // Initialize result to store maximum possible odd numbers in prefix sum
    int max_odd_prefix_count = 0;
    
    // If first number is odd, prefix sum starts odd
    // If first number is even, prefix sum starts even
    int current_sum_parity = 0; // 0 for even, 1 for odd
    
    // We should place numbers to maximize odd prefix sums
    // For each position, we can choose either odd or even number
    // to make current sum odd or even
    for(int i = 0; i < num_elements; i++) {
        // If we want odd sum and have odd numbers available
        if(current_sum_parity == 0 && odd_num_count > 0) {
            odd_num_count--;
            current_sum_parity = 1;
            max_odd_prefix_count++;
        }
        // If we want odd sum and only have even numbers
        else if(current_sum_parity == 0 && even_num_count > 0) {
            even_num_count--;
            current_sum_parity = 0;
        }
        // If we want even sum and have even numbers
        else if(current_sum_parity == 1 && even_num_count > 0) {
            even_num_count--;
            current_sum_parity = 1;
            max_odd_prefix_count++;
        }
        // If we want even sum and only have odd numbers
        else if(current_sum_parity == 1 && odd_num_count > 0) {
            odd_num_count--;
            current_sum_parity = 0;
        }
    }
    
    return max_odd_prefix_count;
}

int main() {
    int num_test_cases;
    scanf("%d", &num_test_cases);
    
    while(num_test_cases--) {
        int num_elements;
        scanf("%d", &num_elements);
        
        int input_array[100];  // Since constraints say N ≤ 100
        for(int i = 0; i < num_elements; i++) {
            scanf("%d", &input_array[i]);
        }
        
        printf("%d\n", count_max_odd_prefixes(num_elements, input_array));
    }
    
    return 0;
}
