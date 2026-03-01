#include <stdio.h>

/* Conversion functions */
float celsius_to_fahrenheit(float celsius) {
    return (9.0f / 5.0f) * celsius + 32.0f;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0f / 9.0f) * (fahrenheit - 32.0f);
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15f;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15f;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

/* Categorization and advisory */
void categorize_temperature(float celsius) {
    printf("\n--- Temperature Category & Advisory ---\n");
    if (celsius < 0.0f) {
        printf("Category : Freezing\n");
        printf("Advisory : Stay indoors and keep warm.\n");
    } else if (celsius < 10.0f) {
        printf("Category : Cold\n");
        printf("Advisory : Wear a jacket.\n");
    } else if (celsius < 25.0f) {
        printf("Category : Comfortable\n");
        printf("Advisory : Enjoy the weather!\n");
    } else if (celsius < 35.0f) {
        printf("Category : Hot\n");
        printf("Advisory : Stay hydrated and wear light clothing.\n");
    } else {
        printf("Category : Extreme Heat\n");
        printf("Advisory : Stay indoors and avoid sun exposure.\n");
    }
}

/* Print scale name */
const char *scale_name(int scale) {
    switch (scale) {
        case 1: return "Fahrenheit";
        case 2: return "Celsius";
        case 3: return "Kelvin";
        default: return "Unknown";
    }
}

int main(void) {
    float temp, converted;
    int from_scale, to_scale;

    printf("=== Temperature Conversion Utility ===\n\n");

    /* Get temperature value */
    while (1) {
        printf("Enter temperature value: ");
        if (scanf("%f", &temp) != 1) {
            printf("Error: Invalid input. Please enter a numeric value.\n");
            while (getchar() != '\n');  /* clear input buffer */
            continue;
        }
        break;
    }

    /* Get input scale */
    printf("\nSelect input scale:\n");
    printf("  1. Fahrenheit\n");
    printf("  2. Celsius\n");
    printf("  3. Kelvin\n");
    while (1) {
        printf("Your choice (1-3): ");
        if (scanf("%d", &from_scale) != 1 || from_scale < 1 || from_scale > 3) {
            printf("Error: Invalid choice. Please enter 1, 2, or 3.\n");
            while (getchar() != '\n');
            continue;
        }
        break;
    }

    /* Validate Kelvin */
    if (from_scale == 3 && temp < 0.0f) {
        printf("Error: Kelvin cannot be negative (absolute zero is 0 K).\n");
        return 1;
    }

    /* Get target scale */
    printf("\nSelect target scale:\n");
    printf("  1. Fahrenheit\n");
    printf("  2. Celsius\n");
    printf("  3. Kelvin\n");
    while (1) {
        printf("Your choice (1-3): ");
        if (scanf("%d", &to_scale) != 1 || to_scale < 1 || to_scale > 3) {
            printf("Error: Invalid choice. Please enter 1, 2, or 3.\n");
            while (getchar() != '\n');
            continue;
        }
        break;
    }

    /* Same scale check */
    if (from_scale == to_scale) {
        printf("Error: Input and target scales are the same (%s). Please choose a different target.\n",
               scale_name(from_scale));
        return 1;
    }

    /* Perform conversion */
    if (from_scale == 1 && to_scale == 2){
        converted = fahrenheit_to_celsius(temp);
    }
    else if (from_scale == 1 && to_scale == 3){
        converted = fahrenheit_to_kelvin(temp);
    }
    else if (from_scale == 2 && to_scale == 1){
        converted = celsius_to_fahrenheit(temp);
    }
    else if (from_scale == 2 && to_scale == 3){
        converted = celsius_to_kelvin(temp);
    }
    else if (from_scale == 3 && to_scale == 1){
        converted = kelvin_to_fahrenheit(temp);
    }
    else{
        converted = kelvin_to_celsius(temp);
    }
    /* Display result */
    printf("\n--- Conversion Result ---\n");
    printf("%.2f %s = %.2f %s\n", temp, scale_name(from_scale), converted, scale_name(to_scale));

    /* Convert result to Celsius for categorization */
    float celsius_val;
    if (to_scale == 2){
        celsius_val = converted;
    }      
    else if (to_scale == 1) {
        celsius_val = fahrenheit_to_celsius(converted);
    }
    else {
        celsius_val = kelvin_to_celsius(converted);
    }

    categorize_temperature(celsius_val);

    return 0;
}